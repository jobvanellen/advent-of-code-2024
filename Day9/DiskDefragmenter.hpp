#pragma once
#include <vector>
#include <list>

struct MemoryBlock
{
    int id;
    int size;
};

class DiskDefragmenter
{
    public:
    DiskDefragmenter(const std::vector<int>& disk);
    
    void rearrangeFileFragments(std::vector<int>& rearranged);
    void rearrangeWholeFiles(std::vector<int>& rearranged);
    void createMemoryBlocks(const std::vector<int>& diskMap);

    private: 
    std::vector<int>::reverse_iterator getFileEnd(std::vector<int>::reverse_iterator riter);
    std::vector<int>::iterator getGapBegin(std::vector<int>::iterator iter);
    int getFileSize(std::vector<int>::reverse_iterator riter, int id, std::vector<int>::reverse_iterator rend);
    int getGapSize(std::vector<int>::iterator iter, std::vector<int>::iterator end);

    std::list<MemoryBlock> _memoryBlocks;
    const std::vector<int>& _disk;
};