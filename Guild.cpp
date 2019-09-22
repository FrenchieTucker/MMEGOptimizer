#include "Guild.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QStringList>

Guild::Guild()
    : m_id(0)
    , m_name()
    , m_rank(0)
    , m_role()
{}

Guild& Guild::operator=(const Guild& g)
{
    m_id = g.m_id;
    m_name = g.m_name;
    m_rank = g.m_rank;
    m_role = g.m_role;

    return *this;
}

void Guild::update(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "id")
            id(obj.value("id"));
        else if(key == "name")
            name(obj.value("name"));
        else if(key == "rank")
            rank(obj.value("rank"));
        else if(key == "role")
            role(obj.value("role"));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void Guild::id(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_id = static_cast<unsigned int>(val.toInt());
}

void Guild::name(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_name = val.toString();
}

void Guild::rank(QJsonValue val)
{
    TEST_JSONVALUE(Double);
    m_rank = static_cast<unsigned int>(val.toInt());
}

void Guild::role(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_role = val.toString();
}
