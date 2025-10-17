#ifndef IVETERINARYCLINIC_H
#define IVETERINARYCLINIC_H
#include <memory>
class Animal;


class IVeterinaryClinic {
public:
    virtual ~IVeterinaryClinic() = default;
    virtual bool CheckHealth(const std::shared_ptr<Animal>& animal) const = 0;
};


#endif //IVETERINARYCLINIC_H
