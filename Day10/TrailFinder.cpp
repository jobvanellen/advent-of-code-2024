#include "TrailFinder.hpp"

const std::vector<std::pair<int,int>> TrailFinder::DIRECTIONS = {{-1,0}, {0,1}, {1,0}, {0,-1}};

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

TrailFinder::TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Trailhead> trailheads)
: _map(map), _trailheads(trailheads)
{}


std::vector<int> TrailFinder::getTrailheadScores()
{
    std::vector<int> scores;
    for(auto& trailhead : _trailheads)
    {
        std::set<std::pair<int,int>> peakLocations;
        peakLocations.merge(findPaths(trailhead));
        scores.push_back(peakLocations.size());
    }
    
    return scores;
}

std::set<std::pair<int,int>> TrailFinder::findPaths(Node& node)
{
    std::set<std::pair<int,int>> peakLocations;

    if(node.value() == 9)
    {
        peakLocations.insert(node.location());
        return peakLocations;
    }

    addNextNodes(node);

    for(auto& node : node.getNextNodes())
    {
        peakLocations.merge(findPaths(node));
    }
    return peakLocations;
    
}

void TrailFinder::addNextNodes(Node& node)
{
    auto currentLocation = node.location();
    
    for(auto direction : DIRECTIONS)
    {
        auto nextLocation = currentLocation + direction;
        if(withinBounds(nextLocation))
        {
            int value = _map.at(nextLocation.first).at(nextLocation.second);
            if(value - node.value() == 1)
            {
                node.addNextNode(Node(value, nextLocation));
            }
        }
    }
}

bool TrailFinder::withinBounds(std::pair<int,int> location)
{
    return location.first >= 0 &&
           location.first < _map.size() &&
           location.second >= 0 &&
           location.second < _map.at(0).size();
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