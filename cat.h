#include "animal.h"

#ifndef CAT_H
#define CAT_H

class Cat: public Animal
{
public:
    Cat();

    string Color;

    bool writeToBase() override;
};

#endif // CAT_H
