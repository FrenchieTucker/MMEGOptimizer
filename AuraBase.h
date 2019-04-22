#ifndef AURA_BASE_H
#define AURA_BASE_H

#include <QtCore/QString>
#include <QtCore/QMap>

class QJsonValue;

class AuraBase
{
    public:
        AuraBase(QJsonValue);

    private:
        void target         (int, QJsonValue);
        void refSku         (int, QJsonValue);
        void params         (int, QJsonValue);
        void activation     (int, QJsonValue);
        void multipliers    (int, QJsonValue);
        void launchCondition(int, QJsonValue);
        void prob           (int, QJsonValue);
        void type           (int, QJsonValue);
        void status         (int, QJsonValue);
        void spellup        (     QJsonValue);

        QMap<int, QString> m_target;
        QMap<int, QString> m_refSku;
        QMap<int, QString> m_params;
        QMap<int, QString> m_activation;
        QMap<int, QString> m_multipliers;
        QMap<int, QString> m_launchCondition;
        QMap<int, QString> m_prob;
        QMap<int, QString> m_type;
        QMap<int, QString> m_status;
        QString m_spellup;
};

#endif // AURA_BASE_H
