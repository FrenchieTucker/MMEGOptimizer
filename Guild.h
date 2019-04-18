#ifndef GUILD_H
#define GUILD_H

#include <QtCore/QString>

class QJsonValue;

class Guild
{
    public:
        Guild();

        void update(QJsonValue);

    private:
        void id(QJsonValue);
        void name(QJsonValue);
        void rank(QJsonValue);
        void role(QJsonValue);

        unsigned int m_id;
        QString m_name;
        unsigned int m_rank;
        QString m_role;
};

#endif // GUILD_H
