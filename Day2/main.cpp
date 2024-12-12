
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

std::vector<std::vector<int>> parseInput()
{
    std::ifstream file("input.txt");
    std::vector<std::vector<int>> reports;

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return reports;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> report;      
        std::istringstream iss(line);

        int level;
        while (iss >> level) {           
            report.push_back(level);
        }

        reports.push_back(report);
    }

    return reports;
}

std::set<int> levelsNotIncreasing(std::vector<int>& report)
{
    std::set<int> badLevels;
    for(int i = 1; i < report.size(); i++)
    {
        if(report[i] < report[i-1])
        {
            badLevels.insert(i);
        }
    }
    return badLevels;
}

std::set<int> levelsNotDecreasing(std::vector<int>& report)
{
    std::set<int> badLevels;
    for(int i = 1; i < report.size(); i++)
    {
        if(report[i] > report[i-1])
        {
            badLevels.insert(i);
        }
    }
    return badLevels;
}

std::set<int> levelDiffBetweenOneAndThree(std::vector<int>& report)
{
    std::set<int> badLevels;
    for(int i = 1; i < report.size(); i++)
    {
        int diff = std::abs(report[i] - report[i-1]);
        if(diff < 1 || diff > 3)
        {
            badLevels.insert(i);
        }
    }
    return badLevels;
}

std::set<int> getBadLevels(std::vector<int> report)
{
    std::set<int> badLevels;
    std::set<int> notIncreasingLevels = levelsNotIncreasing(report);
    std::set<int> notDecreasingLevels = levelsNotDecreasing(report);
    std::set<int> badDiffLevels = levelDiffBetweenOneAndThree(report);

    badLevels.merge(notIncreasingLevels.size() < notDecreasingLevels.size() ? 
                    notIncreasingLevels : notDecreasingLevels);

    badLevels.merge(badDiffLevels);
    
    return badLevels;
}

bool isDampenedReportSafe(const std::vector<int>& report)
{
    for(int i = 0; i < report.size(); i++)
    {
        std::vector<int> dampenedReport = report;
        dampenedReport.erase(dampenedReport.begin() + i);
        if(getBadLevels(dampenedReport).size() == 0)
        {
            return true;
        }
    }
    return false;
}

bool isSafe(std::vector<int> report)
{
    return getBadLevels(report).size() == 0 ? true : isDampenedReportSafe(report);
}

int main()
{
    std::vector<std::vector<int>> reports = parseInput();
    
    unsigned safeReportCount = 0;
    for(const auto& report : reports)
    {
        if(isSafe(report))
        {
            safeReportCount++;
        }
    }
    

    std::cout << safeReportCount << std::endl;

    return 0;
}