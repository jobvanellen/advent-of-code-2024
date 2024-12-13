#include "FileParser.hpp"
#include "AntinodeFinder.hpp"

#include <map>
#include <set>
#include <utility>

int main()
{
    std::vector<std::vector<char>> frequencyMap;
    // FileParser::parseMap("example_map.txt", frequencyMap);
    FileParser::parseMap("frequency_map.txt", frequencyMap);

    std::map<char, std::vector<std::pair<int, int>>> antennaLocations;
    for(int i = 0; i < frequencyMap.size(); i++)
    {
        for(int j = 0; j < frequencyMap.at(i).size(); j++)
        {
            char locationSymbol = frequencyMap.at(i).at(j);
            if( locationSymbol != '.')
            {
                antennaLocations[locationSymbol].push_back({i,j});
            }
        }
    }

    AntinodeFinder antinodeFinder = AntinodeFinder(antennaLocations, frequencyMap.size(), frequencyMap.at(0).size());
    int count = antinodeFinder.countAntiNodes();    

    std::cout << count << std::endl;






    return 0;
}