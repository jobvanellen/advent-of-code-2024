#include "EquationTester.hpp"
#include <iostream>

EquationTester::EquationTester(const std::vector<Equation>& equations)
: _equations(equations)
{}

unsigned long int EquationTester::getTotalCalibrationResult() const
{
    unsigned long int totalCalibrationResult = 0;
    for(const auto& equation : _equations)
    {
        totalCalibrationResult += getCalibrationResult(equation);
    }
    return totalCalibrationResult;
}

unsigned long int EquationTester::getCalibrationResult(const Equation& equation) const
{   
    if(equation.isSolvable())
    {
        std::cout << equation.solution() << " OK!" << std::endl;
        return equation.solution();
    }
    else
    {
        std::cout << equation.solution() << " NOK" << std::endl;
    }
    return 0;
}