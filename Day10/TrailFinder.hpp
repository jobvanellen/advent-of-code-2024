#pragma once

#include "Node.hpp"

#include <vector>
#include <set>



class TrailFinder
{
    public:
    TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Trailhead> trailheads);

    std::vector<int> getTrailheadScores() const;

    static TrailFinder createTrailFinder(const std::vector<std::vector<int>>& map);

    private:
    const std::vector<std::vector<int>>& _map;
    const std::vector<Node> _nodes;
    const std::vector<Trailhead> _trailheads;
    // const std::vector<std::pair<int, int>
};
