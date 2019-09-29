#ifndef CREATURE_H
#define CREATURE_H


#include <QtCore/QString>
#include <QtCore/QList>

class QJsonValue;

enum class Element;

class Creature
{
    public:
        Creature(QJsonValue val);

        Element             element() const    { return m_element; }
        unsigned int        heroicRank() const { return m_heroicRank; }
        QString             heroicStat() const { return m_heroicStat; }
        unsigned int        id() const         { return m_id; }
        QString             idName() const     { return m_idName; }
        unsigned int        level() const      { return m_level; }
        QString             name() const       { return m_name; }
        unsigned int        rank() const       { return m_rank; }
        QList<unsigned int> runes() const      { return m_runes; }
        QList<unsigned int> spells() const     { return m_spells; }
        unsigned int        xp() const         { return m_xp; }

    private:
        void element(QJsonValue val);
        void heroicRank(QJsonValue val);
        void heroicStat(QJsonValue val);
        void id(QJsonValue val);
        void level(QJsonValue val);
        void name(QJsonValue val);
        void rank(QJsonValue val);
        void runes(QJsonValue val);
        void sku(QJsonValue val);
        void spells(QJsonValue val);
        void xp(QJsonValue val);

        Element m_element;
        unsigned int m_heroicRank;
        QString m_heroicStat;
        unsigned int m_id;
        unsigned int m_level;
        QString m_name;
        unsigned int m_rank;
        QList<unsigned int> m_runes;
        QString m_idName;
        QList<unsigned int> m_spells;
        unsigned int m_xp;
};

#endif // CREATURE_H
