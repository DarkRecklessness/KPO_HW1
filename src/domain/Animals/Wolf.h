#ifndef WOLF_H
#define WOLF_H
#include "Predator.h"


class Wolf : public Predator {
public:
    Wolf(const std::string& description, int food_consumption, int inventory_number)
        : Predator(description, food_consumption, inventory_number)
    {}
};


#endif //WOLF_H
