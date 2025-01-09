#pragma once

#include "Robot.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseRobotInfo(const std::string& file, std::vector<Robot>& robots, int lx, int ly);

    private:
        static std::ifstream loadFile(const std::string& filename);
        static void printRobots(const std::vector<Robot>& robots);

        static const std::string path;
};