#ifndef IALIVE_H
#define IALIVE_H


class IAlive {
public:
    virtual ~IAlive() = default;
    virtual int GetFoodConsumptionKg() const = 0;
};


#endif //IALIVE_H
