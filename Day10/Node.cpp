#include "Node.hpp"

Node::Node(int value, int row, int column)
: _value(value), _row(row), _column(column)
{}


int Node::value() const
{
    return _value;
}

std::pair<int,int> Node::location() const
{
    return std::make_pair(_row, _column);
}

bool Node::isTrailHead()
{
    return false;
}


Trailhead::Trailhead(int value, int row, int column)
: Node(value, row, column)
{}
    
void Trailhead::addPeak(Node node)
{
    _peakLocations.emplace(node.location());
}

int Trailhead::countPeaks() const
{
    return _peakLocations.size();
}

bool Trailhead::isTrailHead()
{   
    return true;
}