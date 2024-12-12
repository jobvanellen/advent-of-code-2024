#include "FileParser.hpp"

const std::string FileParser::path = "../../Day7/files/";

void FileParser::parseEquationFile(const std::string& equationFile, std::vector<std::vector<unsigned long int>>& equations)
{
    if(std::ifstream ifs = loadFile(path + equationFile))
    {
        std::string line;
        while (std::getline(ifs, line))
        {
            equations.push_back(parseEquation(line));
        }
    }

//     std::cout << "Parsed equations: " << std::endl;
//     for(const auto& equation : equations )
//     {   
//         std::string separator = ": ";
//         for(unsigned long int number : equation)
//         {
//             std::cout << number << separator;
//             separator = " ";
//         }
//         std::cout << std::endl;
//     }
}

std::vector<unsigned long int> FileParser::parseEquation(const std::string& line)
{
    std::istringstream iss(line);
    std::vector<unsigned long int> result;

    while(!iss.eof() && !iss.bad())
    {
        unsigned long int n;
        iss >> n;
 
        if (iss.fail())
        {
            iss.clear();
            iss.ignore(max_size, ':');
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