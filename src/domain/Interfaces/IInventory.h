#ifndef IINVENTORY_H
#define IINVENTORY_H
#include <string>

class IInventory {
public:
    virtual ~IInventory() = default;
    virtual int GetInventoryNumber() const = 0;
    virtual const std::string& GetDescription() const = 0;
};


#endif //IINVENTORY_H
