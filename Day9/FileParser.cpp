#include "FileParser.hpp"
#include <iterator>

const std::string FileParser::path = "../../Day9/files/";

void FileParser::parseDiskmap(const std::string& diskmapFile, std::vector<int>& diskmap)
{
    if(std::ifstream ifs = loadFile(path + diskmapFile))
    {
        std::string line;
        std::getline(ifs, line);

        for (char c : line)
        {
            diskmap.push_back(std::stoi(std::string{c}));
        }

        // for(int n : diskmap)
        // {
        //     std::cout << n << " ";
        // }
        // std::cout << std::endl;

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