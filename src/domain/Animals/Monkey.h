#ifndef MONKEY_H
#define MONKEY_H
#include "Herbo.h"


class Monkey : public Herbo {
public:
    Monkey(const std::string& description, int food_consumption, int inventory_number, int kindness)
        : Herbo(description, food_consumption, inventory_number, kindness) {}
};


#endif //MONKEY_H
