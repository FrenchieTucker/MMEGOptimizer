#include "AuraSkillUp.h"

#include <QtCore/QJsonValue>
#include <QtCore/QJsonObject>

#include <QtCore/QString>
#include <QtCore/QStringList>


AttributeSkillUp::AttributeSkillUp(QString statsAugmente, QString id, QString suffixe)
    : m_statsAugmente(statsAugmente)
    , m_id(id)
    , m_suffixe(suffixe)
{}

AuraSkillUp::AuraSkillUp(QJsonValue val)
{
    if(!val.isObject()) {
        throw QString("l'attribut n'est pas un objet") + " [" + __FUNCTION__ + "]";
    }

    QJsonObject o = val.toObject();
    QStringList keys = o.keys();
    for(unsigned int i = 0; i < 4; ++i) {
        QString attr1 = QString("skillUp%1").arg(i),
                attr2 = QString("skillUp%1TID").arg(i),
                attr3 = QString("skillUp%1Suffix").arg(i);

        if(!keys.contains(attr1)) {
            throw QString("l'attribut '%1' n'est pas present").arg(attr1);
        } else if(!keys.contains(attr2)) {
            throw QString("l'attribut '%1' n'est pas present").arg(attr2);
        } /*else if(!keys.contains(attr3)) { // L'attribut Suffix n'est pas obligatoire
            throw QString("l'attribut '%1' n'est pas present").arg(attr3);
        }*/

        QJsonValue val1 = o.value(attr1),
                   val2 = o.value(attr2),
                   val3 = !keys.contains(attr3)? QJsonValue(QString()): o.value(attr3);

        if(!val1.isString()) {
            throw QString("la valeur de l'attribut '%1' n'est pas une chaine de caracteres").arg(attr1);
        } else if(!val2.isString()) {
            throw QString("la valeur de l'attribut '%1' n'est pas une chaine de caracteres").arg(attr2);
        } else if(!val3.isString()) {
            throw QString("la valeur de l'attribut '%1' n'est pas une chaine de caracteres").arg(attr3);
        }

        m_attributes.insert(i, new AttributeSkillUp(val1.toString(),
                                                    val2.toString(),
                                                    val3.toString()));
    }
}
