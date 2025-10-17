#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "../../domain/Interfaces/IZoo.h"
#include "../../domain/Interfaces/IIdGenerator.h"

class ConsoleUI {
public:
    ConsoleUI(std::shared_ptr<IZoo> zoo_service, std::shared_ptr<IIdGenerator> id_gen);
    void Run();

private:
    std::shared_ptr<IZoo> zoo_service;
    std::shared_ptr<IIdGenerator> id_gen;

    void ShowMenu();
    void AddAnimal();
    void AddThing();
    void ShowPettingZoo();
    void CalculateFood();
    void ShowFullInventory();
};


#endif //CONSOLEUI_H
