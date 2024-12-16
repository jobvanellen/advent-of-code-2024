#include "FileParser.hpp"

#include <map>
#include <set>
#include <utility>

void decompressDiskMap(const std::vector<int> diskmap, std::vector<int>& decompressed)
{
    bool file = true;
    int filenumber = 0;
    for(int n : diskmap)
    {
        for(int i = 0; i < n; i++)
        {
            decompressed.push_back(file ? (filenumber) : -1);    
        }

        if(file)
        {
            filenumber++;
        }
        file = ! file;
    }
}

void rearrangeFiles(const std::vector<int>& decompressed, std::vector<int>& rearranged)
{
    rearranged = decompressed;

    auto iter = rearranged.begin();
    auto riter = rearranged.rbegin();

    while(iter != rearranged.end())
    {
        while(*iter != -1 )
        {
            iter++;
        }



        if(iter > riter.base() - 1)
        {
            break;
        }

        *iter = *riter; 
        *riter = -1;       
    }
    
}

void rearrangeWholeFiles(const std::vector<int>& decompressed, std::vector<int>& rearranged)
{
    rearranged = decompressed;

    auto iter = rearranged.begin();
    auto riter = rearranged.rbegin();

    int gapsize = 0;
    int filesize = 0;

    while(*iter != -1 )
    {
        iter++;
        gapsize++;
    }

    // find a file that fits the gap
    while(*riter == -1)
    {
        riter++;
        filesize++;
    }
}

unsigned long int calculateChecksum(const std::vector<int>& rearranged)
{
    unsigned long int sum = 0;
    for(int i = 0; i < rearranged.size(); i++)
    {
        if(rearranged.at(i) == -1)
        {
            break;
        }
        sum += i * rearranged.at(i);
    }
    return sum;
}

int main()
{
    std::vector<int> diskmap;
    FileParser::parseDiskmap("example_diskmap.txt", diskmap);
    // FileParser::parseDiskmap("diskmap.txt", diskmap);

    std::vector<int> decompressed;
    decompressDiskMap(diskmap, decompressed);

    std::vector<int> rearranged;
    rearrangeFiles(decompressed, rearranged);

    std::vector<int> rearrangedWhole;
    rearrangeWholeFiles(decompressed, rearrangedWhole);


    std::cout << "Checksum: " << calculateChecksum(rearranged) << std::endl;
    std::cout << "Checksum: " << calculateChecksum(rearrangedWhole) << std::endl; 


    return 0;
}