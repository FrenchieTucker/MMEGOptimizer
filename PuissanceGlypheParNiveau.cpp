#include "PuissanceGlypheParNiveau.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

PuissanceGlypheParNiveau::PuissanceGlypheParNiveau(QJsonValue val) {
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(key == "epic")
            epic(obj.value(key));
        else if(key == "legendary")
            legendary(obj.value(key));
        else if(key == "dark")
            dark(obj.value(key));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void PuissanceGlypheParNiveau::epic(QJsonValue val) {
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        m_epic.append(static_cast<double>(v.toInt()));
    }
}

void PuissanceGlypheParNiveau::legendary(QJsonValue val) {
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        m_legendary.append(static_cast<double>(v.toInt()));
    }
}

void PuissanceGlypheParNiveau::dark(QJsonValue val) {
    TEST_JSONVALUE(Array);
    for(QJsonValue v : val.toArray()) {
        m_legendary.append(static_cast<double>(v.toInt()));
    }
}
