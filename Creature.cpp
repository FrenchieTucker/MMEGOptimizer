#include "Creature.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

#include <QtCore/QString>
#include <QtCore/QStringList>


Creature::Creature(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "element")
            element(obj.value("element"));
        else if(key == "heroicRank")
            heroicRank(obj.value("heroicRank"));
        else if(key == "heroicStat")
            heroicStat(obj.value("heroicStat"));
        else if(key == "id")
            id(obj.value("id"));
        else if(key == "level")
            level(obj.value("level"));
        else if(key == "name")
            name(obj.value("name"));
        else if(key == "rank")
            rank(obj.value("rank"));
        else if(key == "runes")
            runes(obj.value("runes"));
        else if(key == "sku")
            sku(obj.value("sku"));
        else if(key == "spells")
            spells(obj.value("spells"));
        else if(key == "xp")
            xp(obj.value("xp"));
        else
            throw key;
    }
}

void Creature::element(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_element = convertElement(val.toString());
}

void Creature::heroicRank(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_heroicRank = static_cast<unsigned int>(val.toInt());
}

void Creature::heroicStat(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_heroicStat = val.toString();
}

void Creature::id(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_id = static_cast<unsigned int>(val.toDouble());
}

void Creature::level(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_level = static_cast<unsigned int>(val.toInt());
}

void Creature::name(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_name = val.toString();
}

void Creature::rank(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_rank = static_cast<unsigned int>(val.toInt(0));
}

void Creature::runes(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        m_runes.append(static_cast<unsigned int>(v.toInt()));
    }
}

void Creature::sku(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_idName = val.toString();
}

void Creature::spells(QJsonValue val)
{
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        m_spells.append(static_cast<unsigned int>(v.toInt()));
    }
}

void Creature::xp(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_xp = static_cast<unsigned int>(val.toInt());
}
