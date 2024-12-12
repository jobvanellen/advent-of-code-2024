
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>

bool active = true;

std::pair<int, int> parseMatch(std::string mulString)
{
    std::istringstream stream(mulString);

    char symbol;
    do
    {
        symbol = stream.get();
    } 
    while (symbol != '(');

    symbol = stream.get();
    std::string num1 = "";
    do{
        num1 += symbol;
        symbol = stream.get();
    }
    while(symbol != ',');
    // std::cout << num1 << std::endl;

    symbol = stream.get();
    std::string num2 = "";
    do{
        num2 += symbol;
        symbol = stream.get();
    }
    while(symbol != ')');
    // std::cout << num2 << std::endl;

    return {std::stoi(num1), std::stoi(num2)};

}

int mul(std::pair<int, int> values)
{
    return values.first * values.second;
}

std::string getStringUntil(std::string& line, std::string marker)
{
   std::string::size_type index = line.find(marker);
   if(index == std::string::npos)
   {
        return line;
   }
   return line.substr(0, index);
}

int getSubstringSum(std::string substring)
{
    std::regex matchPhrase(R"(mul\((\d*),(\d*)\))");
    int sum = 0;
    auto begin = std::sregex_iterator(substring.begin(), substring.end(), matchPhrase);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; i++) {
        std::smatch match = *i;        
        std::pair<int, int> values = parseMatch(match.str());
        sum += mul(values);
    }
    return sum;
}

int getLineSum(std::string& line)
{
    int sum = 0;

    std::string substring = "";
    while(substring != line)
    {
        if(active)
        {
            substring = getStringUntil(line, "don't()");
            sum += getSubstringSum(substring);
        }
        else
        {
            substring = getStringUntil(line, "do()");
        }
        line.erase(0, substring.size());
        active = !active;
    }
    
    return sum;
}

int main()
{
    std::ifstream file("input.txt");

    std::string line;
    int sum = 0;

    while (std::getline(file, line)) {
        sum += getLineSum(line);
    }

    std::cout << sum << std::endl;

    return 0;
}