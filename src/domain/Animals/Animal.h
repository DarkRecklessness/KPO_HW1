#ifndef ANIMAL_H
#define ANIMAL_H
#include "../Interfaces/IAlive.h"
#include "../Interfaces/IInventory.h"

class Animal : public IAlive, public IInventory {
protected:
    std::string description;
    int food_consumption;
    int inventory_number;
    Animal(const std::string& description, int food_consumption, int inventory_number);

public:
    virtual ~Animal() = default;
    int GetFoodConsumptionKg() const override;
    int GetInventoryNumber() const override;
    const std::string& GetDescription() const override;
};


#endif //ANIMAL_H
