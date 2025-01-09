#include "FileParser.hpp"

std::pair<int,int> findRobot(const std::vector<std::vector<char>>& map)
{
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map.at(i).size(); j++)
        {
            if(map.at(i).at(j) == '@')
            {
                return std::make_pair(i,j);
            }
        }
    }

    return std::make_pair(-1,-1);    
}

void moveObject(std::vector<std::vector<char>> &map, std::pair<int, int> &position, int newX, int newY, char symbol)
{
    map.at(position.first).at(position.second) = '.';
    map.at(newX).at(newY) = symbol;
    position.first = newX;
    position.second = newY;
}

bool tryMove(std::pair<int, int> &position, std::vector<std::vector<char>>& map, int dx, int dy)
{
    auto symbol = map.at(position.first).at(position.second);
    int newX = position.first + dx;
    int newY = position.second + dy;

    if(map.at(newX).at(newY) == '#')
    {
        return false;
    }
    
    if(map.at(newX).at(newY) == '.')
    {
        moveObject(map, position, newX, newY, symbol);
        return true;
    }
    
    if(map.at(newX).at(newY) == 'O')
    {
        auto boxposition = std::make_pair(newX, newY);
        if(tryMove(boxposition, map, dx, dy))
        {
            moveObject(map, position, newX, newY, symbol);
            return true;
        }
    }

    return false;
}

int calculateBoxCoordinates(std::vector<std::vector<char>>& map)
{
    int sumBoxCoordinates = 0;
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map.at(i).size(); j++)
        {
            if(map.at(i).at(j) == 'O')
            {
                sumBoxCoordinates += 100 * i + j;
            }
        }
    }

    return sumBoxCoordinates;
}


int main()
{
    std::vector<std::vector<char>> map;
    std::vector<Move> moves;

    // std::string mapFilefile = "small_map.txt";
    // std::string mapFilefile = "example_map.txt";
    std::string mapFile = "map.txt";

    // std::string movesFile = "small_moves.txt";
    // std::string movesFile = "example_moves.txt";
    std::string movesFile = "moves.txt";

    FileParser::parseMap(mapFile, map);
    FileParser::parseMoves(movesFile, moves);

    std::pair<int,int> robotPosition = findRobot(map);

    for(const auto& move : moves)
    {
        switch (move)
        {
        case Move::UP:
            tryMove(robotPosition, map, -1, 0);
            break;
        case Move::DOWN:
            tryMove(robotPosition, map, 1, 0);
            break;
        case Move::LEFT:
            tryMove(robotPosition, map, 0, -1);
            break;
        case Move::RIGHT:
            tryMove(robotPosition, map, 0, 1);
            break;
        default:
            break;
        }
        // robotPosition = findRobot(map);
        // std::cout << "Robot moved to: " << robotPosition.first << " " << robotPosition.second << std::endl;
    }
    
    FileParser::printMap(map);

    std::cout << "Sum of box coordinates: " << calculateBoxCoordinates(map) << std::endl;

    return 0;
}
