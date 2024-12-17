#include "FileParser.hpp"

#include <map>
#include <vector>
#include <numeric>
#include <iostream>

bool twoDigits(unsigned long int value)
{
    return ((std::to_string(value)).size() % 2) == 0;
}

unsigned long int splitStone(unsigned long int& value)
{
    auto s = std::to_string(value);
    int stone1 = std::stoi(s.substr(0, s.size()/2));
    int stone2 = std::stoi(s.substr(s.size()/2, s.size()));
    value = stone2;
    return stone1;
}

std::map<unsigned long int, unsigned long int> applyRule(const std::map<unsigned long int, unsigned long int>& stones, std::map<unsigned long int, unsigned long int>::iterator stoneType) 
{
    unsigned long int key = stoneType->first;
    unsigned long int amount = stoneType->second;
    auto newMap = stones;
    if(key == 0)
    {  
        newMap[key] -= amount;
        newMap[1] += amount;
    }
    else if(twoDigits(key))
    {
        newMap[key] -= amount;
        auto newKey = splitStone(key);
        newMap[key] += amount;
        newMap[newKey] += amount;
    }
    else
    {
        newMap[key] -= amount;
        newMap[key*2024] += amount;
    }
    return newMap;
}

void blink(std::map<unsigned long int, unsigned long int>& stones)
{
    std::map<unsigned long int, unsigned long int> newMap;
    for(auto stone = stones.begin(); stone != stones.end(); stone++)
    {
        newMap = applyRule(stones, stone);
    }
    stones = newMap;
}

void printStones(const std::map<unsigned long int, unsigned long int>& stones)
{
    for(const auto& stone : stones)
    {
        std::cout << stone.first << "," << stone.second << "|";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<unsigned long int> stoneVector;
    std::map<unsigned long int, unsigned long int> stones;
    FileParser::parseFile("example_stones.txt", stoneVector);    
    // FileParser::parseFile("stones.txt", stoneVector);

    for(auto i : stoneVector)
    {
        stones[i] += 1;
    }  

    for(int i = 0; i < 6; i++)
    {
        blink(stones);
        printStones(stones);
    }

    unsigned long int count = std::accumulate(stones.begin(), stones.end(), 0, [](const unsigned long int previous, const auto& element)
                { return previous + element.second; });
    std::cout << count << std::endl;

    return 0;
}