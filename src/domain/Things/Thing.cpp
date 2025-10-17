#include "Thing.h"

Thing::Thing(const std::string& description, int inventory_number)
        : description(description), inventory_number(inventory_number) {}

int Thing::GetInventoryNumber() const {
    return inventory_number;
}

const std::string& Thing::GetDescription() const {
    return description;
}