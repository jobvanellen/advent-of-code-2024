#include "FileParser.hpp"

int main()
{
    std::vector<std::vector<char>> frequencyMap;
    FileParser::parseMap("example_map.txt", frequencyMap);
    // FileParser::parseMap("frequency_map.txt", frequencyMap);

    return 0;
}