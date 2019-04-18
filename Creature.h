#ifndef CREATURE
#define CREATURE


#include <QtCore/QString>
#include <QtCore/QList>

class QJsonValue;

enum class Element;

class Creature
{
    public:
        Creature(QJsonValue val);

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

#endif // CREATURE
