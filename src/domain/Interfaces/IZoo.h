#ifndef IZOO_H
#define IZOO_H
#include <vector>
#include <memory>
class Animal;
class Thing;
class IInventory;


class IZoo {
public:
    virtual ~IZoo() = default;
    virtual bool AcceptNewAnimal(const std::shared_ptr<Animal>& animal) = 0;
    virtual void AddNewThing(const std::shared_ptr<Thing>& thing) = 0;
    virtual std::vector<std::shared_ptr<Animal>> GetPettingZooAnimals() const = 0;
    virtual int CalculateTotalFoodNeeded() const = 0;
    virtual std::vector<std::shared_ptr<IInventory>> GetAllInventoryItems() const = 0;
};


#endif //IZOO_H
