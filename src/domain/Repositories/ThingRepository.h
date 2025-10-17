#ifndef THINGREPOSITORY_H
#define THINGREPOSITORY_H
#include "../Interfaces/IThingRepository.h"


class ThingRepository : public IThingRepository {
public:
    void Add(const std::shared_ptr<Thing>& thing) override;
    const std::vector<std::shared_ptr<Thing>>& GetAll() const override;
private:
    std::vector<std::shared_ptr<Thing>> things;
};



#endif //THINGREPOSITORY_H
