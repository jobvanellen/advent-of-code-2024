#include "FileParser.hpp"
// #include "Stone.hpp"


#include <list>
#include <iostream>

bool twoDigits(std::list<unsigned long int>::iterator stone)
{
    return (std::to_string(*stone).size() % 2) == 0;
}

unsigned long int splitStone(unsigned long int& value)
{
    auto s = std::to_string(value);
    int stone1 = std::stoi(s.substr(0, s.size()/2));
    int stone2 = std::stoi(s.substr(s.size()/2, s.size()));
    value = stone2;
    return stone1;
}

void applyRule(std::list<unsigned long int>& stones, std::list<unsigned long int>::iterator stone)
{
    if(*stone == 0)
    {
        *stone = 1;
    }
    else if(twoDigits(stone))
    {
        stones.insert(stone, splitStone(*stone));
    }
    else
    {
        *stone *= 2024;
    }
       
}

void blink(std::list<unsigned long int>& stones)
{
    for(auto stone = stones.begin(); stone != stones.end(); stone++)
    {
        applyRule(stones, stone);
    }
}

void printStones(const std::list<unsigned long int>& stones)
{
    for(const auto& stone : stones)
    {
        std::cout << stone << " ";
    }
    std::cout << std::endl;
}



int main()
{
    std::list<unsigned long int> stones;

    // FileParser::parseFile("example_stones.txt", stones);    
    FileParser::parseFile("stones.txt", stones);

    for(int i = 0; i < 25; i++)
    {
        blink(stones);
        // printStones(stones);
    }
    std::list<unsigned long int> stones2;

    std::cout << stones.size() << std::endl;



    return 0;
}