#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseMap(const std::string& mapFile, std::vector<std::vector<char>>& map);

    private:
        static std::ifstream loadFile(const std::string& filename);
        static void printMap(const std::vector<std::vector<char>>& map);

        static const std::string path;
};