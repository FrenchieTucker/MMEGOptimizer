/*
This program helps the user to optimize a glyph's build for an
invocation in the game : Might&Magic : Elemental Guardians
Copyright (C) 2019  Florian LEMEASLE

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "MMEGOptimizer_ctrl.h"

#include "global.h"
#include "extractionProcess.h"

#include "Creature.h"
#include "Rune.h"
#include "AuraSkillUp.h"
#include "AuraBase.h"
#include "ProcRuneParSubStat.h"
#include "HeroicStat.h"
#include "CreatureBaseStat.h"
#include "PuissanceGlypheParNiveau.h"

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include <QtCore/QFile>

#include <QtCore/QString>

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonValue>

#include <iostream>

bool operator<(const CreatureId& ci1, const CreatureId& ci2) {
    return ci1.id < ci2.id;
}

MMEGOptimizer_ctrl::MMEGOptimizer_ctrl()
    : m_wdg(new MMEGOptimizer_wdg)
{
    initialiserDonneesStatiques();

    QObject::connect(m_wdg.get(), &MMEGOptimizer_wdg::importDemande, [this](){importerFichier();});
}

void MMEGOptimizer_ctrl::initialiserDonneesStatiques()
{
    recupererDonneesApportSetGlyphes();
    recupererDonneesAugmentationAura();
    recupererDonneesCreaturesNomParId();
    recupererDonneesDefinitionAura();
    recupererDonneesElementTraduction();
    recupererDonneesLibelleAura();
    recupererDonneesProcGlypheParSubstat();
    recupererDonneesStatHeroiques();
    recupererDonneesStatsCreaturesBases();
    recupererDonneesStatsGlyphesParNiveau();
}

QByteArray getDataFromJsonFile(QString fileName)
{
    QFile file(fileName);
    if(!file.exists()) {
        std::cerr << "le fichier " << fileName.toUtf8().constData() << " n'existe pas" << std::endl;
        return QByteArray();
    }
    if(!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Impossible d'ouvrir le fichier " << fileName.toUtf8().constData() << std::endl;
        return QByteArray();
    }

    return file.readAll();
}

void MMEGOptimizer_ctrl::recupererDonneesApportSetGlyphes()
{
    auto data = getDataFromJsonFile("res/apportSetGlyphes.json");
    QJsonDocument main{QJsonDocument::fromJson(data)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier apportSetGlyphes.json" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        QJsonValue val = o.value(key);
        if(!val.isArray()) {
            std::cerr << "Erreur sur la cle '" << key.toUtf8().constData() << "'" << std::endl;
            continue;
        }
        QJsonArray apports = val.toArray();

        QJsonValue firstAttr = apports.first();
        if(!firstAttr.isString()) {
            std::cerr << "Erreur sur le 1er element de la cle '" << key.toUtf8().constData() << "'" << std::endl;
            continue;
        }
        QString attr = firstAttr.toString();
        if(attr.isEmpty()) {
            m_apportSetGlyphes.insert(key, qMakePair(QString(), 0.));
            continue;
        }

        QJsonValue lastAttr = apports.last();
        if(!lastAttr.isDouble()) {
            std::cerr << "Erreur sur le 2eme element de la cle '" << key.toUtf8().constData() << "'" << std::endl;
            continue;
        }
        m_apportSetGlyphes.insert(key, qMakePair(attr, lastAttr.toDouble()));
    }
}

void MMEGOptimizer_ctrl::recupererDonneesAugmentationAura()
{
    auto data = getDataFromJsonFile("res/augmentationAura.json");
    QJsonDocument main{QJsonDocument::fromJson(data)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier augmentationAura.json" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            bool ok;
            uint value = key.right(4).toUInt(&ok);
            m_augmentationAura.insert(ok? value: (!m_augmentationAura.isEmpty()? m_augmentationAura.lastKey()+1: 0), new AuraSkillUp(o.value(key)));
        } catch (QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesCreaturesNomParId()
{
    auto data = getDataFromJsonFile("res/creaturesNomParId.en.json");
    QJsonDocument main{QJsonDocument::fromJson(data)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier creaturesNomParId.en.json" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        QJsonValue val = o.value(key);
        if(!val.isString()) {
            std::cerr << "Erreur sur la valeur associée à l'attribut '" << key.toUtf8().constData() << "'" << std::endl;
            continue;
        }
        bool ok;
        uint value = key.section('_', 3).toUInt(&ok);
        m_nomparId.insert(ok? value: (!m_nomparId.isEmpty()? m_nomparId.lastKey()+1: 1), val.toString());
    }
}

void MMEGOptimizer_ctrl::recupererDonneesDefinitionAura()
{
    QByteArray data = getDataFromJsonFile("res/definitionAura.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier definitionAura.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            bool ok;
            uint value = key.section('_', 1).toUInt(&ok);
            m_auraBases.insert(ok? value: (!m_auraBases.isEmpty()? m_auraBases.lastKey()+1: 0), new AuraBase(o.value(key)));
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesElementTraduction()
{
    auto data = getDataFromJsonFile("res/elementTraduction.fr.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier elementTraduction.fr.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            QJsonValue val = o.value(key);
            if(!val.isString()) {
                std::cerr << "la valeur associee a la cle '" << key.toUtf8().constData() << "' n'est pas une chaine de caracteres";
                continue;
            }
            m_elementsTraduits.insert(key, val.toString());
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesLibelleAura()
{
    auto data = getDataFromJsonFile("res/libelleAura.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier libelleAura.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            QJsonValue val = o.value(key);
            if(!val.isString()) {
                std::cerr << "la valeur associee a la cle '" << key.toUtf8().constData() << "' n'est pas une chaine de caracteres";
                continue;
            }
            bool ok;
            uint value = key.section('_', 3).toUInt(&ok);
            if(!ok)
                std::cerr << "Erreur de conversion pour la clé = [" << key.toUtf8().constData() << "]" << std::endl;
            m_libellesAura.insert(ok? value: (!m_auraBases.isEmpty()? m_auraBases.lastKey()+1: 0), val.toString());
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesProcGlypheParSubstat()
{
    auto data = getDataFromJsonFile("res/procGlypheParSubstat.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier procGlypheParSubstat.json ["
                  << err.errorString().toUtf8().constData() << "] "
                  << "shift = [" << err.offset << "] "
                  << " - [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            m_procRuneParSubStat.insert(key, new ProcRuneParSubStat(o.value(key)));
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesStatHeroiques()
{
    auto data = getDataFromJsonFile("res/statHeroiques.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier statHeroiques.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            bool ok;
            uint value = key.section('_', 2).toUInt(&ok);
            m_heroicStat.insert(ok? value: (!m_heroicStat.isEmpty()? m_heroicStat.lastKey()+1: 0), new HeroicStat(o.value(key)));
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesStatsCreaturesBases()
{
    auto data = getDataFromJsonFile("res/statsCreaturesBases.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier statsCreaturesBases.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            if(key == "TID_ANDROID_CREATURE earth") {
                m_creatureBaseStat.insert({ANDROID_ID, Element::Earth}, new CreatureBaseStat(o.value(key)));
                continue;
            }
            else if(key == "TID_SIRI_CREATURE fire") {
                m_creatureBaseStat.insert({SIRI_ID, Element::Fire}, new CreatureBaseStat(o.value(key)));
                continue;
            }
            CreatureId ci;
            QStringList infos = key.split(" ");
            bool ok;
            uint value = infos.at(0).section('_', 3).toUInt(&ok);
            ci.id = ok? value: (!m_creatureBaseStat.isEmpty()? m_creatureBaseStat.lastKey().id+1: 0);
            ci.el = convertElement(infos.at(1));
            m_creatureBaseStat.insert(ci, new CreatureBaseStat(o.value(key)));
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::recupererDonneesStatsGlyphesParNiveau()
{
    auto data = getDataFromJsonFile("res/statsGlyphesParNiveau.json");
    QJsonParseError err;
    QJsonDocument main{QJsonDocument::fromJson(data, &err)};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier statsGlyphesParNiveau.json ["
                  << err.errorString().toUtf8().constData()
                  << "] [-31,32]=[" << data.mid(err.offset -31, 64).constData() << "]" << std::endl;
        return;
    }
    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        try {
            m_glyphesParNiveau.insert(key, new PuissanceGlypheParNiveau(o.value(key)));
        }
        catch(QString msg) {
            std::cerr << "<cle=" << key.toUtf8().constData() << "> " << msg.toUtf8().constData() << std::endl;
        }
    }
}


void MMEGOptimizer_ctrl::show()
{
    m_wdg->show();
}

void MMEGOptimizer_ctrl::importerFichier()
{
    //std::cout << "MMEGOptimizer_ctrl::importerFichier" << std::endl;
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    QObject::tr("Open File"),
                                                    QString(),
                                                    QObject::tr("Archive (*.gz)"));
    if(fileName.isEmpty())
        return;

    std::cout << "fichier a importer : " << fileName.toUtf8().constData() << std::endl;

    try{
        QString content = extractInfos(fileName);
        extractModels(content);
        QMessageBox::information(nullptr, "Import", "Import fini.", QMessageBox::Ok);
    }
    catch(...) {
        QMessageBox::warning(nullptr,
                             "7zip",
                             "Le programme 7zip n'est pas installé. "
                             "Il est nécessaire au bon fonctionnement du logiciel. "
                             "Téléchargez-le <a href=\"https://www.7-zip.org/download.html\">ici</a>");
    }
}

void MMEGOptimizer_ctrl::extractModels(QString content)
{
    QJsonDocument main{QJsonDocument::fromJson(content.toUtf8())};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier" << std::endl;
        return;
    }

    QJsonObject o = main.object();
    try {
        for(QString key : o.keys()) {
            if(key == "creatures") {
                extractCreatures(o.value(key));
            } else if(key == "guild") {
                extractGuild(o.value(key));
            } else if(key == "profile") {
                extractProfile(o.value(key));
            } else if(key == "runes") {
                extractRunes(o.value(key));
            } else if(key == "version") {
                extractVersion(o.value(key));
            } else {
                std::cerr << "la cle " << key.toUtf8().constData() << " est inconnue." << std::endl;
            }
        }
    }
    catch(...) {
        return;
    }

    validateData();
}

void MMEGOptimizer_ctrl::extractCreatures(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    if(!m_creatures.isEmpty()) {
        qDeleteAll(m_creatures);
        m_creatures.clear();
    }
    for(QJsonValue v : val.toArray()) {
        extractCreature(v);
    }
}

void MMEGOptimizer_ctrl::extractCreature(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    try{
        m_creatures.append(new Creature(val));
    }
    catch(QString key) {
        std::cerr << "cle inconnue : " << key.toUtf8().constData() << std::endl;
        throw;
    }
    catch(...) {
        std::cerr << "erreur inconnue" << std::endl;
        throw;
    }
}

void MMEGOptimizer_ctrl::extractGuild(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    m_guild.update(val);
}

void MMEGOptimizer_ctrl::extractProfile(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    m_profile.update(val);
}

void MMEGOptimizer_ctrl::extractRunes(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    if(!m_runes.isEmpty()) {
        qDeleteAll(m_runes);
        m_runes.clear();
    }
    for(QJsonValue v : val.toArray()) {
        extractRune(v);
    }
}

void MMEGOptimizer_ctrl::extractRune(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    try{
        m_runes.append(new Rune(val));
    }
    catch(QString key) {
        std::cerr << "cle inconnue : " << key.toUtf8().constData() << std::endl;
        throw;
    }
    catch(...) {
        std::cerr << "erreur inconnue" << std::endl;
        throw;
    }
}

void MMEGOptimizer_ctrl::extractVersion(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_version = val.toString();
}

void MMEGOptimizer_ctrl::validateData()
{
    m_wdg->fillCreatures(m_creatures);
    m_wdg->fillRunes(m_runes);
    m_wdg->fillGuild(m_guild);
    m_wdg->fillProfile(m_profile);
    m_wdg->fillVersion(m_version);
}
