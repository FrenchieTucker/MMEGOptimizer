#include "Creature_wdg.h"
#include <QtWidgets/QFrame>

#include "Creature.h"

Creature_wdg::Creature_wdg(Creature* c)
{
    m_ui.setupUi(&m_wdg);


    //m_ui.m_element;
    //m_ui.m_academicMagic;
    //m_ui.m_role;

    //m_ui.m_icon->setPixmap();

    setName(c->name());
    setId(c->id());
    setLevel(c->level());

    //m_ui.m_runes;

    //m_ui.m_stats;
}

void Creature_wdg::update(Creature* c)
{
    setName(c->name());
    setId(c->id());
    setLevel(c->level());
}

void Creature_wdg::setName(QString name)
{
    m_ui.m_name->setText(name);
}

void Creature_wdg::setId(unsigned int id)
{
    m_ui.m_id->setText(QStringLiteral("Id : %1").arg(id));
}

void Creature_wdg::setLevel(unsigned int level)
{
    m_ui.m_level->setText(QStringLiteral("Level : %1").arg(level));
}
