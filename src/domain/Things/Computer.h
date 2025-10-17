#ifndef COMPUTER_H
#define COMPUTER_H
#include "Thing.h"


class Computer : public Thing {
public:
    Computer(const std::string& description, int inventory_number)
        : Thing(description, inventory_number) {}
};


#endif //COMPUTER_H
