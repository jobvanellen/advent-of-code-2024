#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <limits>

class FileParser
{
    public:
        FileParser() = delete;
        static void parseRules(const std::string& ruleFile, std::vector<std::pair<int, int>>& rules);
        static void parseUpdates(const std::string& updateFile, std::vector<std::vector<int>>& updates);

    private:
        static std::pair<int, int> parseRule(const std::string& line);
        static std::vector<int> parseUpdate(const std::string& line);
        static std::ifstream loadFile(const std::string& filename);

        static constexpr auto max_size  = std::numeric_limits<std::streamsize>::max();
        static const std::string path;


};