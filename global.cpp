#include "global.h"

#include <QtCore/QString>

Element convertElement(QString _element)
{
    if(_element == "fire")
        return Element::Fire;
    else if(_element == "water")
        return Element::Water;
    else if(_element == "air")
        return Element::Air;
    else if(_element == "earth")
        return Element::Earth;
    else
        throw _element + " [" + __FUNCTION__ + "]";
}

StatAttribute convertStatAttribute(QString _attribute)
{
    if(_attribute == "accuracy")
        return StatAttribute::ACCURACY;
    else if(_attribute == "attack")
        return StatAttribute::ATTACK;
    else if(_attribute == "attack%")
        return StatAttribute::ATTACK_PERCENT;
    else if(_attribute == "criticalChance%")
        return StatAttribute::CRITICAL_CHANCE;
    else if(_attribute == "criticalDamage%")
        return StatAttribute::CRITICAL_DAMAGE;
    else if(_attribute == "defense")
        return StatAttribute::DEFENSE;
    else if(_attribute == "defense%")
        return StatAttribute::DEFENSE_PERCENT;
    else if(_attribute == "hp")
        return StatAttribute::HEALTH_POINTS;
    else if(_attribute == "hp%")
        return StatAttribute::HEALTH_POINTS_PERCENT;
    else if(_attribute == "resistance")
        return StatAttribute::RESISTANCE;
    else if(_attribute == "speed")
        return StatAttribute::SPEED;
    else
        throw _attribute + " [" + __FUNCTION__ + "]";
}

ProcRune convertProcRune(QString _rarete)
{
    if(_rarete == "common")
        return ProcRune::COMMON;
    else if(_rarete == "uncommon")
        return ProcRune::UNCOMMON;
    else if(_rarete == "rare")
        return ProcRune::RARE;
    else if(_rarete == "epic")
        return ProcRune::EPIC;
    else if(_rarete == "legendary")
        return ProcRune::LEGENDARY;
    else if(_rarete == "dark")
        return ProcRune::DARK;
    else
        throw _rarete + " [" + __FUNCTION__ + "]";
}
