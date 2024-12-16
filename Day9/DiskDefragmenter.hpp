#pragma once
#include <vector>

class DiskDefragmenter
{
    public:
    DiskDefragmenter(const std::vector<int>& disk);
    
    void rearrangeFileFragments(std::vector<int>& rearranged);

    private: 
    const std::vector<int>& _disk;
};