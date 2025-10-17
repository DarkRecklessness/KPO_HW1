#ifndef ANIMALREPOSITORY_H
#define ANIMALREPOSITORY_H
#include "../Interfaces/IAnimalRepository.h"


class AnimalRepository : public IAnimalRepository {
public:
    void Add(const std::shared_ptr<Animal>& animal) override;
    const std::vector<std::shared_ptr<Animal>>& GetAll() const override;

private:
    std::vector<std::shared_ptr<Animal>> animals;
};



#endif //ANIMALREPOSITORY_H
