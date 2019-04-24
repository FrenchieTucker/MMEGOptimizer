#ifndef PROC_RUNE_PAR_SUBSTAT_H
#define PROC_RUNE_PAR_SUBSTAT_H

class QJsonValue;

class ProcRuneParSubStat
{
    public:
        ProcRuneParSubStat(QJsonValue);

    private:
        void common(QJsonValue);
        void uncommon(QJsonValue);
        void rare(QJsonValue);
        void epic(QJsonValue);
        void legendary(QJsonValue);
        void dark(QJsonValue);

        unsigned int m_common;
        unsigned int m_uncommon;
        unsigned int m_rare;
        unsigned int m_epic;
        unsigned int m_legendary;
        unsigned int m_dark;
};

#endif
