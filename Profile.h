#ifndef PROFILE_H
#define PROFILE_H

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QHash>

class QJsonValue;

class EvolutionMaterials
{
    public:
        EvolutionMaterials();

        void update(QJsonValue);

    private:
        QHash<QString, unsigned int> m_objects;
};

class Profile
{
    public:
        Profile();
        Profile& operator=(const Profile&);

        void update(QJsonValue);

    private:
        void arenaRank(QJsonValue);
        void books(QJsonValue);
        void crimsonStones(QJsonValue);
        void crystals(QJsonValue);
        void essence(QJsonValue);
        void evolutionMaterials(QJsonValue);
        void ink(QJsonValue);
        void level(QJsonValue);
        void magicHouse(QJsonValue);
        void name(QJsonValue);
        void reputationPoints(QJsonValue);
        void staffSkills(QJsonValue);

        QString m_arenaRank;
        unsigned int m_books;
        unsigned int m_crimsonStones;
        unsigned int m_crystals;
        unsigned int m_essence;
        EvolutionMaterials m_evolutionMaterials;
        unsigned int m_ink;
        unsigned int m_level;
        QString m_magicHouse;
        QString m_name;
        unsigned int m_reputationPoints;
        QStringList m_staffSkills;
};

#endif // PROFILE_H
