#include "Equation.hpp"

Equation::Equation(const std::vector<unsigned long int>& equation)
: _solution(equation.at(0)), _terms(equation.begin()+1, equation.end())
{}

bool Equation::isSolvable()  const
{
    return tryCalculation(_terms.at(0), _terms.begin());
}

bool Equation::tryCalculation(unsigned long int calculationResult, std::vector<int>::const_iterator termIter) const
{
    if(termIter + 1 == _terms.end())
    {
        return calculationResult == _solution;
    }    

    if(trySum(calculationResult, termIter + 1))
    {
        return true;
    }
    if(tryMultiply(calculationResult, termIter + 1))
    {  
        return true;
    }
    else if (tryConcatenate(calculationResult, termIter + 1))
    {
        return true;
    }
    return false;
}

bool Equation::trySum(unsigned long int calculationResult, std::vector<int>::const_iterator termIter) const
{       
    unsigned long int sum = calculationResult + *termIter;
    return tryCalculation(sum, termIter);
}
bool Equation::tryMultiply(unsigned long int calculationResult, std::vector<int>::const_iterator termIter) const
{
    unsigned long int product = calculationResult * *termIter;
    return tryCalculation(product, termIter);
}

bool Equation::tryConcatenate(unsigned long int calculationResult, std::vector<int>::const_iterator termIter) const
{
    unsigned long int combinedValue = std::stol(std::to_string(calculationResult) + std::to_string(*termIter));
    return tryCalculation(combinedValue, termIter);
}

unsigned long int Equation::solution() const
{
    return _solution;
}

void Equation::createEquations(const std::vector<std::vector<unsigned long int>>& equationInput, std::vector<Equation>& equationOutput)
{
    for(const auto& in : equationInput)
    {
        equationOutput.push_back(Equation(in));
    }
}