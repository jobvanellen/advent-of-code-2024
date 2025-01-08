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

    long long int cost = 0;

    for(long long int i = 0; i < 100; i++)
    {
        for(long long int j = 0; j < 100; j++)
        {
            long long int xAttempt = i * aButton.x + j * bButton.x;
            long long int yAttempt = i * aButton.y + j * bButton.y;
            long long int attemptCost = i * machine.aButton.cost + j * machine.bButton.cost;

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

long long int beSmartAboutPrizeCost(const Machine& machine)
{
    long long int ax = machine.aButton.x;
    long long int ay = machine.aButton.y;

    long long int bx = machine.bButton.x;
    long long int by = machine.bButton.y;
    
    long long int tx = machine.prizeLocation.first;
    long long int ty = machine.prizeLocation.second;

    long long int aCost = machine.aButton.cost;
    long long int bCost = machine.bButton.cost;

    long long int b = (tx * ay - ty * ax) / (ay * bx - by * ax);
    long long int a = (tx * by - ty * bx) / (by * ax - bx * ay);

    return (ax * a + bx * b == tx && ay * a + by * b == ty) ? (a * aCost + b * bCost) : 0;
}

void prepPart2(std::vector<Machine>& machines)
{
    for(auto& machine : machines)
    {
        machine.prizeLocation.first += 10000000000000;
        machine.prizeLocation.second += 10000000000000;
    }
}



int main()
{
    // std::string file = "example_machines.txt";
    std::string file = "machines.txt";

    std::vector<Machine> machines;
    FileParser::parseMachineInfo(file, machines);
    
    prepPart2(machines);

    long long int totalCost = 0;
    for(const auto& machine : machines)
    {        
        totalCost += beSmartAboutPrizeCost(machine);
    }

    std::cout << "Total cost: " << totalCost << std::endl;

    return 0;
}