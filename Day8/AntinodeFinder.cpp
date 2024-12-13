#include "AntinodeFinder.hpp"
#include <iostream>
#include <ranges>

AntinodeFinder::AntinodeFinder(const std::map<char, std::vector<std::pair<int, int>>>& antennaLocations, int maxRow, int maxColumn)
: _antennaLocations(antennaLocations), _maxRow(maxRow), _maxColumn(maxColumn)
{}

int AntinodeFinder::countAntiNodes() const
{
    std::set<std::pair<int,int>> antinodes;
    
    findAllAntiNodes(antinodes);
    printAntiNodes(antinodes);

    return antinodes.size();
}

void AntinodeFinder::findAllAntiNodes(std::set<std::pair<int,int>>& antinodes) const
{
    for(auto it = _antennaLocations.begin(); it != _antennaLocations.end(); it++)
    {
        findAntinodesForAntennaType(it->second, antinodes);
    }
}

void AntinodeFinder::findAntinodesForAntennaType(const std::vector<std::pair<int, int>>& antennas, std::set<std::pair<int,int>>& antinodes) const
{
    for(const auto& antenna : antennas)
    {
        for(const auto& otherAntenna : antennas)
        {
            if(antenna != otherAntenna)
            {
                findAntinodesForAntennas(antenna, otherAntenna, antinodes);
            }            
        }
    }
}

void AntinodeFinder::findAntinodesForAntennas(const std::pair<int,int> antenna, const std::pair<int,int> otherAntenna, std::set<std::pair<int,int>>& antinodes) const
{
    int rowDelta = antenna.first - otherAntenna.first;
    int columnDelta = antenna.second - otherAntenna.second;

    std::pair<int,int> antinode = antenna;

    while(!outOfBounds(antinode))
    {
        antinodes.insert(antinode);
        antinode.first += rowDelta;
        antinode.second += columnDelta;
    }            
}

bool AntinodeFinder::outOfBounds(const std::pair<int,int>& location) const
{
    return location.first < 0 ||
           location.second < 0 ||
           location.first >= _maxRow ||
           location.second >= _maxColumn;
}

void AntinodeFinder::printAntiNodes(const std::set<std::pair<int,int>>& antinodes) const
{
    for(int i = 0; i < _maxRow; i++)
    {
        for(int j = 0; j < _maxColumn; j++)
        {
           
            std::cout << getSymbol(antinodes, i,j);
        }
        std::cout << std::endl;
    }
}

char AntinodeFinder::getSymbol(const std::set<std::pair<int,int>>& antinodes, int row, int column) const
{
    char symbol = antinodes.find({row, column}) == antinodes.end() ? '.' : '#';
    for(const auto& antennaType : _antennaLocations)
    {
        for(const auto& antenna : antennaType.second)
        {
            if(antenna == std::make_pair(row, column))
            {
                symbol = antennaType.first;
            }
        }
    }
    return symbol;
}
