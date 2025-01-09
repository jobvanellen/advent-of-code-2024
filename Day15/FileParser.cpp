#include "FileParser.hpp"

const std::string FileParser::path = "../../Day15/files/";

void FileParser::parseMap(const std::string& mapFile, std::vector<std::vector<char>>& map)
{
    if(std::ifstream ifs = loadFile(path + mapFile))
    {
        std::string line;
        while (std::getline(ifs, line))
        {
            map.push_back(parseMapRow(line));
        }
    }

    printMap(map);
}

void FileParser::parseMoves(const std::string& movesFile, std::vector<Move>& moves)
{
    if(std::ifstream ifs = loadFile(path + movesFile))
    {
        char moveChar;
        while (ifs >> moveChar)
        {
            switch (moveChar)
            {
                case '^': moves.push_back(Move::UP); break;
                case 'v': moves.push_back(Move::DOWN); break;
                case '<': moves.push_back(Move::LEFT); break;
                case '>': moves.push_back(Move::RIGHT); break;
                default: break;
            }
        }
    }

    printMoves(moves);
}

void FileParser::printMap(const std::vector<std::vector<char>>& map)
{
    std::cout << "Parsed mapfile: " << std::endl;
    for(const auto& mapRow : map )
    {
        for(char symbol : mapRow)
        {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}

void FileParser::printMoves(const std::vector<Move>& moves)
{
    std::cout << "Parsed moves: " << std::endl;
    for(const auto& move : moves)
    {
        switch (move)
        {
            case Move::UP: std::cout << "^ "; break;
            case Move::DOWN: std::cout << "v "; break;
            case Move::LEFT: std::cout << "< "; break;
            case Move::RIGHT: std::cout << "> "; break;
        }
    }
    std::cout << std::endl;
}

std::vector<char> FileParser::parseMapRow(const std::string& line)
{
    std::vector<char> result;
    std::copy(line.begin(), line.end(), std::back_inserter(result));

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