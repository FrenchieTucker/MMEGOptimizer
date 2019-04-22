#include "AuraBase.h"
#include "global.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>
#include <QtCore/QStringList>
#include <QtCore/QRegularExpression>

AuraBase::AuraBase(QJsonValue val)
{
    QJsonObject obj = val.toObject();
    for(QString key : obj.keys()) {
        if(QRegularExpression("target[0-9]+").match(key).hasMatch())
            target(key.mid(sizeof("target")).toInt(), obj.value(key));
        else if(QRegularExpression("refSku[0-9]+").match(key).hasMatch())
            refSku(key.mid(sizeof("refSku")).toInt(), obj.value(key));
        else if(QRegularExpression("params[0-9]+").match(key).hasMatch())
            params(key.mid(sizeof("params")).toInt(), obj.value(key));
        else if(QRegularExpression("activation[0-9]+").match(key).hasMatch())
            activation(key.mid(sizeof("activation")).toInt(), obj.value(key));
        else if(QRegularExpression("multipliers[0-9]+").match(key).hasMatch())
            multipliers(key.mid(sizeof("multipliers")).toInt(), obj.value(key));
        else if(QRegularExpression("launchCondition[0-9]+").match(key).hasMatch())
            launchCondition(key.mid(sizeof("launchCondition")).toInt(), obj.value(key));
        else if(QRegularExpression("prob[0-9]+").match(key).hasMatch())
            prob(key.mid(sizeof("prob")).toInt(), obj.value(key));
        else if(QRegularExpression("type[0-9]+").match(key).hasMatch())
            type(key.mid(sizeof("type")).toInt(), obj.value(key));
        else if(QRegularExpression("status[0-9]+").match(key).hasMatch())
            status(key.mid(sizeof("status")).toInt(), obj.value(key));
        else if(key == "spellup")
            spellup(obj.value(key));
        else
            throw key + " [" + __FUNCTION__ + "]";
    }
}

void AuraBase::target(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_target.insert(id, val.toString());
}

void AuraBase::refSku(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_refSku.insert(id, val.toString());
}

void AuraBase::params(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_params.insert(id, val.toString());
}

void AuraBase::activation(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_activation.insert(id, val.toString());
}

void AuraBase::multipliers(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_multipliers.insert(id, val.toString());
}

void AuraBase::launchCondition(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_launchCondition.insert(id, val.toString());
}

void AuraBase::prob(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_prob.insert(id, val.toString());
}

void AuraBase::type(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_type.insert(id, val.toString());
}

void AuraBase::status(int id, QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_status.insert(id, val.toString());
}

void AuraBase::spellup(QJsonValue val)
{
    TEST_JSONVALUE(String);
    m_spellup = val.toString();
}
