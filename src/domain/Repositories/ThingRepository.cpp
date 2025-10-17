#include "ThingRepository.h"

void ThingRepository::Add(const std::shared_ptr<Thing>& thing) {
    things.emplace_back(thing);
}

const std::vector<std::shared_ptr<Thing>>& ThingRepository::GetAll() const {
    return things;
}