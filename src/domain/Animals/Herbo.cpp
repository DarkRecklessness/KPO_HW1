#include "Herbo.h"

Herbo::Herbo(const std::string& description, int food_consumption, int inventory_number, int kindness)
    : Animal(description, food_consumption, inventory_number), kindness(kindness) {}

int Herbo::GetKindness() const {
    return kindness;
}