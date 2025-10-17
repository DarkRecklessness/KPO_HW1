#ifndef PREDATOR_H
#define PREDATOR_H
#include "Animal.h"


class Predator : public Animal {
protected:
    Predator(const std::string& description, int food_consumption, int inventory_number)
        : Animal(description, food_consumption, inventory_number)
    {}
};


#endif //PREDATOR_H
