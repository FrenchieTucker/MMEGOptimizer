#include "CreatureBaseStat.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>

CreatureBaseStat::CreatureBaseStat(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "rank")
            rank(obj.value(key));
        else if(key == "hp")
            hp(obj.value(key));
        else if(key == "attack")
            attack(obj.value(key));
        else if(key == "defense")
            defense(obj.value(key));
        else if(key == "criticalChance")
            criticalChance(obj.value(key));
        else if(key == "criticalDamage")
            criticalDamage(obj.value(key));
        else if(key == "accuracy")
            accuracy(obj.value(key));
        else if(key == "resistance")
            resistance(obj.value(key));
        else if(key == "speed")
            speed(obj.value(key));
        else if(key == "heroicStatId")
            heroicStatId(obj.value(key));
        else if(key == "aura")
            aura(obj.value(key));
        else if(key == "creatureTag")
            creatureTag(obj.value(key));
        else if(key == "trackingName")
            trackingName(obj.value(key));
        else if(key == "inStone")
            inStone(obj.value(key));
        else if(key == "evoStatAttack")
            evoStatAttack(obj.value(key));
        else if(key == "evoStatDefense")
            evoStatDefense(obj.value(key));
        else if(key == "evoStatHP")
            evoStatHP(obj.value(key));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void CreatureBaseStat::rank(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_rank = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::hp(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_hp = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::attack(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_attack = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::defense(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_defense = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::criticalChance(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_criticalChance = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::criticalDamage(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_criticalDamage = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::accuracy(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_accuracy = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::resistance(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_resistance = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::speed(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_speed = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::heroicStatId(QJsonValue val)
{
    TEST_JSONVALUE(String);
    bool ok;
    int value = val.toString().section("_", 2).toInt(&ok);
    if(!ok)
        throw QString("heroicStatId: aucune valeur trouvée");
    m_heroicStatId = static_cast<unsigned int>(value);
}

void CreatureBaseStat::aura(QJsonValue val)
{
    TEST_JSONVALUE(String);
    bool ok;
    int value = val.toString().section("_", 1).toInt(&ok);
    if(!ok)
        throw QString("aura: aucune valeur trouvée");
    m_aura = static_cast<unsigned int>(value);
}

void CreatureBaseStat::creatureTag(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_creatureTag = val.toString().split(',');
}

void CreatureBaseStat::trackingName(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_trackingName = val.toString();
}

void CreatureBaseStat::inStone(QJsonValue val)
{
    TEST_JSONVALUE(Bool);
    m_inStone = val.toBool();
}

void CreatureBaseStat::evoStatAttack(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_evoStatAttack = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::evoStatDefense(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_evoStatDefense = static_cast<unsigned int>(val.toInt());
}

void CreatureBaseStat::evoStatHP(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_evoStatHP = static_cast<unsigned int>(val.toInt());
}
