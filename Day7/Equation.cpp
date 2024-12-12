#include "Equation.hpp"
#include <iostream>

Equation::Equation(const std::vector<unsigned long int>& equation)
: _solution(equation.at(0)), _terms(equation.begin()+1, equation.end())
{}

bool Equation::isSolvable()  const
{
    // std::cout << _solution << ":" << std::endl;
    return tryCalculation(0, _terms.begin());
}

bool Equation::tryCalculation(unsigned long int calculationResult, std::vector<unsigned long int>::const_iterator termIter) const
{
    if(termIter == _terms.end())
    {
        // std::cout << calculationResult <<std::endl;
        return calculationResult == _solution;
    }    

    if(trySum(calculationResult, *termIter, termIter))
    {
        return true;
    }
    if(tryMultiply(calculationResult, *termIter, termIter))
    {  
        return true;
    }
    else if (tryMerge(calculationResult, termIter))
    {
        return true;
    }
    return false;
}

bool Equation::trySum(unsigned long int calculationResult, unsigned long int term, std::vector<unsigned long int>::const_iterator termIter) const
{   
    // std::cout << calculationResult << " + " << term << std::endl;
    return tryCalculation(calculationResult + term, termIter+1);
}
bool Equation::tryMultiply(unsigned long int calculationResult, unsigned long int term, std::vector<unsigned long int>::const_iterator termIter) const
{
    if(termIter == _terms.begin())
    {
        return false;
    }
    // std::cout << calculationResult << " * " << term << std::endl;
    return tryCalculation(calculationResult * term, termIter+1);
}

bool Equation::tryMerge(unsigned long int calculationResult, std::vector<unsigned long int>::const_iterator termIter) const
{
    if(termIter + 1 == _terms.end())
    {
        return false;
    }

    // std::cout << *termIter << " * " << *termIter + 1 << std::endl;

    unsigned long int combinedValue = std::stoi(std::to_string(*termIter) + std::to_string(*(termIter + 1)));

    if(trySum(calculationResult, combinedValue, termIter+1))
    {
        return true;
    }
    if(tryMultiply(calculationResult, combinedValue, termIter+1))
    {  
        return true;
    }
    return false;
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