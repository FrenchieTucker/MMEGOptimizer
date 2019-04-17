#include "Creature.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
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
    m_element = convertElement(val.toString());
}

void Creature::heroicRank(QJsonValue val)
{
    ;
}

void Creature::id(QJsonValue val)
{
    ;
}

void Creature::level(QJsonValue val)
{
    ;
}

void Creature::name(QJsonValue val)
{
    ;
}

void Creature::rank(QJsonValue val)
{
    ;
}

void Creature::runes(QJsonValue val)
{
    ;
}

void Creature::sku(QJsonValue val)
{
    ;
}

void Creature::spells(QJsonValue val)
{
    ;
}

void Creature::xp(QJsonValue val)
{
    ;
}
