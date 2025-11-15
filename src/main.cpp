#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "Transport.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Centaur.h"
#include "Boots.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Broom.h"
#include "RaceManager.h"

RaceType chooseRaceType();
double getDistance();
void registerParticipants(Race& race);
void displayResults(const std::vector<ParticipantResult>& results);
bool askToContinue();

int main() {
    while (true) {
        RaceType raceType = chooseRaceType();

        double distance = getDistance();

        auto race = RaceManager::createRace(raceType, distance);

        registerParticipants(*race);

        auto results = race->run();
        displayResults(results);

        if (!askToContinue()) break;
    }
    return 0;
}

RaceType chooseRaceType() 
{
    std::cout << "\nВыберите тип гонки:\n";
    std::cout << "1. Наземная (только наземные ТС)\n";
    std::cout << "2. Воздушная (только воздушные ТС)\n";
    std::cout << "3. Смешанная (все ТС)\n";
    int choice;
    std::cin >> choice;

    switch (choice) 
    {
    case 1: return RaceType::LAND;
    case 2: return RaceType::AIR;
    case 3: return RaceType::MIXED;
    default:
    {
        std::cout << "Неверный выбор, попробуйте снова.\n";
        return chooseRaceType();
    }
    }
}

double getDistance() 
{
    double distance;
    std::cout << "\nВведите дистанцию гонки (км): ";
    std::cin >> distance;
    return distance;
}

void registerParticipants(Race& race) 
{
    std::set<std::string> registeredNames;
    std::vector<std::string> availableTransports = 
    {
        "Верблюд", "Верблюд-быстроход", "Кентавр", "Ботинки-вездеходы",
        "Ковёр-самолёт", "Орёл", "Метла"
    };

    while (true) 
    {
        std::cout << "\nДоступные ТС для регистрации:\n";
        for (const auto& name : availableTransports) 
        {
            if (registeredNames.find(name) == registeredNames.end()) 
            { std::cout << "- " << name << "\n"; }
        }

        std::cout << "\nВведите название ТС для регистрации (или 'старт' для начала гонки): ";
        std::string name;
        std::cin >> name;

        if (name == "старт") 
        {
            if (race.participants.size() < 2) 
            {
                std::cout << "Нужно зарегистрировать минимум 2 ТС!\n";
                continue;
            }
            break;
        }

        bool found = false;
        for (const auto& avail : availableTransports) 
        {
            if (avail == name) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            std::cout << "ТС не найдено!\n";
            continue;
        }

        if (registeredNames.find(name) != registeredNames.end()) 
        {
            std::cout << "Это ТС уже зарегистрировано!\n";
            continue;
        }

        std::unique_ptr<Transport> transport;
        if (name == "Верблюд") transport = std::make_unique<Camel>();
        else if (name == "Верблюд-быстроход") transport = std::make_unique<CamelFast>();
        else if (name == "Кентавр") transport = std::make_unique<Centaur>();
        else if (name == "Ботинки-вездеходы") transport = std::make_unique<Boots>();
        else if (name == "Ковёр-самолёт") transport = std::make_unique<Carpet>();
        else if (name == "Орёл") transport = std::make_unique<Eagle>();
        else if (name == "Метла") transport = std::make_unique<Broom>();

        if (!RaceManager::isValidParticipant(*transport, race.type)) 
        {
            std::cout << "Нельзя зарегистрировать это ТС в данной гонке!\n";
            continue;
        }

        race.addParticipant(std::move(transport));
        registeredNames.insert(name);
        std::cout << name << " зарегистрирован!\n";
    }
}

void displayResults(const std::vector<ParticipantResult>& results) 
{
    std::cout << "\nРезультаты гонки:\n";
    for (const auto& result : results) 
    {
        std::cout << result.name << ": "
            << std::fixed << std::setprecision(2) << result.time
            << " ч\n";
    }
}

bool askToContinue() 
{
    std::cout << "\nХотите провести ещё одну гонку? (да/нет): ";
    std::string choice;
    std::cin >> choice;
    return (choice == "да" || choice == "yes" || choice == "y");
}
