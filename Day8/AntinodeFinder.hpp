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
    void findAllAntiNodes(std::set<std::pair<int,int>>& antinodes) const;
    void findAntinodesForAntennaType(const std::vector<std::pair<int, int>>& antennas, std::set<std::pair<int,int>>& antiNodes) const;
    void findAntinodesForAntennas(const std::pair<int,int> antenna, const std::pair<int,int> otherAntenna, std::set<std::pair<int,int>>& antinodes) const;
    bool outOfBounds(const std::pair<int,int>& location) const; 

    void printAntiNodes(const std::set<std::pair<int,int>>& antinodes) const;
    char getSymbol(const std::set<std::pair<int,int>>& antinodes, int row, int column) const;

    const std::map<char, std::vector<std::pair<int, int>>>& _antennaLocations;
    const int _maxRow, _maxColumn;

    const std::pair<int,int> NO_ANTINODE = {-1,-1};
};