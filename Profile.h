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

        unsigned int value(QString key, unsigned int defaultValue) { return m_objects.value(key, defaultValue); }

    private:
        QHash<QString, unsigned int> m_objects;
};

class Profile
{
    public:
        Profile() = default;

        void update(QJsonValue);

        QString arenaRank() const { return m_arenaRank; }
        unsigned int books() const { return m_books; }
        unsigned int crimsonStones() const { return m_crimsonStones; }
        unsigned int crystals() const { return m_crystals; }
        unsigned int essence() const { return m_essence; }
        EvolutionMaterials evolutionMaterials() const { return m_evolutionMaterials; }
        unsigned int ink() const { return m_ink; }
        unsigned int level() const { return m_level; }
        QString magicHouse() const { return m_magicHouse; }
        QString name() const { return m_name; }
        unsigned int reputationPoints() const { return m_reputationPoints; }
        QHash<QString, unsigned int> staffSkills() const { return m_staffSkills; }

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
        QHash<QString, unsigned int> m_staffSkills;
};

#endif // PROFILE_H
