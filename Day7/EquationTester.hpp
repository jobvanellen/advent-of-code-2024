#pragma once

#include "Equation.hpp"
#include <vector>

class EquationTester
{
    public:
    EquationTester(const std::vector<Equation>& equations);

    private:
    std::vector<Equation> _equations;
};
