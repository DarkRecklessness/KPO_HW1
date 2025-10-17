#include "ZooService.h"
#include "../Animals/Herbo.h"
#include "../Things/Thing.h"

ZooService::ZooService(std::shared_ptr<IAnimalRepository> animals,
                       std::shared_ptr<IThingRepository> things,
                       std::shared_ptr<IVeterinaryClinic> vet_clinic)
    : animal_repository(std::move(animals)),
      thing_repository(std::move(things)),
      vet_clinic(std::move(vet_clinic)) {
}

bool ZooService::AcceptNewAnimal(const std::shared_ptr<Animal>& animal) {
    if (vet_clinic->CheckHealth(animal)) {
        animal_repository->Add(animal);
        return true;
    }
    return false;
}

void ZooService::AddNewThing(const std::shared_ptr<Thing>& thing) {
    thing_repository->Add(thing);
}

std::vector<std::shared_ptr<Animal>> ZooService::GetPettingZooAnimals() const {
    std::vector<std::shared_ptr<Animal>> result;
    auto animals = animal_repository->GetAll();
    for (auto& animal : animals) {
        auto herbo = std::dynamic_pointer_cast<Herbo>(animal);
        if (herbo) {
            if (herbo->GetKindness() > 5) {
                result.emplace_back(animal);
            }
        }
    }

    return result;
}

int ZooService::CalculateTotalFoodNeeded() const {
    int total_food = 0;
    auto animals = animal_repository->GetAll();
    for (auto& animal : animals) {
        total_food += animal->GetFoodConsumptionKg();
    }

    return total_food;
}

std::vector<std::shared_ptr<IInventory>> ZooService::GetAllInventoryItems() const {
    std::vector<std::shared_ptr<IInventory>> result;
    auto animals = animal_repository->GetAll();
    auto things = thing_repository->GetAll();
    result.reserve(animals.size() + things.size());
    result.insert(result.end(), animals.begin(), animals.end());
    result.insert(result.end(), things.begin(), things.end());

    return result;
}