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
        static void parseMap(const std::string& mapFile, std::vector<std::vector<int>>& map);

    private:
        static std::ifstream loadFile(const std::string& filename);

        static const std::string path;
};