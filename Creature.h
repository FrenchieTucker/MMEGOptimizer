#ifndef CREATURE
#define CREATURE

class QJsonValue;
class QString;

enum class Element;

class Creature
{
    public:
        Creature(QJsonValue val);

    private:
        void element(QJsonValue val);
        void heroicRank(QJsonValue val);
        void id(QJsonValue val);
        void level(QJsonValue val);
        void name(QJsonValue val);
        void rank(QJsonValue val);
        void runes(QJsonValue val);
        void sku(QJsonValue val);
        void spells(QJsonValue val);
        void xp(QJsonValue val);

        Element m_element;
};

#endif // CREATURE
