#include "FileParser.hpp"
#include <iterator>

const std::string FileParser::path = "../../Day12/files/";

void FileParser::parseMap(const std::string& mapFile, std::vector<std::vector<char>>& map)
{
    if(std::ifstream ifs = loadFile(path + mapFile))
    {
        std::string line;
        while(std::getline(ifs, line))
        {
            std::vector<char> mapRow;
            for (char c : line)
            {
                mapRow.push_back(c);
            }
            map.push_back(mapRow);
        }
    }

    // printMap(map);
}

void FileParser::printMap(const std::vector<std::vector<char>>& map)
{
    for(const auto& mapRow : map)
    {
        for( char i : mapRow)
        {
            std::cout << i;
        }
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