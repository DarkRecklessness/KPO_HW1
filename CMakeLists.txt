cmake_minimum_required(VERSION 3.28)
project(HW1)

set(CMAKE_CXX_STANDARD 20)

add_executable(KPO_HW1 src/app/main.cpp
        src/domain/Interfaces/IAlive.h
        src/domain/Interfaces/IInventory.h
        src/domain/Interfaces/IVeterinaryClinic.h
        src/domain/Interfaces/IAnimalRepository.h
        src/domain/Interfaces/IThingRepository.h
        src/domain/Interfaces/IZoo.h
        src/domain/Animals/Animal.cpp
        src/domain/Animals/Animal.h
        src/domain/Animals/Predator.h
        src/domain/Animals/Herbo.cpp
        src/domain/Animals/Herbo.h
        src/domain/Animals/Rabbit.h
        src/domain/Animals/Monkey.h
        src/domain/Animals/Tiger.h
        src/domain/Animals/Wolf.h
        src/domain/Things/Thing.cpp
        src/domain/Things/Thing.h
        src/domain/Things/Table.h
        src/domain/Things/Computer.h
        src/domain/VeterinaryClinic/VeterinaryClinic.h
        src/domain/Repositories/AnimalRepository.cpp
        src/domain/Repositories/AnimalRepository.h
        src/domain/Repositories/ThingRepository.cpp
        src/domain/Repositories/ThingRepository.h
        src/domain/ZooService/ZooService.cpp
        src/domain/ZooService/ZooService.h
        src/app/Console/ConsoleUI.cpp
        src/app/Console/ConsoleUI.h
        src/app/Console/InputHelper.h
        src/domain/Interfaces/IIdGenerator.h
        src/domain/IdGenerator/IdGenerator.h
        src/domain/Animals/AllAnimals.h
        src/app/DI-container.h
        src/domain/Interfaces/AllInterfaces.h
)