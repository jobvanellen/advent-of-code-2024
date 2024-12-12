#include "xmasFinder.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <forward_list>
#include <memory>


void parseFile(std::string filename, std::vector<std::vector<char>>& result)
{
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::string line;
    while(std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<char> row;

        char letter;
        while(iss >> letter)
        {
            row.push_back(letter);
        }

        result.push_back(row);
    }
}

void printMatrix(const std::vector<std::vector<char>>& matrix)
{
    for(const auto& row : matrix)
    {
        for(const auto& letter : row)
        {
            std::cout << letter;
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<char>> xmasMatrix;
    parseFile("input.txt", xmasMatrix);
    // parseFile("example.txt", xmasMatrix);
    // printMatrix(xmasMatrix);

    XmasFinder finder(xmasMatrix);
    std::cout << finder.countXmas() << std::endl;
    std::cout << finder.countCrossMas() << std::endl;

    return 0;
}