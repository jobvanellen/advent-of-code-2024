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
        static void parseFile(const std::string& file, std::vector<unsigned long int>& output);

    private:
        static std::ifstream loadFile(const std::string& filename);

        static const std::string path;
};