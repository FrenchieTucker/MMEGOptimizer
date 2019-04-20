#ifndef AURA_SKILL_UP_H
#define AURA_SKILL_UP_H


#include <QtCore/QMap>

class QJsonValue;


class AttributeSkillUp
{
    public:
        AttributeSkillUp(QString statsAugmente, QString id, QString suffixe);

    private:
        QString m_statsAugmente;
        QString m_id;
        QString m_suffixe;
};

class AuraSkillUp
{
    public:
        AuraSkillUp(QJsonValue);

    private:
        QMap<unsigned int, AttributeSkillUp*> m_attributes;
};

#endif // AURA_SKILL_UP_H
