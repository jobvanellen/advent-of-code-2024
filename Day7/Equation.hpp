#pragma once
#include <vector>

struct Equation
{
    public:
    Equation(const std::vector<int>& equation);

    const int solution;
    const std::vector<int> terms;

    static void createEquations(const std::vector<std::vector<int>>& equationInput, std::vector<Equation>& equationOutput);
};

