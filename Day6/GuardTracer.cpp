#include "GuardTracer.hpp"
#include <iostream>
#include <exception>


GuardTracer::GuardTracer(const std::vector<std::vector<char>>& map)
: _map(map)
{}

int GuardTracer::countVisitedPositions() const
{
    Position startPosition;
    try{
        startPosition = getStartPosition();
        // std::cout << "Startposition: " << position.row << "," << position.column << std::endl;
    }
    catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }   

    return getVisitedPositions(startPosition).size();
}

int GuardTracer::countLoopCausingObstaclePositions() const
{
    Position startPosition;
    int count = 0;
    try{
        startPosition = getStartPosition();
    }
    catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
    std::set<std::pair<int,int>> initialPath = getVisitedPositions(startPosition);

    for(const auto& pair : initialPath)
    {
        Position newObstacle = {pair.first, pair.second};
        if(loopCaused(startPosition, newObstacle))
        {
            count++;
        }   
    }
    return count;
}

std::set<std::pair<int,int>> GuardTracer::getVisitedPositions(const Position& startPosition) const
{
    Position position = startPosition;
    Direction direction = Direction::UP;  
    std::set<std::pair<int, int>> visitedPositions;
    visitedPositions.insert(std::make_pair(position.row, position.column));

    while(positionIsOnMap(getForwardPosition(position, direction)))
    {
        if(hitObstacle(position, direction))
        {
            direction = turnRight(direction);
        }
        else
        {  
            position = getForwardPosition(position, direction);
            // std::cout << "New position: " << position.row << "," << position.column << std::endl;

            visitedPositions.insert(std::make_pair(position.row, position.column));
        }
    }    
    return visitedPositions;
}

bool GuardTracer::loopCaused(const Position& startPosition, Position newObstacle) const
{   
    Direction direction = Direction::UP;
    Position position = startPosition;
    std::set<std::pair<int,int>> path;
    int sequentialRepeatVisits = 0;

    while(positionIsOnMap(getForwardPosition(position, direction)))
    {
        if(hitObstacle(position, direction, newObstacle))
        {
            direction = turnRight(direction);
        }
        else
        {
            position = getForwardPosition(position,direction);
            if(!path.insert(std::make_pair(position.row, position.column)).second)
            {
                sequentialRepeatVisits++;
            }
            else
            {
                sequentialRepeatVisits = 0;
            }
        }
        if(sequentialRepeatVisits > 100)
        {
            return true;
        }
    }
    return false;
}

Position GuardTracer::getStartPosition() const
{
    for(int row = 0; row < _map.size(); row++)
    {
        for(int column = 0; column < _map.at(row).size(); column++)
        {
            if(_map.at(row).at(column) == '^')
            {
                // std::cout << "^ found at: " << row << "," << column << std::endl;
                return Position{row, column};
            }
        }
    }
    throw std::out_of_range("Start position not found");
}

bool GuardTracer::positionIsOnMap(Position position) const
{
    return position.row >= 0 && 
           position.row < _map.size() &&
           position.column >= 0 && 
           position.column < _map.at(0).size();
}

bool GuardTracer::hitObstacle(Position position, Direction direction, Position newObstacle) const
{
    auto forward = getForwardPosition(position, direction);
    return _map.at(forward.row).at(forward.column) == '#' || forward == newObstacle;
}

Position GuardTracer::getForwardPosition(Position position, Direction direction) const
{
    switch(direction)
    {
        case Direction::UP:
            return position.up(); 
        case Direction::RIGHT:
            return position.right();
        case Direction::DOWN:
            return position.down(); 
        case Direction::LEFT:
            return position.left();
        default:
            return position.up(); 
    }
}

Direction GuardTracer::turnRight(Direction direction) const
{
    switch(direction)
    {
        case Direction::UP:
            return Direction::RIGHT; 
        case Direction::RIGHT:
            return Direction::DOWN; 
        case Direction::DOWN:
            return Direction::LEFT; 
        case Direction::LEFT:
            return Direction::UP;
        default:
            return Direction::UP;
    }
}

