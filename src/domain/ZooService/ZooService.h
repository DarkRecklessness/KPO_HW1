#ifndef ZOOSERVICE_H
#define ZOOSERVICE_H
#include "../Interfaces/IZoo.h"
#include "../Interfaces/IAnimalRepository.h"
#include "../Interfaces/IThingRepository.h"
#include "../Interfaces/IVeterinaryClinic.h"


class ZooService : public IZoo {
public:
    ZooService(std::shared_ptr<IAnimalRepository> animals,
               std::shared_ptr<IThingRepository> things,
               std::shared_ptr<IVeterinaryClinic> vet_clinic);
    bool AcceptNewAnimal(const std::shared_ptr<Animal>& animal) override;
    void AddNewThing(const std::shared_ptr<Thing>& thing) override;
    std::vector<std::shared_ptr<Animal>> GetPettingZooAnimals() const override;
    int CalculateTotalFoodNeeded() const override;
    std::vector<std::shared_ptr<IInventory>> GetAllInventoryItems() const override;

private:
    std::shared_ptr<IAnimalRepository> animal_repository;
    std::shared_ptr<IThingRepository> thing_repository;
    std::shared_ptr<IVeterinaryClinic> vet_clinic;
};


#endif //ZOOSERVICE_H
