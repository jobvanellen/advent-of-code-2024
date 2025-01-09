#include "FileParser.hpp"

#include <iterator>

const std::string FileParser::path = "../../Day14/files/";

void FileParser::parseRobotInfo(const std::string& file, std::vector<Robot>& robots, const int lx, const int ly)
{
    std::ifstream stream = loadFile(path + file);
    if (!stream) return;

    std::string line;
    while (std::getline(stream, line))
    {
        int x, y, vx, vy;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &x, &y, &vx, &vy);
        robots.emplace_back(x, y, vx, vy, lx, ly);
    }

    printRobots(robots);
}

void FileParser::printRobots(const std::vector<Robot>& robots)
{
    int i = 0;
    for(const auto& robot : robots)
    {
        std::cout << "Robot " << i++ << std::endl;
        std::cout << "Position: X=" << robot.getX() << ", Y=" << robot.getY() << std::endl;
        std::cout << "Velocity: VX=" << robot.getVX() << ", VY=" << robot.getVY() << std::endl;
        std::cout << std::endl;
    }
}

std::ifstream FileParser::loadFile(const std::string& filename)
{    
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return stream;
}