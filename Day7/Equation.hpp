#pragma once
#include <vector>
#include <string>

class Equation
{
    public:
    Equation(const std::vector<unsigned long int>& equation);

    bool isSolvable() const;
    unsigned long int solution() const;
    static void createEquations(const std::vector<std::vector<unsigned long int>>& equationInput, std::vector<Equation>& equationOutput);

    private:
    bool tryCalculation(unsigned long int calculationResult, std::vector<int>::const_iterator termIter) const;

    bool trySum(unsigned long int currentResult, std::vector<int>::const_iterator termIter) const;
    bool tryMultiply(unsigned long int currentResult, std::vector<int>::const_iterator termIter) const;
    bool tryConcatenate(unsigned long int currentResult, std::vector<int>::const_iterator termIter) const;

    const unsigned long int _solution;
    const std::vector<int> _terms;
    

};

