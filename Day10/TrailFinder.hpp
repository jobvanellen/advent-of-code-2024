#pragma once

#include "Node.hpp"

#include <vector>
#include <set>

class TrailFinder
{
    public:
    TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Node> trailheads);

    std::vector<int> getTrailheadScores() const;
    std::vector<int> getTrailheadRatings() const;

    static TrailFinder createTrailFinder(const std::vector<std::vector<int>>& map);

    private:
    std::set<std::pair<int,int>> findReachablePeaks(const Node& node) const;
    int countPaths(const Node& node) const;
    bool withinBounds(const std::pair<int,int> location) const;

    void addNextNodes(Node& node);

    const std::vector<std::vector<int>>& _map;
    std::vector<Node> _trailheads;
    static const std::vector<std::pair<int,int>> DIRECTIONS;
};
