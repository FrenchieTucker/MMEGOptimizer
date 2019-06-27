#ifndef CREATURE_BASE_STAT_H
#define CREATURE_BASE_STAT_H

#include <QtCore/QString>
#include <QtCore/QStringList>

class QJsonValue;

class CreatureBaseStat {
    public:
        CreatureBaseStat(QJsonValue val);

    private:
        void rank(QJsonValue val);
        void hp(QJsonValue val);
        void attack(QJsonValue val);
        void defense(QJsonValue val);
        void criticalChance(QJsonValue val);
        void criticalDamage(QJsonValue val);
        void accuracy(QJsonValue val);
        void resistance(QJsonValue val);
        void speed(QJsonValue val);
        void heroicStatId(QJsonValue val);
        void aura(QJsonValue val);
        void creatureTag(QJsonValue val);
        void trackingName(QJsonValue val);
        void inStone(QJsonValue val);
        void evoStatAttack(QJsonValue val);
        void evoStatDefense(QJsonValue val);
        void evoStatHP(QJsonValue val);

        unsigned int m_rank;
        unsigned int m_hp;
        unsigned int m_attack;
        unsigned int m_defense;
        unsigned int m_criticalChance;
        unsigned int m_criticalDamage;
        unsigned int m_accuracy;
        unsigned int m_resistance;
        unsigned int m_speed;
        unsigned int m_heroicStatId;
        unsigned int m_aura;
        QStringList m_creatureTag;
        QString m_trackingName;
        bool m_inStone;
        unsigned int m_evoStatAttack;
        unsigned int m_evoStatDefense;
        unsigned int m_evoStatHP;
};

#endif // CREATURE_BASE_STAT_H
