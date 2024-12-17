#include "FileParser.hpp"
#include <iterator>

const std::string FileParser::path = "../../Day11/files/";

void FileParser::parseFile(const std::string& file, std::vector<unsigned long int>& output)
{
    if(std::ifstream ifs = loadFile(path + file))
    {
        std::string line;
        while (std::getline(ifs, line)) {
     
            std::istringstream iss(line);

            int value;
            while (iss >> value) {           
                output.push_back(value);
            }

        }
    }

    for( int i : output)
    {
        std::cout << i << " ";
    }
        std::cout << std::endl;
}


std::ifstream FileParser::loadFile(const std::string& filename)
{    
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return stream;
}