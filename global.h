#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

class QString;

#define TEST_JSONVALUE(X)                                             \
    do{                                                               \
        /*std::cout << __FUNCTION__ << " - BEGIN" << std::endl;*/     \
        if(!val.is ## X()) {                                          \
            std::cerr << __FUNCTION__ << ": not an " #X << std::endl; \
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

#endif // GLOBAL_H
