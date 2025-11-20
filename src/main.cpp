#include "../RacesLib/include/Race.h"
#include "../RacesLib/include/Camel.h"
#include "../RacesLib/include/FastCamel.h"
#include "../RacesLib/include/Centaur.h"
#include "../RacesLib/include/Boots.h"
#include "../RacesLib/include/Carpet.h"
#include "../RacesLib/include/Eagle.h"
#include "../RacesLib/include/Broom.h"

#include <iostream>
#include <vector>
#include <memory>

int main() 
{
    while (true) 
    {
        std::cout << "\n=== Симулятор гонок ===\n";
        std::cout << "Выберите тип гонки:\n";
        std::cout << "1. Наземная (только наземные ТС)\n";
        std::cout << "2. Воздушная (только воздушные ТС)\n";
        std::cout << "3. Смешанная (наземные + воздушные ТС)\n";

        int raceTypeChoice;
        std::cin >> raceTypeChoice;

        Race::Type raceType;
        switch (raceTypeChoice) 
        {
        case 1: raceType = Race::Type::Ground; break;
        case 2: raceType = Race::Type::Air; break;
        case 3: raceType = Race::Type::Mixed; break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }

        double distance;
        std::cout << "Введите дистанцию гонки (км): ";
        std::cin >> distance;

        if (distance <= 0) 
        {
            std::cout << "Дистанция должна быть положительной!\n";
            continue;
        }

        Race race(raceType, distance);
        std::vector<std::unique_ptr<Transport>> registeredTransports;

        std::cout << "\nРегистрация ТС. Минимум 2 участника.\n";

        while (true) 
        {
            std::cout << "\nДоступные действия:\n";
            std::cout << "1. Зарегистрировать ТС\n";
            std::cout << "2. Начать гонку\n";

            int action;
            std::cin >> action;

            if (action == 1) 
            {
                std::cout << "\nВыберите ТС для регистрации:\n";
                std::cout << "1. Верблюд (наземный)\n";
                std::cout << "2. Верблюд-быстроход (наземный)\n";
                std::cout << "3. Кентавр (наземный)\n";
                std::cout << "4. Ботинки-вездеходы (наземный)\n";
                std::cout << "5. Ковёр-самолёт (воздушный)\n";
                std::cout << "6. Орёл (воздушный)\n";
                std::cout << "7. Метла (воздушный)\n";

                int transportChoice;
                std::cin >> transportChoice;

                std::unique_ptr<Transport> newTransport;

                switch (transportChoice) 
                {
                case 1: newTransport = std::make_unique<Camel>(); break;
                case 2: newTransport = std::make_unique<FastCamel>(); break;
                case 3: newTransport = std::make_unique<Centaur>(); break;
                case 4: newTransport = std::make_unique<Boots>(); break;
                case 5: newTransport = std::make_unique<Carpet>(); break;
                case 6: newTransport = std::make_unique<Eagle>(); break;
                case 7: newTransport = std::make_unique<Broom>(); break;
                default:
                    std::cout << "Неверный выбор ТС. Попробуйте снова.\n";
                    continue;
                }

                if (race.registerTransport(newTransport.get())) 
                {
                    registeredTransports.push_back(std::move(newTransport));
                    std::cout << newTransport->getName() << " успешно зарегистрирован!\n";
                }
                else 
                {
                    std::cout << "Ошибка регистрации ТС:\n";
                    std::cout << "- Возможно, ТС уже зарегистрировано\n";
                    std::cout << "- Или тип ТС не соответствует типу гонки\n";
                }
            }
            else if (action == 2) 
            {
                if (registeredTransports.size() < 2) 
                {
                    std::cout << "Необходимо зарегистрировать минимум 2 ТС!\n";
                    continue;
                }

                auto results = race.start();

                std::cout << "\n=== Результаты гонки ===\n";
                for (const auto& result : results) 
                {
                    std::cout << result.name << ": " << result.time << " ч\n";
                }

                std::cout << "\nХотите провести ещё одну гонку?\n";
                std::cout << "1. Да\n2. Нет (выход)\n";
                int nextAction;
                std::cin >> nextAction;

                if (nextAction != 1) 
                {
                    std::cout << "До свидания!\n";
                    return 0;
                }
                else 
                {
                    registeredTransports.clear();
                    break;
                }
            }
            else {
                std::cout << "Неверный выбор действия. Попробуйте снова.\n";
            }
        }
    }

    return EXIT_SUCCESS;
}
