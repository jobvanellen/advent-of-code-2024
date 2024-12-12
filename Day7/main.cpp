#include "FileParser.hpp"
#include "EquationTester.hpp"
#include <vector>

int main()
{

    std::vector<Equation> equations;
    std::vector<std::vector<unsigned long int>> equationInput;
    // FileParser::parseEquationFile("example_equations.txt", equationInput);
    FileParser::parseEquationFile("equations.txt", equationInput);
    Equation::createEquations(equationInput, equations);
    
    auto tester = EquationTester(equations);

    unsigned long int totalCalibrationResult = tester.getTotalCalibrationResult();

    std::cout << totalCalibrationResult << std::endl;

    return 0;
}