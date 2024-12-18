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
    unsigned long int stone1 = std::stoi(s.substr(0, s.size()/2));
    unsigned long int stone2 = std::stoi(s.substr(s.size()/2, s.size()));
    value = stone2;
    return stone1;
}

std::map<unsigned long int, unsigned long int> applyRule(const std::map<unsigned long int, unsigned long int>& stones, 
                                                        std::map<unsigned long int, unsigned long int>& newMap, 
                                                        std::map<unsigned long int, unsigned long int>::iterator stoneType) 
{
    unsigned long int key = stoneType->first;
    unsigned long int amount = stoneType->second;
    if(key == 0)
    {  
        newMap[1] += amount;
    }
    else if(twoDigits(key))
    {
        auto newKey = splitStone(key);
        newMap[key] += amount;
        newMap[newKey] += amount;
    }
    else
    {
        newMap[key*2024] += amount;
    }
    return newMap;
}

void blink(std::map<unsigned long int, unsigned long int>& stones)
{
    std::map<unsigned long int, unsigned long int> newMap;
    for(auto stonetype = stones.begin(); stonetype != stones.end(); stonetype++)
    {
        applyRule(stones, newMap, stonetype);
    }
    stones = newMap;
}

void printStones(const std::map<unsigned long int, unsigned long int>& stones)
{
    for(const auto& stonetype : stones)
    {
        std::cout << stonetype.first << "," << stonetype.second << "|";
    }
    std::cout << std::endl;
}

std::map<unsigned long int, unsigned long int> createStoneMap(const std::string& file)
{
    std::vector<unsigned long int> stoneVector;
    FileParser::parseFile(file, stoneVector);

    std::map<unsigned long int, unsigned long int> stones;   
    for(auto i : stoneVector)
    {
        stones[i] += 1;
    }  

    return stones;
}

int main()
{
    // std::string file = "example_stones.txt";
    std::string file = "stones.txt";
    std::map<unsigned long int, unsigned long int> stones = createStoneMap(file);

    const int blinkTimes = 75;

    for(int i = 0; i < blinkTimes; i++)
    {
        blink(stones);
        // printStones(stones);
    }

    unsigned long int count = 0;
    for(const auto& stonetype : stones)
    {
        count += stonetype.second;
    }
    std::cout << count << std::endl;


    return 0;
}