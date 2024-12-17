#include "FileParser.hpp"
#include <iterator>

const std::string FileParser::path = "../../Day10/files/";

void FileParser::parseMap(const std::string& mapFile, std::vector<std::vector<int>>& map)
{
    if(std::ifstream ifs = loadFile(path + mapFile))
    {
        std::string line;
        while(std::getline(ifs, line))
        {
            std::vector<int> mapRow;
            for (char c : line)
            {
                mapRow.push_back(std::stoi(std::string{c}));
            }
            map.push_back(mapRow);
        }
    }
    for(const auto& mapRow : map)
    {
        for( int i : mapRow)
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