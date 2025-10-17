#include "ConsoleUI.h"
#include "iostream"
#include "InputHelper.h"
#include "../../domain/Animals/AllAnimals.h"


ConsoleUI::ConsoleUI(std::shared_ptr<IZoo> zoo_service,
                     std::shared_ptr<IIdGenerator> id_gen)
    : zoo_service(std::move(zoo_service)), id_gen(std::move(id_gen)) {
}

void ConsoleUI::Run() {
    int choice = 0;
    while (true) {
        ShowMenu();
        choice = InputHelper::ReadInt(" >", 0, 5);

        switch (choice) {
            case 1:
                AddAnimal();
                break;
            case 2:
                AddThing();
                break;
            case 3:
                ShowPettingZoo();
                break;
            case 4:
                CalculateFood();
                break;
            case 5:
                ShowFullInventory();
                break;
            case 0:
                std::cout << "Exiting the program..." << std::endl;
                return;
            default: break;
        }
        std::cout << "---------------------------------" << std::endl;
    }
}

void ConsoleUI::ShowMenu() {
    std::cout << "=== Please select an action: ===" << std::endl;
    std::cout << "1. Add a new animal" << std::endl;
    std::cout << "2. Add a new thing to inventory" << std::endl;
    std::cout << "3. Show petting zoo animals" << std::endl;
    std::cout << "4. Show daily food report" << std::endl;
    std::cout << "5. Show full inventory report" << std::endl;
    std::cout << "0. Exit the program" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void ConsoleUI::AddAnimal() {
    int type = InputHelper::ReadInt("Which animal to add? (1-Tiger, 2-Wolf, 3-Rabbit, 4-Monkey): ", 1, 4);

    std::string description = InputHelper::ReadString("Enter the animal's description (e.g., name/nickname): ");

    int consumption = InputHelper::ReadInt("Enter the amount of food this animal consumes per day (in kg): ", 0, INT_MAX);

    int id = id_gen->Generate();

    int kindness = 0;
    if (type > 2) {
        kindness = InputHelper::ReadInt("Enter the animal's kindness level (1-10): ", 1, 10);
    }

    std::shared_ptr<Animal> new_animal;
    switch (type) {
        case 1:
            new_animal = std::make_shared<Tiger>(description, consumption, id);
            break;
        case 2:
            new_animal = std::make_shared<Wolf>(description, consumption, id);
            break;
        case 3:
            new_animal = std::make_shared<Rabbit>(description, consumption, id, kindness);
            break;
        case 4:
            new_animal = std::make_shared<Monkey>(description, consumption, id, kindness);
            break;
        default: break;
    }

    if (zoo_service->AcceptNewAnimal(new_animal)) {
        std::cout << "The animal was successfully accepted to the zoo after a health check." << std::endl;
    } else {
        std::cout << "The veterinary clinic did not approve this animal." << std::endl;
    }
}


void ConsoleUI::AddThing() {
    int type = InputHelper::ReadInt("Which thing to add? (1-Table, 2-Computer): ", 1, 2);

    std::string description = InputHelper::ReadString("Enter the thing's description: ");

    int id = id_gen->Generate();

    std::shared_ptr<Thing> new_thing;
    switch (type) {
        case 1:
            new_thing = std::make_shared<Table>(description, id);
            break;
        case 2:
            new_thing = std::make_shared<Computer>(description, id);
            break;
        default: break;
    }

    zoo_service->AddNewThing(new_thing);

    std::cout << "\nThing '" << description << "' successfully added to inventory." << std::endl;
}

void ConsoleUI::ShowPettingZoo() {
    std::cout << "=== Animals available in the petting zoo (kindness > 5) ===" << std::endl;

    auto petting_animals = zoo_service->GetPettingZooAnimals();

    if (petting_animals.empty()) {
        std::cout << "There are no suitable animals in the petting zoo yet." << std::endl;
    } else {
        for (const auto& animal : petting_animals) {
            std::cout << "ID: " << animal->GetInventoryNumber() << " | "
                      << animal->GetDescription() << std::endl;
        }
    }
}

void ConsoleUI::CalculateFood() {
    std::cout << "Total daily food consumption in the zoo (kg): ";
    std::cout << zoo_service->CalculateTotalFoodNeeded() << std::endl;
}

void ConsoleUI::ShowFullInventory() {
    std::cout << "=== Full Inventory List ===" << std::endl;

    auto inventory_items = zoo_service->GetAllInventoryItems();

    if (inventory_items.empty()) {
        std::cout << "The zoo's inventory is empty." << std::endl;
        return;
    }

    for (const auto& item : inventory_items) {
        std::cout << "Id: " << item->GetInventoryNumber()
                  << "\t| Description: " << item->GetDescription() << std::endl;
    }
}