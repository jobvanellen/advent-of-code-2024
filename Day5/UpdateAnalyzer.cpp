#include "UpdateAnalyzer.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

UpdateAnalyzer::UpdateAnalyzer(const std::vector<std::pair<int,int>>& rules, const std::vector<std::vector<int>>& updates)
: _rules(rules), _updates(updates)
{}

int UpdateAnalyzer::getCorrectUpdateScore() const
{
    std::vector<int> correctIndices = findCorrectUpdates();
    return sumOfMiddleValues(correctIndices);
}  

int UpdateAnalyzer::getCorrectedUpdateScore() const
{
    int sum = 0;
    std::vector<int> incorrectIndices = findIncorrectUpdates();
    for(int index : incorrectIndices)
    {
        sum += correctAndGetMiddleValue(_updates.at(index)); 
    }
    return sum;
}

int UpdateAnalyzer::sumOfMiddleValues(const std::vector<int>& indices) const
{
    int sum = 0;
    for(auto index : indices)
    {
        sum += getMiddleValue(_updates.at(index));
    }
    return sum;
}

int UpdateAnalyzer::correctAndGetMiddleValue(const std::vector<int>& update) const
{
    std::vector<int> updateCopy = update;
    while(!isUpdateCorrect(updateCopy))
    {
        correctSequence(updateCopy);
    }

    return getMiddleValue(updateCopy);
}

void UpdateAnalyzer::correctSequence(std::vector<int>& update) const
{
    std::pair<int, int> rule = _rules.at(getFirstViolatedRule(update));
    update.at(getPageIndex(rule.first, update)) = rule.second;
    update.at(getPageIndex(rule.second, update)) = rule.first;
}


int UpdateAnalyzer::getMiddleValue(const std::vector<int>& update) const
{
    int middle = update.at(update.size()/2);
    // std::cout << "Middle value: " << middle << std::endl;
    return middle;
}

std::vector<int> UpdateAnalyzer::findCorrectUpdates() const
{
    std::vector<int> correctUpdates;
    for(int i = 0; i < _updates.size(); i++)
    {
        if(isUpdateCorrect(_updates.at(i)))
        {
            correctUpdates.push_back(i);
        }
    }
    return correctUpdates;
}

std::vector<int> UpdateAnalyzer::findIncorrectUpdates() const
{
    std::vector<int> incorrectUpdates;
    for(int i = 0; i < _updates.size(); i++)
    {
        if(!isUpdateCorrect(_updates.at(i)))
        {
            incorrectUpdates.push_back(i);
        }
    }
    return incorrectUpdates;
}

bool UpdateAnalyzer::isUpdateCorrect(const std::vector<int>& update) const
{
    return getFirstViolatedRule(update) == -1;
}

int UpdateAnalyzer::getFirstViolatedRule(const std::vector<int>& update) const
{
    for(int i = 0; i < _rules.size(); i++)
    {
        if(!doesRuleApplyToUpdate(_rules.at(i), update))
        {
            return i;
        }
    }
    return -1;
}

bool UpdateAnalyzer::doesRuleApplyToUpdate(const std::pair<int,int>& rule, const std::vector<int>& update) const
{
    int firstIndex = getPageIndex(rule.first, update);
    int secondIndex = getPageIndex(rule.second, update);

    if(firstIndex < 0 || secondIndex < 0)
    {
        return true;
    }

    return firstIndex < secondIndex;
}

int UpdateAnalyzer::getPageIndex(int page, const std::vector<int>& update) const
{
    const auto iter = std::find(update.begin(), update.end(), page);
    return iter != update.end() ? std::distance(update.begin(), iter) : -1;
}