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

#include "Guild.h"
#include "Profile.h"
#include "Rune.h"
#include "Creature.h"

#include "MMEGOptimizer_wdg.h"

MMEGOptimizer_wdg::MMEGOptimizer_wdg()
    : QObject()
{
    m_ui.setupUi(&m_wdg);

    QObject::connect(m_ui.actionImport, &QAction::triggered, this, &MMEGOptimizer_wdg::importDemande);
}

MMEGOptimizer_wdg::~MMEGOptimizer_wdg()
{}

void MMEGOptimizer_wdg::show()
{
    m_wdg.show();
}

void MMEGOptimizer_wdg::fillCreatures(QList<Creature*>)
{}

void MMEGOptimizer_wdg::fillGuild(Guild g)
{
    m_ui.m_guildIdValue->setText(QString::number(g.id()));
    m_ui.m_guildNameValue->setText(g.name());
    m_ui.m_guildRankValue->setText(QString::number(g.rank()));
    m_ui.m_guildRoleValue->setText(g.role());
}

void MMEGOptimizer_wdg::fillProfile(Profile)
{}

void MMEGOptimizer_wdg::fillRunes(QList<Rune*>)
{}

void MMEGOptimizer_wdg::fillVersion(QString version)
{
    m_ui.m_versionValue->setText(version);
}
