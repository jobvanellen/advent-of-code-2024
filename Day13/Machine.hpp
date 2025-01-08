#pragma once

#include <utility>

struct Button
{
    int x;
    int y;
    int cost;
};

struct Machine
{
    Machine(){ aButton.cost = 3; bButton.cost = 1; }
    Button aButton;
    Button bButton;
    std::pair<int,int> prizeLocation;
};