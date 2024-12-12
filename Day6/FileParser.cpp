#include "FileParser.hpp"

const std::string FileParser::path = "../../Day6/files/";

void FileParser::parseMap(const std::string& mapFile, std::vector<std::vector<char>>& map)
{
    if(std::ifstream ifs = loadFile(path + mapFile))
    {
        std::string line;
        while (std::getline(ifs, line))
        {
            map.push_back(parseMapRow(line));
        }
    }

    std::cout << "Parsed mapfile: " << std::endl;
    for(const auto& mapRow : map )
    {
        for(char symbol : mapRow)
        {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}

std::vector<char> FileParser::parseMapRow(const std::string& line)
{
    std::vector<char> result;
    std::copy(line.begin(), line.end(), std::back_inserter(result));

    return result;
}

std::ifstream FileParser::loadFile(const std::string& filename)
{    
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return stream;
}