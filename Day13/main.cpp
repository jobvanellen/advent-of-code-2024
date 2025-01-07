#include "FileParser.hpp"
#include "Machine.hpp"

#include <map>
#include <vector>
#include <iostream>

int main()
{
    std::string file = "example_machines.txt";
    // std::string file = "machines.txt";

    std::vector<Machine> machines;
    FileParser::parseMachineInfo(file, machines);


    return 0;
}