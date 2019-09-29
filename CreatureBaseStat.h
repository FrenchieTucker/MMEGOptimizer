#ifndef CREATURE_BASE_STAT_H
#define CREATURE_BASE_STAT_H

#include <QtCore/QString>
#include <QtCore/QStringList>

class QJsonValue;

class CreatureBaseStat {
    public:
        CreatureBaseStat(QJsonValue val);
        ~CreatureBaseStat() = default;

        unsigned int accuracy()       const { return m_accuracy; }
        unsigned int attack()         const { return m_attack; }
        unsigned int aura()           const { return m_aura; }
        QStringList  creatureTag()    const { return m_creatureTag; }
        unsigned int criticalChance() const { return m_criticalChance; }
        unsigned int criticalDamage() const { return m_criticalDamage; }
        unsigned int defense()        const { return m_defense; }
        unsigned int evoStatAttack()  const { return m_evoStatAttack; }
        unsigned int evoStatDefense() const { return m_evoStatDefense; }
        unsigned int evoStatHP()      const { return m_evoStatHP; }
        unsigned int heroicStatId()   const { return m_heroicStatId; }
        unsigned int hp()             const { return m_hp; }
        bool         inStone()        const { return m_inStone; }
        unsigned int rank()           const { return m_rank; }
        unsigned int resistance()     const { return m_resistance; }
        unsigned int speed()          const { return m_speed; }
        QString      trackingName()   const { return m_trackingName; }

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

        unsigned int m_accuracy;
        unsigned int m_attack;
        unsigned int m_aura;
        QStringList  m_creatureTag;
        unsigned int m_criticalChance;
        unsigned int m_criticalDamage;
        unsigned int m_defense;
        unsigned int m_evoStatAttack{0};
        unsigned int m_evoStatDefense{0};
        unsigned int m_evoStatHP{0};
        unsigned int m_heroicStatId;
        unsigned int m_hp;
        bool         m_inStone;
        unsigned int m_rank;
        unsigned int m_resistance;
        unsigned int m_speed;
        QString      m_trackingName;
};

#endif // CREATURE_BASE_STAT_H
