#include "DiskDefragmenter.hpp"
#include <iostream>

DiskDefragmenter::DiskDefragmenter(const std::vector<int>& disk)
:_disk(disk)
{}

void DiskDefragmenter::rearrangeFileFragments(std::vector<int>& rearranged)
{
    rearranged = _disk;

    auto iter = rearranged.begin();
    auto riter = rearranged.rbegin();

    while(iter != rearranged.end())
    {
        riter = getFileEnd(riter);
        iter = getGapBegin(iter);

        if(iter > riter.base() - 1)
        {
            break;
        }

        *iter = *riter; 
        *riter = -1;       
    }
}

void DiskDefragmenter::createMemoryBlocks(const std::vector<int>& diskMap)
{   
    _memoryBlocks = std::list<MemoryBlock>();
    bool file = true;
    int id = 0;
    for(int n : diskMap)
    {
        if(file)
        {
            _memoryBlocks.emplace_back(MemoryBlock{id,n});
            id++;
        }
        else 
        {
            _memoryBlocks.emplace_back(MemoryBlock{-1, n});
        }
        file = !file;
    }

//     for(const auto& block : _memoryBlocks)
//     {
//         std::cout << block.id << "," << block.size << std::endl;
//     }
}

void DiskDefragmenter::rearrangeWholeFiles(std::vector<int>& rearranged)
{
    auto fileRiter = _memoryBlocks.rbegin();
    int previousId = __INT_MAX__;

    while(fileRiter != _memoryBlocks.rend())
    {
        while((fileRiter->id == -1 || fileRiter->id >= previousId) && fileRiter != _memoryBlocks.rend())
        {
            fileRiter++;
        }
        previousId = fileRiter->id;

        auto gapIter = _memoryBlocks.begin();
        while((gapIter->id != -1 || gapIter->size < fileRiter->size) && gapIter != _memoryBlocks.end())
        {
            gapIter++;
        }

        if(gapIter == _memoryBlocks.end() || std::distance(_memoryBlocks.begin(), gapIter) >= std::distance(fileRiter, _memoryBlocks.rend()))
        {
            continue;
        }

        _memoryBlocks.emplace(gapIter, MemoryBlock{fileRiter->id, fileRiter->size});
        fileRiter->id = -1;
        if(gapIter->size > fileRiter->size)
        {
            int newGapSize = gapIter->size - fileRiter->size;
            _memoryBlocks.emplace(gapIter, MemoryBlock{-1, newGapSize});
        }
        _memoryBlocks.erase(gapIter);
        
    }

    for(const auto& block : _memoryBlocks)
    {
        for (int i = 0;  i < block.size; i++)
        {
            rearranged.push_back(block.id);
        }
    }
}

std::vector<int>::reverse_iterator DiskDefragmenter::getFileEnd(std::vector<int>::reverse_iterator riter)
{
    while(*riter == -1 )
    {
        riter++;
    }
    return riter;   
}

std::vector<int>::iterator DiskDefragmenter::getGapBegin(std::vector<int>::iterator iter)
{
    while(*iter != -1 )
    {
        iter++;
    }
    return iter;
}

int DiskDefragmenter::getFileSize(std::vector<int>::reverse_iterator riter, int id, std::vector<int>::reverse_iterator rend)
{
    int size = 0;
    while(*riter == id && riter != rend)
    {
        size++;
        riter++;
    }
    return size;
}

int DiskDefragmenter::getGapSize(std::vector<int>::iterator iter, std::vector<int>::iterator end)
{
    int size = 0;
    while(*iter == -1 && iter != end)
    {
        size++;
        iter++;
    }
    return size;
}

