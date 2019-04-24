#include "ProcRuneParSubStat.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

#include <QtCore/QString>
#include <QtCore/QStringList>

ProcRuneParSubStat::ProcRuneParSubStat(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "common")
            common(obj.value("common"));
        else if(key == "uncommon")
            uncommon(obj.value("uncommon"));
        else if(key == "rare")
            rare(obj.value("rare"));
        else if(key == "epic")
            epic(obj.value("epic"));
        else if(key == "legendary")
            legendary(obj.value("legendary"));
        else if(key == "dark")
            dark(obj.value("dark"));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void ProcRuneParSubStat::common(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_common = static_cast<unsigned int>(val.toDouble());
}

void ProcRuneParSubStat::uncommon(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_uncommon = static_cast<unsigned int>(val.toDouble());
}

void ProcRuneParSubStat::rare(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_rare = static_cast<unsigned int>(val.toDouble());
}

void ProcRuneParSubStat::epic(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_epic = static_cast<unsigned int>(val.toDouble());
}

void ProcRuneParSubStat::legendary(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_legendary = static_cast<unsigned int>(val.toDouble());
}

void ProcRuneParSubStat::dark(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_dark = static_cast<unsigned int>(val.toDouble());
}
