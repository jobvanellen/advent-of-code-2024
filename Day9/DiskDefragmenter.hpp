#pragma once
#include <vector>

class DiskDefragmenter
{
    public:
    DiskDefragmenter(const std::vector<int>& disk);
    
    void rearrangeFileFragments(std::vector<int>& rearranged);

    private: 
    std::vector<int>::reverse_iterator getFileEnd(std::vector<int>::reverse_iterator riter);
    std::vector<int>::iterator getGapBegin(std::vector<int>::iterator iter);
    

    const std::vector<int>& _disk;
};