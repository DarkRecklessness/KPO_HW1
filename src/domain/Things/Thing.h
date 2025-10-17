#ifndef THING_H
#define THING_H
#include "../Interfaces/IInventory.h"


class Thing : public IInventory {
protected:
    std::string description;
    int inventory_number;
    Thing(const std::string& description, int inventory_number);

public:
    virtual ~Thing() = default;
    int GetInventoryNumber() const override;
    const std::string& GetDescription() const override;
};


#endif //THING_H
