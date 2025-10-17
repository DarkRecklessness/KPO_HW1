#ifndef ITHINGREPOSITORY_H
#define ITHINGREPOSITORY_H
#include <memory>
#include <vector>
class Thing;

class IThingRepository {
public:
    virtual ~IThingRepository() = default;
    virtual void Add(const std::shared_ptr<Thing>& thing) = 0;
    virtual const std::vector<std::shared_ptr<Thing>>& GetAll() const = 0;
};


#endif //ITHINGREPOSITORY_H
