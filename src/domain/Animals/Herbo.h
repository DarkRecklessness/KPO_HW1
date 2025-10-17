#ifndef HERBO_H
#define HERBO_H
#include "Animal.h"


class Herbo : public Animal {
protected:
    int kindness; // [1, 10]
    Herbo(const std::string& description, int food_consumption, int inventory_number, int kindness);
public:
    int GetKindness() const;
};



#endif //HERBO_H
