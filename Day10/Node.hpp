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
    void addNextNode(Node node);
    
    std::vector<Node>& getNextNodes();
    
    private:
    const int _value;
    const int _row;
    const int _column;
    std::vector<Node> _nextNodes;
};