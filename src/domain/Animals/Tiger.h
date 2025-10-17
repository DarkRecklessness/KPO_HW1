#ifndef TIGER_H
#define TIGER_H
#include "Predator.h"


class Tiger : public Predator {
public:
    Tiger(const std::string& description, int food_consumption, int inventory_number)
        : Predator(description, food_consumption, inventory_number)
    {}
};


#endif //TIGER_H
