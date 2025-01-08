#include "FileParser.hpp"
#include "Machine.hpp"

#include <map>
#include <vector>
#include <iostream>

int bruteForcePrizeCost(const Machine& machine)
{
    const auto& prizeLocation = machine.prizeLocation;
    const auto& aButton = machine.aButton;
    const auto& bButton = machine.bButton;

    int cost = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            int xAttempt = i * aButton.x + j * bButton.x;
            int yAttempt = i * aButton.y + j * bButton.y;
            int attemptCost = i * machine.aButton.cost + j * machine.bButton.cost;

            if (xAttempt == prizeLocation.first && yAttempt == prizeLocation.second)
            {
                cost = attemptCost < cost || cost == 0 ? attemptCost : cost;
            }
            else if (xAttempt > prizeLocation.first || yAttempt > prizeLocation.second)
            {
                break;
            }
        }
    }
    return cost;
}

int main()
{
    // std::string file = "example_machines.txt";
    std::string file = "machines.txt";

    std::vector<Machine> machines;
    FileParser::parseMachineInfo(file, machines);

    int totalCost = 0;
    for(const auto& machine : machines)
    {
        totalCost += bruteForcePrizeCost(machine);
    }

    std::cout << "Total cost: " << totalCost << std::endl;

    return 0;
}