#include "Input.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <iostream>

int main()
{
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int distance = 0;
    for(unsigned i = 0; i < 1000; i++)
    {
        distance += std::abs(list1[i] - list2[i]);
    }
    std::cout << "List distance: " << distance << std::endl;

    int similarityScore = 0;
    for(const int leftValue : list1)
    {
        similarityScore += leftValue * std::count(list2.begin(), list2.end(), leftValue);
    }

    std::cout << "Similarity score: " << similarityScore << std::endl;

    return 0;
}