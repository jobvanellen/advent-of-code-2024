#include "FileParser.hpp"

#include <iterator>

const std::string FileParser::path = "../../Day13/files/";

void FileParser::parseMachineInfo(const std::string& file, std::vector<Machine>& machines)
{
    std::ifstream stream = loadFile(path + file);
    if (!stream) return;

    std::string line;
    while (std::getline(stream, line))
    {
        Machine machine;
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &machine.aButton.x, &machine.aButton.y);
        std::getline(stream, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &machine.bButton.x, &machine.bButton.y);
        std::getline(stream, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &machine.prizeLocation.first, &machine.prizeLocation.second);
        machines.push_back(machine);
        std::getline(stream, line); // Skip the empty line
    }

    printMachines(machines);
}

void FileParser::printMachines(const std::vector<Machine>& machines)
{
    for(const auto& machine : machines)
    {
        std::cout << "Button A: X+" << machine.aButton.x << ", Y+" << machine.aButton.y << std::endl;
        std::cout << "Button B: X+" << machine.bButton.x << ", Y+" << machine.bButton.y << std::endl;
        std::cout << "Prize: X=" << machine.prizeLocation.first << ", Y=" << machine.prizeLocation.second << std::endl;
        std::cout << std::endl;
    }
}

std::ifstream FileParser::loadFile(const std::string& filename)
{    
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return stream;
}