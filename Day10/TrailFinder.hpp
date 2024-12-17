#pragma once

#include "Node.hpp"

#include <vector>
#include <set>

class TrailFinder
{
    public:
    TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Trailhead> trailheads);

    std::vector<int> getTrailheadScores();
    void addNextNodes(Node& node);

    static TrailFinder createTrailFinder(const std::vector<std::vector<int>>& map);

    private:

    bool withinBounds(std::pair<int,int> location);

    const std::vector<std::vector<int>>& _map;
    std::vector<Trailhead> _trailheads;
    static const std::vector<std::pair<int,int>> DIRECTIONS;
    // const std::vector<std::pair<int, int>
};
