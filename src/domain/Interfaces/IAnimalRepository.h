#ifndef IANIMALREPOSITORY_H
#define IANIMALREPOSITORY_H
#include <memory>
#include <vector>
class Animal;


class IAnimalRepository {
public:
    virtual ~IAnimalRepository() = default;
    virtual void Add(const std::shared_ptr<Animal>& animal) = 0;
    virtual const std::vector<std::shared_ptr<Animal>>& GetAll() const = 0;
};


#endif //IANIMALREPOSITORY_H
