#pragma once

#include "Node.hpp"

#include <vector>
#include <set>

class TrailFinder
{
    public:
    TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Node> trailheads);

    std::vector<int> getTrailheadScores();
    std::vector<int> getTrailheadRatings();

    static TrailFinder createTrailFinder(const std::vector<std::vector<int>>& map);

    private:

    std::set<std::pair<int,int>> findReachablePeaks(Node& node);
    int countPaths(Node& node);
    void addNextNodes(Node& node);
    bool withinBounds(std::pair<int,int> location);

    const std::vector<std::vector<int>>& _map;
    std::vector<Node> _trailheads;
    static const std::vector<std::pair<int,int>> DIRECTIONS;
};
