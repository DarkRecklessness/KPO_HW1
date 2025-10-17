#ifndef RABBIT_H
#define RABBIT_H
#include "Herbo.h"


class Rabbit : public Herbo {
public:
    Rabbit(const std::string& description, int food_consumption, int inventory_number, int kindness)
        : Herbo(description, food_consumption, inventory_number, kindness) {}
};


#endif //RABBIT_H
