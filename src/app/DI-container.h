#ifndef DI_CONTAINER_H
#define DI_CONTAINER_H
#include <memory>
#include <unordered_map>
#include <functional>
#include <string>
#include <stdexcept>
#include <any>
#include <typeindex>
#include "../domain/Interfaces/AllInterfaces.h"
#include "../domain/Repositories/AnimalRepository.h"
#include "../domain/Repositories/ThingRepository.h"
#include "../domain/VeterinaryClinic/VeterinaryClinic.h"
#include "../domain/IdGenerator/IdGenerator.h"
#include "../domain/ZooService/ZooService.h"
#include "Console/ConsoleUI.h"


class DIContainer {
public:
    template<typename TInterface>
    void Register(std::function<std::shared_ptr<TInterface>()> factory) {
        auto type_id = std::type_index(typeid(TInterface));

        m_factories[type_id] = [factory]() {
            return factory();
        };
    }

    template<typename TInterface>
    std::shared_ptr<TInterface> Resolve() {
        auto type_id = std::type_index(typeid(TInterface));

        if (m_instances.count(type_id)) {
            return std::any_cast<std::shared_ptr<TInterface>>(m_instances.at(type_id));
        }

        if (m_factories.count(type_id)) {
            auto instance = m_factories.at(type_id)();

            m_instances[type_id] = instance;
            return std::any_cast<std::shared_ptr<TInterface>>(instance);
        }

        throw std::runtime_error("DI: Зависимость не зарегистрирована для типа: " + std::string(typeid(TInterface).name()));
    }

private:
    std::unordered_map<std::type_index, std::function<std::any()>> m_factories;
    std::unordered_map<std::type_index, std::any> m_instances;
};


void ConfigureDependencies(DIContainer& container) {
    container.Register<IAnimalRepository>([]() {
        return std::make_shared<AnimalRepository>();
    });

    container.Register<IThingRepository>([]() {
        return std::make_shared<ThingRepository>();
    });

    container.Register<IVeterinaryClinic>([]() {
        return std::make_shared<VeterinaryClinic>();
    });

    container.Register<IIdGenerator>([]() {
        return std::make_shared<IdGenerator>();
    });

    container.Register<IZoo>([&container]() {
        return std::make_shared<ZooService>(
            container.Resolve<IAnimalRepository>(),
            container.Resolve<IThingRepository>(),
            container.Resolve<IVeterinaryClinic>()
        );
    });

    container.Register<ConsoleUI>([&container]() {
        return std::make_shared<ConsoleUI>(
            container.Resolve<IZoo>(),
            container.Resolve<IIdGenerator>()
        );
    });
}

#endif //DI_CONTAINER_H
