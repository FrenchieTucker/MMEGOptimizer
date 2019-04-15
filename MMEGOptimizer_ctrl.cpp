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

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include <QtCore/QString>
#include <QtCore/QProcess>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

#include <iostream>

MMEGOptimizer_ctrl::MMEGOptimizer_ctrl()
    : m_infosMdl()
    , m_wdg(new MMEGOptimizer_wdg(m_infosMdl))
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
    //std::cout << "fillModels [" << content.size() << "]" << std::endl;
    QJsonDocument main{QJsonDocument::fromJson(content.toUtf8())};
    if(main.isNull())
        std::cout << "Document null" << std::endl;
    if(main.isArray())
        std::cout << "Document array" << std::endl;
    if(main.isEmpty())
        std::cout << "Document empty" << std::endl;
    if(main.isObject())
        std::cout << "Document object" << std::endl;

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
    std::cout << __FUNCTION__ << " - BEGIN" << std::endl;
    if(!val.isArray()) {
        std::cerr << __FUNCTION__ << ": not an array" << std::endl;
        return;
    }
}

void MMEGOptimizer_ctrl::fillGuild(QJsonValue val)
{
    std::cout << __FUNCTION__ << " - BEGIN" << std::endl;
    if(!val.isObject()) {
        std::cerr << __FUNCTION__ << ": not an object" << std::endl;
        return;
    }
}

void MMEGOptimizer_ctrl::fillProfile(QJsonValue val)
{
    std::cout << __FUNCTION__ << " - BEGIN" << std::endl;
    if(!val.isObject()) {
        std::cerr << __FUNCTION__ << ": not an object" << std::endl;
        return;
    }
}

void MMEGOptimizer_ctrl::fillRunes(QJsonValue val)
{
    std::cout << __FUNCTION__ << " - BEGIN" << std::endl;
    if(!val.isArray()) {
        std::cerr << __FUNCTION__ << ": not an array" << std::endl;
        return;
    }
}

void MMEGOptimizer_ctrl::fillVersion(QJsonValue val)
{
    std::cout << __FUNCTION__ << " - BEGIN" << std::endl;
    if(!val.isString()) {
        std::cerr << __FUNCTION__ << ": not a string" << std::endl;
        return;
    }
}
