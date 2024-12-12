#pragma once
#include <vector>
#include <utility>

class UpdateAnalyzer
{
    public:
    UpdateAnalyzer(const std::vector<std::pair<int,int>>& rules, const std::vector<std::vector<int>>& updates);
    
    // Update Score: Sum of the middle value of all correct updates
    int getCorrectUpdateScore() const;
    int getCorrectedUpdateScore() const;

    private:
    std::vector<int> findCorrectUpdates() const;
    std::vector<int> findIncorrectUpdates() const;
    int getFirstViolatedRule(const std::vector<int>& update) const;
    bool isUpdateCorrect(const std::vector<int>& update) const;
    bool doesRuleApplyToUpdate(const std::pair<int,int>& rule, const std::vector<int>& update) const;
    int getPageIndex(int page, const std::vector<int>& update) const;
    int sumOfMiddleValues(const std::vector<int>& indices) const;
    int correctAndGetMiddleValue(const std::vector<int>& update) const;
    void correctSequence(std::vector<int>& update) const;
    int getMiddleValue(const std::vector<int>& update) const;

    const std::vector<std::pair<int,int>>& _rules;
    const std::vector<std::vector<int>>& _updates;

    

    
};