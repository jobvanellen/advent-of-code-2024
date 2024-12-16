#include "DiskDefragmenter.hpp"

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