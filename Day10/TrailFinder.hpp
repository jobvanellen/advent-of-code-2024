#pragma once

#include "Node.hpp"

#include <vector>
#include <set>

class TrailFinder
{
    public:
    TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Node> trailheads);

    std::vector<int> getTrailheadScores();

    static TrailFinder createTrailFinder(const std::vector<std::vector<int>>& map);

    private:

    std::set<std::pair<int,int>> findPaths(Node& node);
    void addNextNodes(Node& node);
    bool withinBounds(std::pair<int,int> location);

    const std::vector<std::vector<int>>& _map;
    std::vector<Node> _trailheads;
    static const std::vector<std::pair<int,int>> DIRECTIONS;
    // const std::vector<std::pair<int, int>
};
