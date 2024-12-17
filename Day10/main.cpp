#include "FileParser.hpp"
#include "TrailFinder.hpp"

#include <map>
#include <iostream>
#include <numeric>


int main()
{
    std::vector<std::vector<int>> map;
    // FileParser::parseMap("example_map.txt", map);

    FileParser::parseMap("map.txt", map);

    TrailFinder trailFinder = TrailFinder::createTrailFinder(map);
    
    std::vector<int> scores = trailFinder.getTrailheadScores();

    int scoreSum = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << scoreSum << std::endl;
    

    std::vector<int> ratings = trailFinder.getTrailheadRatings();
    int ratingSum = std::accumulate(ratings.begin(), ratings.end(), 0);
    std::cout << ratingSum << std::endl;

    return 0;
}