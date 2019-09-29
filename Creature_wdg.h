#ifndef CREATURE_WDG_H
#define CREATURE_WDG_H

#include <memory>

#include "ui_Creature.h"

class Creature;
class QFrame;

class Creature_wdg
{
    public:
        Creature_wdg(Creature*);
        QFrame* widget() { return &m_wdg; }

        void update(Creature*);

    private:
        void setName(QString);
        void setId(unsigned int);
        void setLevel(unsigned int);

        Ui::Creature m_ui;
        QFrame m_wdg;
};

#endif // CREATURE_WDG_H
