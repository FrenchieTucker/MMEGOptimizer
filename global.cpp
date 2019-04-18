#include "global.h"

#include <QtCore/QString>

Element convertElement(QString _element)
{
    if(_element == "fire")
        return Element::Fire;
    else if(_element == "water")
        return Element::Fire;
    else if(_element == "air")
        return Element::Air;
    else if(_element == "earth")
        return Element::Earth;
    else
        return Element::Undefined;
}
