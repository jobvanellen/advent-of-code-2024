#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

enum class Move
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class FileParser
{
    public:
        FileParser() = delete;
        static void parseMap(const std::string& mapFile, std::vector<std::vector<char>>& map);
        static void parseMoves(const std::string& movesFile, std::vector<Move>& moves);
        static void printMap(const std::vector<std::vector<char>>& map);

    private:
        static std::vector<char> parseMapRow(const std::string& line);
        static std::ifstream loadFile(const std::string& filename);
        static void printMoves(const std::vector<Move>& moves);

        static const std::string path;
};