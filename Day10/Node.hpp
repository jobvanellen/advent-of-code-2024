#pragma once

#include <utility>
#include <vector>
#include <set>


class Node
{
    public:
    Node(int value, int row, int column);
    int value() const;
    std::pair<int,int> location() const;
    bool isTrailHead();

    private:
    const int _value;
    const int _row;
    const int _column;
    std::vector<Node> nextNodes;
};

class Trailhead : public Node
{
    public:
    Trailhead(int value, int row, int column);
    void addPeak(Node);
    bool isTrailHead();
    int countPeaks() const;

    private:
    std::set<std::pair<int,int>> _peakLocations;
};