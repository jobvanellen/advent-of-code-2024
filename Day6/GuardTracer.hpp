#pragma once
#include <vector>
#include <set>

struct Position
{
    int row;
    int column;

    Position up(){return Position{row - 1, column};}
    Position right(){return Position{row, column + 1};}
    Position down(){return Position{row + 1, column};}
    Position left(){return Position{row, column - 1};}

    bool operator==(const Position& rhs)
    {
        return this->row == rhs.row && this->column == rhs.column;
    }

};

enum class Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

class GuardTracer
{
    public:
    explicit GuardTracer(const std::vector<std::vector<char>>& map);
    int countVisitedPositions() const;
    int countLoopCausingObstaclePositions() const;

    private:
    Position getStartPosition() const;
    std::set<std::pair<int,int>> getVisitedPositions(const Position& startPosition) const;
    bool loopCaused(const Position& startPosition, Position newObstacle) const;
    bool hitObstacle(Position position, Direction direction, Position newObstacle = {-1,-1}) const;
    bool positionIsOnMap(Position position) const;
    Direction turnRight(Direction direction) const;
    Position getForwardPosition(Position position, Direction direction) const;

    const std::vector<std::vector<char>>& _map;

};