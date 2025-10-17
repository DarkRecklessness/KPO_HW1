#include "AnimalRepository.h"

void AnimalRepository::Add(const std::shared_ptr<Animal>& animal) {
    animals.emplace_back(animal);
}

const std::vector<std::shared_ptr<Animal>>& AnimalRepository::GetAll() const {
    return animals;
}