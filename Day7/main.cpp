#include "FileParser.hpp"
#include "EquationTester.hpp"
#include <vector>

int main()
{

    std::vector<Equation> equations;
    std::vector<std::vector<int>> equationInput;
    FileParser::parseEquationFile("example_equations.txt", equationInput);
    Equation::createEquations(equationInput, equations);
    
    auto tester = EquationTester(equations);

    

    return 0;
}