#include "FileParser.hpp"

#include <array>
#include <numeric>

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
    return 0;
}