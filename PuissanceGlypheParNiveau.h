#ifndef PUISSANCE_GLYPHE_PAR_NIVEAU_H
#define PUISSANCE_GLYPHE_PAR_NIVEAU_H

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QList>

class QJsonValue;

class PuissanceGlypheParNiveau {
    public:
        PuissanceGlypheParNiveau(QJsonValue val);

    private:
        void epic(QJsonValue val);
        void legendary(QJsonValue val);
        void dark(QJsonValue val);

        QList<double> m_epic;
        QList<double> m_legendary;
        QList<double> m_dark;
};

#endif // PUISSANCE_GLYPHE_PAR_NIVEAU_H
