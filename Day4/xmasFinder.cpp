#include "xmasFinder.hpp"
#include <iostream>
#include <forward_list>

XmasFinder::XmasFinder(const std::vector<std::vector<char>>& matrix)
: _matrix(matrix)
{}

int XmasFinder::countXmas()
{
    _count = 0;
    for( int i = 0; i < _matrix.size(); i++)
    {
        for( int j = 0; j < _matrix.at(i).size(); j++)
        {
            std::forward_list<char>::const_iterator letterIterator = _letters.begin();
            if(_matrix.at(i).at(j) == 'X')
            {
                for(auto direction : _directionList)
                {
                    int oldCount = _count;
                    _letterIterator = _letters.begin();
                    checkForXmas(i,j, direction);
                }
            }
        }
    }
    return _count;
}

void XmasFinder::checkForXmas(const int row, const int column, const Direction direction)
{
    if(_letterIterator == _letters.end())
    {
        _count++;
        return;
    }

    if(outOfBounds(row, column))
    {
        return;
    }

    char letter = _matrix.at(row).at(column);

    if(letter != *_letterIterator)
    {
        return;
    }

    _letterIterator++;    
    int nextRow = row;
    int nextColumn = column;
    moveIndices(nextRow, nextColumn, direction);
    checkForXmas(nextRow, nextColumn, direction);
}

bool XmasFinder::outOfBounds(const int row, const int column) const
{
    // std::cout << _matrix.at(row).size() << std::endl;
    return row < 0 || 
           row >= _matrix.size() || 
           column < 0 || 
           column >= _matrix.at(row).size();
}

void XmasFinder::moveIndices(int& row, int& column, const Direction direction ) const
{
    switch(direction)
    {
        case Direction::NORTH:
            row--;
            return;
        case Direction::NORTHEAST:
            row--;
            column++;
            return;
        case Direction::EAST:
            column++;
            return;
        case Direction::SOUTHEAST:
            column++;
            row++;
            return;
        case Direction::SOUTH:
            row++;
            return;
        case Direction::SOUTHWEST:
            row++;
            column--;
            return;
        case Direction::WEST:
            column--;
            return;
        case Direction::NORTHWEST:
            row--;
            column--;
            return;
    }
}

int XmasFinder::countCrossMas()
{
    _count = 0;
    for( int i = 0; i < _matrix.size(); i++)
    {
        for( int j = 0; j < _matrix.at(i).size(); j++)
        {
            if(_matrix.at(i).at(j) == 'A')
            {
                const char upperLeft = getChar(i-1, j-1);
                const char lowerLeft = getChar(i+1, j-1);
                const char upperRight = getChar(i-1, j+1);
                const char lowerRight = getChar(i+1, j+1);

                if(isCrossMas(upperLeft, lowerLeft, upperRight, lowerRight))
                {
                    _count++;
                }
            }

        }
    }
    return _count;
}

char XmasFinder::getChar(const int row, const int column) const
{
    char result = ' ';
    if(!outOfBounds(row, column))
    {
        result = _matrix.at(row).at(column);
    }
    return result;
}

bool XmasFinder::isCrossMas(char upperLeft, char lowerLeft, char upperRight, char lowerRight) const
{
    return (upperLeft == 'S' && lowerRight == 'M' ||
           upperLeft == 'M' && lowerRight == 'S') && 
           (upperRight == 'S' && lowerLeft == 'M' ||
           upperRight == 'M' && lowerLeft == 'S');
} 

