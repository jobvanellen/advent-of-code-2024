#pragma once

#include "Equation.hpp"
#include <vector>

class EquationTester
{
    public:
    EquationTester(const std::vector<Equation>& equations);
    unsigned long int getTotalCalibrationResult() const;

    private:
    unsigned long int getCalibrationResult(const Equation& equation) const;

    const std::vector<Equation>& _equations;
};
