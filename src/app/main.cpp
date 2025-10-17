#include "DI-container.h"

int main() {
    DIContainer container;
    ConfigureDependencies(container);

    auto application = container.Resolve<ConsoleUI>();
    application->Run();
}