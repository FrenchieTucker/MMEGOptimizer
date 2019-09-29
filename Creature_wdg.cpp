#include "Creature_wdg.h"
#include <QtWidgets/QFrame>

#include "global.h"
#include "Creature.h"
#include "CreatureBaseStat.h"
#include "MMEGOptimizer_wdg.h"
#include <QtWidgets/QLayoutItem>

Creature_wdg::Creature_wdg(Creature* c, CreatureBaseStat* cbs, MMEGOptimizer_wdg* parent)
    : m_parent(parent)
    , m_cbs(cbs)
{
    m_ui.setupUi(&m_wdg);


    QStringList creatureTag = cbs->creatureTag();
    setElement(creatureTag.takeFirst());
    setAcademicMagic(creatureTag.takeFirst());
    setRole(creatureTag.takeFirst());

    setMonsterIcon(cbs->trackingName());

    setName(c->name());
    setId(c->id());
    setLevel(c->level());

    setFamilies(creatureTag);

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

void Creature_wdg::setMonsterIcon(QString iconName)
{
    QPixmap p = m_parent->pixmap(QString("https://www.mmeg-optimizer.com/img/monsters/%1.png").arg(iconName));
    m_ui.m_icon->setPixmap(p.scaledToWidth(75));
    m_ui.m_icon->setFixedSize(75, 75);
}

void Creature_wdg::setElement(QString element)
{
    QPixmap p = m_parent->pixmap(QString("https://www.mmeg-optimizer.com/img/icon/Element-%1.png").arg(element));
    m_ui.m_element->setPixmap(p.scaledToHeight(30));
    m_ui.m_element->setFixedSize(30, 30);
}

void Creature_wdg::setAcademicMagic(QString academicMagic)
{
    QPixmap p = m_parent->pixmap(QString("https://www.mmeg-optimizer.com/img/icon/icon-%1.png").arg(academicMagic));
    m_ui.m_academicMagic->setPixmap(p.scaledToHeight(30));
    m_ui.m_academicMagic->setFixedSize(30, 30);
}

void Creature_wdg::setRole(QString role)
{
    QPixmap p = m_parent->pixmap(QString("https://www.mmeg-optimizer.com/img/icon/icon-%1.png").arg(role));
    m_ui.m_role->setPixmap(p.scaledToHeight(30));
    m_ui.m_role->setFixedSize(30, 30);
}

void Creature_wdg::setFamilies(QStringList families)
{
    QVBoxLayout* vlay = static_cast<QVBoxLayout*>(m_ui.m_families->layout());
    if (!vlay) {
        vlay = new QVBoxLayout;
        m_ui.m_families->setLayout(vlay);
    }

    QLayoutItem* child = nullptr;
    while ((child = vlay->takeAt(0)) != nullptr) {
        delete child;
    }

    for (QString family : families) {
        QLabel* l = new QLabel;
        QPixmap p = m_parent->pixmap(QString("https://www.mmeg-optimizer.com/img/icon/icon-tag-%1.png").arg(family));
        l->setPixmap(p.scaledToHeight(30));
        l->setFixedSize(30, 30);
        vlay->addWidget(l);
    }
}
