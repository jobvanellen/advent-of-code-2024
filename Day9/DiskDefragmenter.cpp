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
        while(*iter != -1 )
        {
            iter++;
        }

        while(*riter == -1 )
        {
            riter++;
        }

        if(iter > riter.base() - 1)
        {
            break;
        }

        *iter = *riter; 
        *riter = -1;       
    }
}
