#include "Rune.h"
#include "global.h"

#include <QtCore/QJsonArray>
#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QStringList>


Stat::Stat(QString key, QJsonValue val)
{
    static QStringList names{"accuracy", "attack", "attack%", "criticalChance%", "criticalDamage%", "defense", "defense%", "hp", "hp%", "resistance", "speed"};
    if(!names.contains(key))
        throw key + " [" + __FUNCTION__ + "]";

    m_statAttr = convertStatAttribute(key);

    if(val.isArray()) {
        for (QJsonValue v : val.toArray()) {
            if(!v.isDouble())
                throw QString("Un élément du tableau correspondant à la clé %1 n'est pas une valeur").arg(key);

            m_value += v.toDouble();
        };
    }
    else
        throw QString("%1 n'est pas un Tableau").arg(key);
}

Rune::Rune(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "creature")
            creature(obj.value("creature"));
        else if(key == "id")
            id(obj.value("id"));
        else if(key == "level")
            level(obj.value("level"));
        else if(key == "main")
            mainRune(obj.value("main"));
        else if(key == "rarity")
            rarity(obj.value("rarity"));
        else if(key == "shape")
            shape(obj.value("shape"));
        else if(key == "sku")
            sku(obj.value("sku"));
        else if(key == "stats")
            stats(obj.value("stats"));
        else if(key == "type")
            type(obj.value("type"));
        else if(key == "value")
            value(obj.value("value"));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void Rune::creature(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_creature = static_cast<unsigned int>(val.toDouble());
}

void Rune::id(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_id = static_cast<unsigned int>(val.toDouble());
}

void Rune::level(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_level = static_cast<unsigned int>(val.toDouble());
}

void Rune::mainRune(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_main = val.toString();
}

void Rune::rarity(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_rarity = val.toString();
}

void Rune::shape(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_shape = val.toString();
}

void Rune::sku(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_sku = val.toString();
}

void Rune::stats(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        m_stats.append(new Stat(key, obj.value(key)));
    }
}

void Rune::type(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_id = static_cast<unsigned int>(val.toDouble());
}

void Rune::value(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_id = static_cast<unsigned int>(val.toDouble());
}
