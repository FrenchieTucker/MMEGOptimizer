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
#include "extractionProcess.h"
#include "Creature.h"
#include "Rune.h"
#include "global.h"

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include <QtCore/QString>

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonValue>

#include <iostream>

MMEGOptimizer_ctrl::MMEGOptimizer_ctrl()
    : m_wdg(new MMEGOptimizer_wdg)
{
    QObject::connect(m_wdg.get(), &MMEGOptimizer_wdg::importDemande, [this](){importerFichier();});
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
        fillModels(content);
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

void MMEGOptimizer_ctrl::fillModels(QString content)
{
    QJsonDocument main{QJsonDocument::fromJson(content.toUtf8())};
    if(!main.isObject()) {
        std::cerr << "Erreur de lecture du fichier" << std::endl;
        return;
    }

    QJsonObject o = main.object();
    for(QString key : o.keys()) {
        //std::cout << "value=" << key.toUtf8().constData() << std::endl;
        if(key == "creatures") {
            fillCreatures(o.value(key));
        } else if(key == "guild") {
            fillGuild(o.value(key));
        } else if(key == "profile") {
            fillProfile(o.value(key));
        } else if(key == "runes") {
            fillRunes(o.value(key));
        } else if(key == "version") {
            fillVersion(o.value(key));
        } else {
            std::cerr << "la cle " << key.toUtf8().constData() << " est inconnue." << std::endl;
        }
    }
}

void MMEGOptimizer_ctrl::fillCreatures(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        fillCreature(v);
    }
}

void MMEGOptimizer_ctrl::fillCreature(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    try{
        m_creatures.append(new Creature(val));
    }
    catch(QString key) {
        std::cerr << "clé inconnue : " << key.toUtf8().constData() << std::endl;
    }
    catch(...) {
        std::cerr << "erreur inconnue" << std::endl;
    }
}

void MMEGOptimizer_ctrl::fillGuild(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    m_guild.update(val);
}

void MMEGOptimizer_ctrl::fillProfile(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    m_profile.update(val);
}

void MMEGOptimizer_ctrl::fillRunes(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        fillRune(v);
    }
}

void MMEGOptimizer_ctrl::fillRune(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    try{
        m_runes.append(new Rune(val));
    }
    catch(QString key) {
        std::cerr << "clé inconnue : " << key.toUtf8().constData() << std::endl;
    }
    catch(...) {
        std::cerr << "erreur inconnue" << std::endl;
    }
}

void MMEGOptimizer_ctrl::fillVersion(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_version = static_cast<unsigned int>(val.toInt(0));
}
