#include "Animal.h"

Animal::Animal(const std::string& description, int food_consumption, int inventory_number)
    : description(description),
      food_consumption(food_consumption),
      inventory_number(inventory_number) {}

int Animal::GetFoodConsumptionKg() const {
    return food_consumption;
}

int Animal::GetInventoryNumber() const {
    return inventory_number;
}

const std::string& Animal::GetDescription() const {
    return description;
}