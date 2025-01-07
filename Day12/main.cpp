#include "FileParser.hpp"
#include "FencePriceCalculator.hpp"

#include <map>
#include <vector>
#include <iostream>

int main()
{
    // std::string file = "example_map.txt";
    std::string file = "map.txt";

    std::vector<std::vector<char>> map;
    FileParser::parseMap(file, map);

    FencePriceCalculator fencePriceCalculator(map);

    int price = fencePriceCalculator.calculateFencingPrice();

    std::cout << "The total price for fencing the regions is: " << price << std::endl;

    return 0;
}