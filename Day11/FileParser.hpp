#pragma once

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseFile(const std::string& file, std::list<unsigned long int>& output);

    private:
        static std::ifstream loadFile(const std::string& filename);

        static const std::string path;
};