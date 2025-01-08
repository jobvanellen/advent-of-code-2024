#pragma once

#include <utility>

struct Button
{
    long long int x;
    long long int y;
    long long int cost;
};

struct Machine
{
    Machine(){ aButton.cost = 3; bButton.cost = 1; }
    Button aButton;
    Button bButton;
    std::pair<long long int,long long int> prizeLocation;
};