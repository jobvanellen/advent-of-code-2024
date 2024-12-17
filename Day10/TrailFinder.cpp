#include "TrailFinder.hpp"

TrailFinder::TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Trailhead> trailheads)
: _map(map), _trailheads(trailheads)
{}


std::vector<int> TrailFinder::getTrailheadScores() const
{

}

TrailFinder TrailFinder::createTrailFinder(const std::vector<std::vector<int>>& map)
{
    std::vector<Trailhead> trailHeads;
    for (int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map.at(i).size(); j++)
        {
            int value = map.at(i).at(j);
            if(value == 0)
            {
                trailHeads.emplace_back(Trailhead(value, i, j));
            }
        }
    }

    return TrailFinder(map, trailHeads);
}