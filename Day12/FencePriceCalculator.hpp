#pragma once

#include <vector>
#include <set>

class FencePriceCalculator
{
    public:
    FencePriceCalculator(const std::vector<std::vector<char>>& map);
    int calculateFencingPrice();

    private:
    int calculateRegionPrice(int i, int j);
    void addAdjacentPlots(int i, int j, std::set<std::pair<int,int>>& plots);
    void findOuterCorners(const std::vector<bool>& edges);
    void findInnerCorners(const std::vector<bool>& edges, int row, int column, char type);

    const std::vector<std::vector<char>>& _map;
    std::set<std::pair<int,int>> _processedPlots;
    int _regionPerimeter = 0;
    int _regionCorners = 0;
};