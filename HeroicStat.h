#ifndef HEROIC_STAT_H
#define HEROIC_STAT_H

#include <array>
#include <QtCore/QMap>

class QJsonValue;
class QString;

class HeroicStat
{
    public:
        HeroicStat(QJsonValue);

    private:
        void heroicStar(unsigned int, QJsonValue);

        std::array<QMap<QString, double>, 5> m_heroicStarStats;
};

#endif // HEROIC_STAT_H
