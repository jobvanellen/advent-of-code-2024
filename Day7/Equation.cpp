#include "Equation.hpp"

Equation::Equation(const std::vector<int>& equation)
: solution(equation.at(0)), terms(equation.begin()+1, equation.end())
{}

void Equation::createEquations(const std::vector<std::vector<int>>& equationInput, std::vector<Equation>& equationOutput)
{
    for(const auto& in : equationInput)
    {
        equationOutput.push_back(Equation(in));
    }
}
