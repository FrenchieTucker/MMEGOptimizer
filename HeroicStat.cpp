#include "HeroicStat.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>

HeroicStat::HeroicStat(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "heroicStar1")
            heroicStar(1, obj.value("heroicStar1"));
        else if(key == "heroicStar2")
            heroicStar(2, obj.value("heroicStar2"));
        else if(key == "heroicStar3")
            heroicStar(3, obj.value("heroicStar3"));
        else if(key == "heroicStar4")
            heroicStar(4, obj.value("heroicStar4"));
        else if(key == "heroicStar5")
            heroicStar(5, obj.value("heroicStar5"));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void HeroicStat::heroicStar(unsigned int level, QJsonValue val)
{
    TEST_JSONVALUE(Object);
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        QJsonValue v = obj.value(key);
        if(!v.isDouble()) {
            std::cerr << "la valeur associee à la cle " << key.toUtf8().constData() << "n'est pas un entier ou une decimale" << std::endl;
            continue;
        }
        m_heroicStarStats[level-1].insert(key, v.toDouble());
    }
}
