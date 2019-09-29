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

#ifndef MMEGOPTIMIZER_WDG_H
#define MMEGOPTIMIZER_WDG_H

#include <QtWidgets/QMainWindow>
#include <QtCore/QMap>

#include "ui_MMEGOptimizer.h"

class Rune;
class Profile;
class Guild;
class Creature;
class Creature_wdg;
class CreatureBaseStat;

class MMEGOptimizer_ctrl;

class MMEGOptimizer_wdg : public QObject
{
    Q_OBJECT

public:
    MMEGOptimizer_wdg();
    ~MMEGOptimizer_wdg();

    void show();

    void fillCreatures(QList<Creature*>, MMEGOptimizer_ctrl*);
    void fillCreature(Creature* creature, CreatureBaseStat* cbs);
    void fillGuild(const Guild &);
    void fillProfile(const Profile &);
    void fillRunes(QList<Rune*>);
    void fillVersion(QString);

    QPixmap pixmap(QString);

signals:
    void importDemande();

private:
    Ui::MMEGOptimizer_wdg m_ui;
    QMainWindow m_wdg;

    QVBoxLayout* m_creatureLayout;
    QMap<unsigned int, Creature_wdg*> m_creaturesWdgList;
    QMap<QString, QByteArray> m_urlToData;
};

#endif // MMEGOPTIMIZER_WDG_H
