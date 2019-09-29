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
#include "Creature_wdg.h"

#include "MMEGOptimizer_wdg.h"

MMEGOptimizer_wdg::MMEGOptimizer_wdg()
    : QObject()
{
    m_ui.setupUi(&m_wdg);

    m_creatureLayout = new QVBoxLayout;
    m_ui.m_creaturesWdg->setLayout(m_creatureLayout);

    QObject::connect(m_ui.actionImport, &QAction::triggered, this, &MMEGOptimizer_wdg::importDemande);
}

MMEGOptimizer_wdg::~MMEGOptimizer_wdg()
{
    qDeleteAll(m_creaturesWdgList);
}

void MMEGOptimizer_wdg::show()
{
    m_wdg.show();
}

void MMEGOptimizer_wdg::fillCreatures(QList<Creature*> creatures)
{
    for (Creature* c : creatures) {
        fillCreature(c);
    }
}

void MMEGOptimizer_wdg::fillCreature(Creature* creature)
{
    unsigned int creatureId = creature->id();
    if (m_creaturesWdgList.contains(creatureId)) {
        Creature_wdg* c = m_creaturesWdgList.value(creatureId, nullptr);
        c->update(creature);
        return;
    }

    Creature_wdg* c = new Creature_wdg(creature);
    m_creaturesWdgList.insert(creatureId, c);
    m_creatureLayout->addWidget(c->widget());
}

void MMEGOptimizer_wdg::fillGuild(const Guild& g)
{
    m_ui.m_guildIdValue->setText(QString::number(g.id()));
    m_ui.m_guildNameValue->setText(g.name());
    m_ui.m_guildRankValue->setText(QString::number(g.rank()));
    m_ui.m_guildRoleValue->setText(g.role());
}

void MMEGOptimizer_wdg::fillProfile(const Profile& p)
{
    m_ui.m_nameValue->setText(p.name());
    m_ui.m_levelValue->setText(QString::number(p.level()));
    m_ui.m_houseValue->setText(p.magicHouse());
    m_ui.m_arenaRankValue->setText(p.arenaRank());
    m_ui.m_crystalsValue->setText(QString::number(p.crystals()));
    m_ui.m_reputationPointsValue->setText(QString::number(p.reputationPoints()));
    m_ui.m_booksValue->setText(QString::number(p.books()));
    m_ui.m_crimsonStonesValue->setText(QString::number(p.crimsonStones()));
    m_ui.m_essenceValue->setText(QString::number(p.essence()));
    m_ui.m_inkValue->setText(QString::number(p.ink()));

    m_ui.m_coreMateriaFragmentValue->setText(QString::number(p.evolutionMaterials().value("Core Materia Fragment", 0)));
    m_ui.m_arcaneMateriaFragmentValue->setText(QString::number(p.evolutionMaterials().value("Arcane Materia Fragment", 0)));
    m_ui.m_coreAnimaEssenceValue->setText(QString::number(p.evolutionMaterials().value("Core Anima Essence", 0)));
    m_ui.m_arcaneAnimaEssenceValue->setText(QString::number(p.evolutionMaterials().value("Arcane Anima Essence", 0)));
    m_ui.m_coreChimeraOilValue->setText(QString::number(p.evolutionMaterials().value("Core Chimera Oil", 0)));
    m_ui.m_arcaneChimeraOilValue->setText(QString::number(p.evolutionMaterials().value("Arcane Chimera Oil", 0)));
    m_ui.m_fieryMaterialValue->setText(QString::number(p.evolutionMaterials().value("Fiery Material", 0)));
    m_ui.m_arcaneFieryMaterialValue->setText(QString::number(p.evolutionMaterials().value("Arcane Fiery Material", 0)));
    m_ui.m_aerialMaterialValue->setText(QString::number(p.evolutionMaterials().value("Aerial Material", 0)));
    m_ui.m_arcaneAerialMaterialValue->setText(QString::number(p.evolutionMaterials().value("Arcane Aerial Material", 0)));
    m_ui.m_glacialMaterialValue->setText(QString::number(p.evolutionMaterials().value("Glacial Material", 0)));
    m_ui.m_arcaneGlacialMaterialValue->setText(QString::number(p.evolutionMaterials().value("Arcane Glacial Material", 0)));
    m_ui.m_naturalMaterialValue->setText(QString::number(p.evolutionMaterials().value("Natural Material", 0)));
    m_ui.m_arcaneNaturalMaterialValue->setText(QString::number(p.evolutionMaterials().value("Arcane Natural Material", 0)));
}

void MMEGOptimizer_wdg::fillRunes(QList<Rune*>)
{}

void MMEGOptimizer_wdg::fillVersion(QString version)
{
    m_ui.m_versionValue->setText(version);
}
