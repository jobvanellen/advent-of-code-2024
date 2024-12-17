#pragma once

#include <utility>
#include <vector>
#include <set>

class Node
{
    public:
    Node(int value, int row, int column);
    Node(int value, std::pair<int,int> location);
    int value() const;
    std::pair<int,int> location() const;
    bool isTrailHead();
    void addNextNode(Node node);

    private:
    const int _value;
    const int _row;
    const int _column;
    std::vector<Node> _nextNodes;
};

class Trailhead : public Node
{
    public:
    Trailhead(int value, int row, int column);
    void addPeak(Node node);
    bool isTrailHead();
    int countPeaks() const;

    private:
    std::set<std::pair<int,int>> _peakLocations;
};