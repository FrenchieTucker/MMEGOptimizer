#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

class QString;

const unsigned int ANDROID_ID = 1000000;
const unsigned int    SIRI_ID = 1000001;

#define TEST_JSONVALUE(X)                                             \
    do{                                                               \
        /*std::cout << __FUNCTION__ << " - BEGIN" << std::endl;*/     \
        if(!val.is ## X()) {                                          \
            std::cerr << __FUNCTION__ << ": not a " #X " QJsonValue" << std::endl; \
            return;                                                   \
        }                                                             \
    }while(false)

enum class Element{
    Undefined,
    Fire,
    Water,
    Air,
    Earth
};

Element convertElement(QString _element);

enum class StatAttribute{
    UNDEFINED,
    ACCURACY,
    ATTACK,
    ATTACK_PERCENT,
    CRITICAL_CHANCE,
    CRITICAL_DAMAGE,
    DEFENSE,
    DEFENSE_PERCENT,
    HEALTH_POINTS,
    HEALTH_POINTS_PERCENT,
    RESISTANCE,
    SPEED
};

StatAttribute convertStatAttribute(QString _element);

enum class ProcRune{
    UNDEFINED,
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY,
    DARK
};

ProcRune convertProcRune(QString _rarete);

#endif // GLOBAL_H
