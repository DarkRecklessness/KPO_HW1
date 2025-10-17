#ifndef IDGENERATOR_H
#define IDGENERATOR_H
#include "../Interfaces/IIdGenerator.h"


class IdGenerator : public IIdGenerator {
private:
    int id = 0;

public:
    int Generate() override {
        return ++id;
    }
};


#endif //IDGENERATOR_H
