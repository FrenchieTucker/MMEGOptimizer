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

#include <QtWidgets/QFileDialog>
#include <QtCore/QString>

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

    std::cout << "fichier à importer : " << fileName.toUtf8().constData() << std::endl;
    //QString content = extractInfosFromFile(fileName.toUtf8().constData());
    //std::cout << "contenu : [" << content.toUtf8().constData() << "]" << std::endl;
}
