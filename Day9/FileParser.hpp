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
        static void parseDiskmap(const std::string& diskmapFile, std::vector<int>& diskmap);

    private:
        static std::ifstream loadFile(const std::string& filename);

        static const std::string path;
};