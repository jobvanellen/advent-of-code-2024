#pragma once
#include <map>
#include <set>
#include <utility>
#include <vector>

class AntinodeFinder
{
    public:
    AntinodeFinder(const std::map<char, std::vector<std::pair<int, int>>>& antennaLocations, int maxRow, int maxColumn);
    int countAntiNodes() const;

    private:
    void findAntinodesForAntennaType(const std::vector<std::pair<int, int>>& antennas ,std::set<std::pair<int,int>>& antiNodes) const;
    std::pair<int, int> findAntinodeForAntennas(const std::pair<int,int> antenna, const std::pair<int,int> otherAntenna) const;
    bool outOfBounds(const std::pair<int,int>& location) const; 

    const std::map<char, std::vector<std::pair<int, int>>>& _antennaLocations;
    const int _maxRow, _maxColumn;

    const std::pair<int,int> NO_ANTINODE = {-1,-1};
};