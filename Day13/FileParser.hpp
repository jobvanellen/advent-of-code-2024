#pragma once

#include "Machine.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseMachineInfo(const std::string& file, std::vector<Machine>& machines);

    private:
        static std::ifstream loadFile(const std::string& filename);
        static void printMachines(const std::vector<Machine>& machines);

        static const std::string path;
};