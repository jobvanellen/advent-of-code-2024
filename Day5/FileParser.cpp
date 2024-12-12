#include "FileParser.hpp"
#include <limits>

const std::string FileParser::path = "../../Day5/files/";

void FileParser::parseRules(const std::string& ruleFile, std::vector<std::pair<int, int>>& rules)
{
    if(std::ifstream ifs = loadFile(path + ruleFile))
    {
        std::string line;
        while (std::getline(ifs, line))
        {
            rules.push_back(parseRule(line));
        }
    }

    // std::cout << "Parsed rulefile: " << std::endl;
    // for(const auto& rule : rules )
    // {
    //     std::cout << rule.first << "|" << rule.second << std::endl;
    // }
}

std::pair<int, int> FileParser::parseRule(const std::string& line)
{
    int a,b;
    char sep;
    std::istringstream iss(line);
    iss >> a >> sep >> b;

    return {a,b};
}

void FileParser::parseUpdates(const std::string& updateFile, std::vector<std::vector<int>>& updates)
{
    std::string line;
    if(std::ifstream ifs = loadFile(path + updateFile))
    {
        while (std::getline(ifs, line))
        {
            updates.push_back(parseUpdate(line));
        }
    }

    // std::cout << "Parsed updatefile: " << std::endl;
    // for(const auto& update : updates )
    // {
    //     for(int file : update)
    //     {
    //         std::cout << file << ',';
    //     }

    //     std::cout << std::endl;
    // }
}

std::vector<int> FileParser::parseUpdate(const std::string& line)
{
    std::istringstream iss(line);
    std::vector<int> result;
    while(!iss.eof() && !iss.bad())
    {
        int n;
        iss >> n;
 
        if (iss.fail())
        {
            iss.clear();
            iss.ignore(max_size, ',');
        }
        else{
            result.push_back(n);
        }
    }

    return result;
}

std::ifstream FileParser::loadFile(const std::string& filename)
{    
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return stream;
}