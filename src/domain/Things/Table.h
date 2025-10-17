#ifndef TABLE_H
#define TABLE_H
#include "Thing.h"


class Table : public Thing {
public:
    Table(const std::string& description, int inventory_number)
        : Thing(description, inventory_number) {}
};


#endif //TABLE_H
