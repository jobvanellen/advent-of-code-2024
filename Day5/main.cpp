#include "UpdateAnalyzer.hpp"
#include "FileParser.hpp"

int main()
{
    
    std::vector<std::pair<int, int>> rules;
    std::vector<std::vector<int>> updates;

    // FileParser::parseRules("example_rules.txt", rules);
    // FileParser::parseUpdates("example_updates.txt", updates);
    FileParser::parseRules("rules.txt", rules);
    FileParser::parseUpdates("updates.txt", updates);

    UpdateAnalyzer updateAnalyzer(rules, updates);

    std::cout << "Sum of middle values of correct updates: " << updateAnalyzer.getCorrectUpdateScore() << std::endl;
    std::cout << "Sum of middle values of corrected updates: " << updateAnalyzer.getCorrectedUpdateScore() <<std::endl;
    return 0;
}