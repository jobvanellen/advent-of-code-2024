#include "FileParser.hpp"
#include "GuardTracer.hpp"

int main()
{
    
    std::vector<std::vector<char>> map;

    FileParser::parseMap("map.txt", map);
    // FileParser::parseMap("example_map.txt", map);

    GuardTracer guardTracer(map);

    int count = guardTracer.countVisitedPositions();

    std::cout << "Amount of positions visited: " << count << std::endl;

    count = guardTracer.countLoopCausingObstaclePositions();
    std::cout << "Amount of loop causing obstacles: " << count << std::endl;
    return 0;
}