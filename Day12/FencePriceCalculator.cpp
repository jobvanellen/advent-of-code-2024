#include "FencePriceCalculator.hpp"
#include <iostream>
#include <set>
#include <algorithm>

FencePriceCalculator::FencePriceCalculator(const std::vector<std::vector<char>>& map)
: _map(map)
{}

int FencePriceCalculator::calculateFencingPrice()
{
    int totalPrice = 0;
    for(int i = 0; i < _map.size(); i++)
    {
        for(int j = 0; j < _map.at(i).size(); j++)
        {
            if(std::find(_processedPlots.begin(), _processedPlots.end(), std::make_pair(i,j)) == _processedPlots.end())
            {
                totalPrice += calculateRegionPrice(i,j);
            }
        }
    }

    return totalPrice;
}

int FencePriceCalculator::calculateRegionPrice(int startRow, int startColumn)
{
    std::set<std::pair<int,int>> regionPlots;

    _regionPerimeter = 0;
    _regionCorners = 0;

    addAdjacentPlots(startRow, startColumn, regionPlots);

    // std::cout << "Region size: " << regionSize << std::endl;
    // std::cout << "Region perimeter: " << _regionPerimeter << std::endl;
    // std::cout << "Region price: " << regionSize * _regionPerimeter << std::endl;

    for(const auto& plot : regionPlots)
    {
        _processedPlots.insert(plot);
    }

    // return regionPlots.size() * _regionPerimeter;
    return regionPlots.size() * _regionCorners;
}

void FencePriceCalculator::addAdjacentPlots(int row, int column, std::set<std::pair<int,int>>& plots)
{
    if(!plots.emplace(row,column).second)
    {
        return;
    }

    const char type = _map.at(row).at(column);
    //                                                  up, down, left, right
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<bool> edges;

    for (const auto& direction : directions)
    {
        int newRow = row + direction.first;
        int newColumn = column + direction.second;

        if (newRow >= 0 && newRow < _map.size() && newColumn >= 0 && newColumn < _map.at(newRow).size())
        {
            if (_map.at(newRow).at(newColumn) == type) 
            {
                addAdjacentPlots(newRow, newColumn, plots);
                edges.push_back(false);
            }
            else
            {
                edges.push_back(true);
                _regionPerimeter++;
            }
        }
        else
        {
            edges.push_back(true);
            _regionPerimeter++;
        }
    }

    findOuterCorners(edges);
    findInnerCorners(edges, row, column, type);
}

void FencePriceCalculator::findOuterCorners(const std::vector<bool>& edges)
{
    if(edges.at(0) && edges.at(2))
    {
        _regionCorners++;
    }
    if(edges.at(0) && edges.at(3))
    {
        _regionCorners++;
    }
    if(edges.at(1) && edges.at(2))
    {
        _regionCorners++;
    }
    if(edges.at(1) && edges.at(3))
    {
        _regionCorners++;
    }
}

void FencePriceCalculator::findInnerCorners(const std::vector<bool>& edges, int row, int column, char type)
{
    if(!edges.at(0) && !edges.at(2))
    {
        std::pair<int,int> diagonal = (std::make_pair(row-1,column-1));
        if(_map.at(diagonal.first).at(diagonal.second) != type)
        {
            _regionCorners++;
        }
    }

    if(!edges.at(0) && !edges.at(3))
    {
        std::pair<int,int> diagonal = (std::make_pair(row-1,column+1));
        if(_map.at(diagonal.first).at(diagonal.second) != type)
        {
            _regionCorners++;
        }
    }

    if(!edges.at(1) && !edges.at(2))
    {
        std::pair<int,int> diagonal = (std::make_pair(row+1,column-1));
        if(_map.at(diagonal.first).at(diagonal.second) != type)
        {
            _regionCorners++;
        }
    }

    if(!edges.at(1) && !edges.at(3))
    {
        std::pair<int,int> diagonal = (std::make_pair(row+1,column+1));
        if(_map.at(diagonal.first).at(diagonal.second) != type)
        {
            _regionCorners++;
        }
    }
}


