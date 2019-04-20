#ifndef RUNE_H
#define RUNE_H

#include "global.h"

#include <QtCore/QString>
#include <QtCore/QList>

class QJsonValue;

class Stat
{
    public:
        Stat(QString, QJsonValue);

    private:
        StatAttribute m_statAttr{StatAttribute::UNDEFINED};
        double m_value{0.};
};

class Rune
{
    public:
        Rune(QJsonValue);

    private:
        void creature(QJsonValue);
        void id(QJsonValue);
        void level(QJsonValue);
        void mainRune(QJsonValue);
        void rarity(QJsonValue);
        void shape(QJsonValue);
        void sku(QJsonValue);
        void stats(QJsonValue);
        void type(QJsonValue);
        void value(QJsonValue);

        unsigned int m_creature;
        unsigned int m_id;
        unsigned int m_level;
        QString m_main;
        QString m_rarity;
        QString m_shape;
        QString m_sku;
        QList<Stat*> m_stats;
        QString m_type;
        double m_value;
};

#endif // RUNE_H
