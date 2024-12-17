#pragma once

#include <utility>
#include <vector>
#include <set>

class Stone
{
    public:
    Stone(int value);
    
    int value() const;
    

    private:
    int _value;
};