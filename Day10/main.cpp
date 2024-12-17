#include "FileParser.hpp"
#include "TrailFinder.hpp"

#include <map>
#include <set>
#include <utility>

int main()
{
    std::vector<std::vector<int>> map;
    FileParser::parseMap("example_map.txt", map);

    // FileParser::parseMap("map.txt", map);

    TrailFinder trailFinder = TrailFinder::createTrailFinder(map);
    

    return 0;
}