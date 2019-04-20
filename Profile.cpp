#include "Profile.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QStringList>

EvolutionMaterials::EvolutionMaterials() {}

void EvolutionMaterials::update(QJsonValue val)
{
    TEST_JSONVALUE(Object);
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        m_objects.insert(key, static_cast<unsigned int>(obj.value(key).toInt()));
    }
}

Profile::Profile() {}

void Profile::update(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "arenaRank")
            arenaRank(obj.value("arenaRank"));
        else if(key == "books")
            books(obj.value("books"));
        else if(key == "crimsonStones")
            crimsonStones(obj.value("crimsonStones"));
        else if(key == "crystals")
            crystals(obj.value("crystals"));
        else if(key == "essence")
            essence(obj.value("essence"));
        else if(key == "evolutionMaterials")
            evolutionMaterials(obj.value("evolutionMaterials"));
        else if(key == "ink")
            ink(obj.value("ink"));
        else if(key == "level")
            level(obj.value("level"));
        else if(key == "magicHouse")
            magicHouse(obj.value("magicHouse"));
        else if(key == "name")
            name(obj.value("name"));
        else if(key == "reputationPoints")
            reputationPoints(obj.value("reputationPoints"));
        else if(key == "staffSkills")
            staffSkills(obj.value("staffSkills"));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void Profile::arenaRank(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Profile::books(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::crimsonStones(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::crystals(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::essence(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::evolutionMaterials(QJsonValue val)
{
    TEST_JSONVALUE(Object);
}

void Profile::ink(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::level(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::magicHouse(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Profile::name(QJsonValue val)
{
    TEST_JSONVALUE(String);
}

void Profile::reputationPoints(QJsonValue val)
{
    TEST_JSONVALUE(Double);
}

void Profile::staffSkills(QJsonValue val)
{
    TEST_JSONVALUE(Object);
}