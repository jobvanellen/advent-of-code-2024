#include "AntinodeFinder.hpp"

AntinodeFinder::AntinodeFinder(const std::map<char, std::vector<std::pair<int, int>>>& antennaLocations, int maxRow, int maxColumn)
: _antennaLocations(antennaLocations), _maxRow(maxRow), _maxColumn(maxColumn)
{}

int AntinodeFinder::countAntiNodes() const
{
    std::set<std::pair<int,int>> antinodes;
    for(auto it = _antennaLocations.begin(); it != _antennaLocations.end(); it++)
    {
        findAntinodesForAntennaType(it->second, antinodes);
    }
    return antinodes.size();
}

void AntinodeFinder::findAntinodesForAntennaType(const std::vector<std::pair<int, int>>& antennas, std::set<std::pair<int,int>>& antinodes) const
{
    for(const auto& antenna : antennas)
    {
        for(const auto& otherAntenna : antennas)
        {
            const std::pair<int,int> antinode = findAntinodeForAntennas(antenna, otherAntenna);

            if(!outOfBounds(antinode))
            {
                antinodes.insert(antinode);
            }
        }
    }
}

std::pair<int, int> AntinodeFinder::findAntinodeForAntennas(const std::pair<int,int> antenna, const std::pair<int,int> otherAntenna) const
{   
    return antenna == otherAntenna ? NO_ANTINODE : 
                                     std::make_pair(2 * antenna.first - otherAntenna.first, 2 * antenna.second - otherAntenna.second);
  
}

bool AntinodeFinder::outOfBounds(const std::pair<int,int>& location) const
{
    return location.first < 0 ||
           location.second < 0 ||
           location.first >= _maxRow ||
           location.second >= _maxColumn;
}