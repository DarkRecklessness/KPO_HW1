#ifndef IIDGENERATOR_H
#define IIDGENERATOR_H


class IIdGenerator {
public:
    ~IIdGenerator() = default;
    virtual int Generate() = 0;
};


#endif //IIDGENERATOR_H
