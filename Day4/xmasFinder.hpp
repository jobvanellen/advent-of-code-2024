#pragma once
#include <vector>
#include <forward_list>

enum class Direction
{
    NORTH,
    NORTHEAST,
    EAST,
    SOUTHEAST,
    SOUTH,
    SOUTHWEST,
    WEST,
    NORTHWEST
};

class XmasFinder
{
    public:
     XmasFinder(const std::vector<std::vector<char>>& matrix);
     int countXmas();
     int countCrossMas();

    private:
     void checkForXmas(const int row, const int column, const Direction direction);
     bool outOfBounds(int row, int colums) const;
     void tryNextDirection(int row, int colums) const;
     void moveIndices(int& row, int& column, const Direction direction) const;
     char getChar(const int row, const int column) const;
     bool isCrossMas(char upperLeft, char lowerLeft, char upperRight, char lowerRight) const;


     const std::vector<std::vector<char>>& _matrix;

     int _count = 0;

     const std::forward_list<char> _letters = {'X', 'M', 'A', 'S'};

     const std::forward_list<Direction> _directionList = {
        Direction::NORTH,
        Direction::NORTHEAST,
        Direction::EAST,
        Direction::SOUTHEAST,
        Direction::SOUTH,
        Direction::SOUTHWEST,
        Direction::WEST,
        Direction::NORTHWEST};

    std::forward_list<char>::const_iterator _letterIterator = _letters.begin();
};

