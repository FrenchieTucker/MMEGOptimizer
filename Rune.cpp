#include "Rune.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QStringList>

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
            throw key;
    }
}

void Rune::creature(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Rune::id(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Rune::level(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Rune::mainRune(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Rune::rarity(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Rune::shape(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Rune::sku(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Rune::stats(QJsonValue val)
{
    TEST_JSONVALUE(Object);
}

void Rune::type(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Rune::value(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}
