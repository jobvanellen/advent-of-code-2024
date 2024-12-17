#include "TrailFinder.hpp"

const std::vector<std::pair<int,int>> TrailFinder::DIRECTIONS = {{-1,0}, {0,1}, {1,0}, {0,-1}};

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

TrailFinder::TrailFinder(const std::vector<std::vector<int>>& map, const std::vector<Node> trailheads)
: _map(map), _trailheads(trailheads)
{
    for(auto& trailhead : _trailheads)
    {
        addNextNodes(trailhead);
    }
}

void TrailFinder::addNextNodes(Node& node)
{
    if(node.value() == 9)
    {
        return;
    }

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

    for(auto& nextNode : node.getNextNodes())
    {
        addNextNodes(nextNode);
    }
}


std::vector<int> TrailFinder::getTrailheadScores()
{
    std::vector<int> scores;
    for(auto& trailhead : _trailheads)
    {
        std::set<std::pair<int,int>> peakLocations;
        peakLocations.merge(findReachablePeaks(trailhead));
        scores.push_back(peakLocations.size());
    }
    
    return scores;
}

std::set<std::pair<int,int>> TrailFinder::findReachablePeaks(Node& node)
{
    std::set<std::pair<int,int>> peakLocations;

    if(node.value() == 9)
    {
        peakLocations.insert(node.location());
        return peakLocations;
    }

    for(auto& node : node.getNextNodes())
    {
        peakLocations.merge(findReachablePeaks(node));
    }
    return peakLocations;
}

std::vector<int> TrailFinder::getTrailheadRatings()
{
    std::vector<int> ratings;
    for(auto& trailhead : _trailheads)
    {
        int rating = 1;
        rating += countPaths(trailhead);
        ratings.push_back(rating);
    }
    return ratings;
}

int TrailFinder::countPaths(Node& node)
{
    if(node.value() == 9)
    {
        return 0;
    }
    else if (node.getNextNodes().size() == 0) 
    {
        return -1;
    }
    
    int paths = node.getNextNodes().size() - 1;

    for(auto& nextNode : node.getNextNodes())
    {
        paths += countPaths(nextNode);
    }
    return paths;
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
    std::vector<Node> trailHeads;
    for (int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map.at(i).size(); j++)
        {
            int value = map.at(i).at(j);
            if(value == 0)
            {
                trailHeads.emplace_back(Node(value, i, j));
            }
        }
    }

    return TrailFinder(map, trailHeads);
}