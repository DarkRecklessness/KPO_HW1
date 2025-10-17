#ifndef VETERINARYCLINIC_H
#define VETERINARYCLINIC_H
#include "../Animals/Animal.h"
#include "../Interfaces/IVeterinaryClinic.h"

class VeterinaryClinic : public IVeterinaryClinic {
public:
    bool CheckHealth(const std::shared_ptr<Animal>& animal) const override {
        return animal->GetFoodConsumptionKg() >= 1;
    }
};


#endif //VETERINARYCLINIC_H
