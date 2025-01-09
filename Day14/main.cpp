#include "FileParser.hpp"

#include <array>
#include <numeric>
#include <algorithm>
#include <set>


int main()
{
    std::string file = "example_robots.txt";
    // std::string file = "robots.txt";

    std::vector<Robot> robots;

    // int xLimit = 11;
    // int yLimit = 7;

    int xLimit = 101;
    int yLimit = 103;

    // FileParser::parseRobotInfo("example_robots.txt", robots, 11, 7);
    FileParser::parseRobotInfo("robots.txt", robots, 101, 103);
    
    int cycles = 100;

    for(auto& robot : robots)
    {
        robot.move(cycles);
    }

    std::array<int, 4> quadrantScores = {0, 0, 0, 0};
    for(const auto& robot : robots)
    {
        if(robot.getX() < xLimit / 2 && robot.getY() < yLimit / 2)
        {
            quadrantScores.at(0)++;
        }
        else if(robot.getX() > xLimit / 2 && robot.getY() < yLimit / 2)
        {
            quadrantScores.at(1)++;
        }
        else if(robot.getX() < xLimit / 2 && robot.getY() > yLimit / 2)
        {
            quadrantScores.at(2)++;
        }
        else if (robot.getX() > xLimit / 2 && robot.getY() > yLimit / 2)
        {
            quadrantScores.at(3)++;
        }
    }

    std::cout << "Quadrant scores: ";
    std::cout << quadrantScores.at(0) << " ";
    std::cout << quadrantScores.at(1) << " ";
    std::cout << quadrantScores.at(2) << " ";
    std::cout << quadrantScores.at(3) << std::endl;

    int safetyFactor = quadrantScores.at(0) * quadrantScores.at(1) * quadrantScores.at(2) * quadrantScores.at(3);
    std::cout << "Safety factor: " << safetyFactor << std::endl;

    robots.clear();
    FileParser::parseRobotInfo("robots.txt", robots, 101, 103);
    // print eacht cycle
    int x = 499;
    for(int i = 0; i < 100000; i++)
    {   
        // 2d char vector of spaces
        std::vector<std::vector<char>> map(yLimit, std::vector<char>(xLimit, ' '));
        for(auto& robot : robots)
        {
            map.at(robot.getY()).at(robot.getX()) = '#';
            robot.move(1);
        }

        int uniquePositions = 0;
        for(const auto& row: map)
        {
            uniquePositions += std::count(row.begin(), row.end(), '#');
        }
        // print map if unique size > x
        if(uniquePositions > x)
        {
            for(const auto& row : map)
            {
                for(const auto& cell : row)
                {
                    std::cout << cell;
                }
                std::cout << std::endl;
            }
            // close cycle with line
            std::cout << i << std::string(xLimit - 1, '-') << std::endl;
        }
    }

    return 0;
}