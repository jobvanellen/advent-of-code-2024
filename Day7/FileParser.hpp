#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseEquationFile(const std::string& equationFile, std::vector<std::vector<unsigned long int>>& equations);

    private:
        static std::vector<unsigned long int> parseEquation(const std::string& line);
        static std::ifstream loadFile(const std::string& filename);

        static const std::string path;
        static constexpr auto max_size  = std::numeric_limits<std::streamsize>::max();

};