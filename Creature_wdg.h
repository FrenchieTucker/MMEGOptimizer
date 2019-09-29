#ifndef CREATURE_WDG_H
#define CREATURE_WDG_H

#include <memory>

#include "ui_Creature.h"

#include "CreatureBaseStat.h"

class Creature;
class QFrame;
class MMEGOptimizer_wdg;

class Creature_wdg
{
    public:
        Creature_wdg(Creature*, CreatureBaseStat*, MMEGOptimizer_wdg*);
        QFrame* widget() { return &m_wdg; }

        void update(Creature*);

    private:
        void setElement(QString);
        void setAcademicMagic(QString);
        void setRole(QString);

        void setMonsterIcon(QString);

        void setName(QString);
        void setId(unsigned int);
        void setLevel(unsigned int);

        void setFamilies(QStringList);

        Ui::Creature m_ui;
        QFrame m_wdg;
        MMEGOptimizer_wdg* m_parent;

        std::unique_ptr<CreatureBaseStat> m_cbs{nullptr};
};

#endif // CREATURE_WDG_H
