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

#ifndef MMEGOPTIMIZER_CTRL_H
#define MMEGOPTIMIZER_CTRL_H

#include <memory>

#include "MMEGOptimizer_wdg.h"
#include "Guild.h"
#include "Profile.h"

#include <QtCore/QList>
#include <QtCore/QHash>

class Creature;
class Rune;
class AuraSkillUp;
class AuraBase;
class ProcRuneParSubStat;
class HeroicStat;
class CreatureBaseStat;
class PuissanceGlypheParNiveau;

enum class Element;

struct CreatureId {
    unsigned int id;
    Element el;
};

class MMEGOptimizer_ctrl
{
public:
    MMEGOptimizer_ctrl();
    ~MMEGOptimizer_ctrl() = default;

    void show();

    CreatureBaseStat* creatureBaseStatById(CreatureId id);

private:
    std::unique_ptr<MMEGOptimizer_wdg> m_wdg;

    void initialiserDonneesStatiques();
    void recupererDonneesApportSetGlyphes();
    void recupererDonneesAugmentationAura();
    void recupererDonneesCreaturesNomParId();
    void recupererDonneesDefinitionAura();
    void recupererDonneesElementTraduction();
    void recupererDonneesLibelleAura();
    void recupererDonneesProcGlypheParSubstat();
    void recupererDonneesStatHeroiques();
    void recupererDonneesStatsCreaturesBases();
    void recupererDonneesStatsGlyphesParNiveau();

    QHash<QString, QPair<QString, double>> m_apportSetGlyphes;
    QMap<unsigned int, AuraSkillUp*> m_augmentationAura;
    QMap<unsigned int, QString> m_nomparId;
    QMap<unsigned int, AuraBase*> m_auraBases;
    QMap<QString, QString> m_elementsTraduits;
    QMap<unsigned int, QString> m_libellesAura;
    QMap<QString, ProcRuneParSubStat*> m_procRuneParSubStat;
    QMap<unsigned int, HeroicStat*> m_heroicStat;
    QMap<CreatureId, CreatureBaseStat*> m_creatureBaseStat;
    QMap<QString, PuissanceGlypheParNiveau*> m_glyphesParNiveau;

    void importerFichier();
    void extractModels(QString content);

    void extractCreatures(QJsonValue val);
    void extractCreature(QJsonValue val);
    void extractGuild(QJsonValue val);
    void extractProfile(QJsonValue val);
    void extractRunes(QJsonValue val);
    void extractRune(QJsonValue val);
    void extractVersion(QJsonValue val);

    void validateData();

    // Temporary User Data
    QList<Creature*> m_creatures;
    Guild m_guild;
    Profile m_profile;
    QList<Rune*> m_runes;
    QString m_version;
};

#endif // MMEGOPTIMIZER_CTRL_H
