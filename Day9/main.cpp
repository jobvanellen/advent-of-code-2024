#include "FileParser.hpp"
#include "DiskDefragmenter.hpp"

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

unsigned long int calculateChecksum(const std::vector<int>& rearranged)
{
    unsigned long int sum = 0;
    for(int i = 0; i < rearranged.size(); i++)
    {
        if(rearranged.at(i) == -1)
        {
            continue;
        }
        sum += i * rearranged.at(i);
    }
    return sum;
}

int main()
{
    std::vector<int> diskmap;
    // FileParser::parseDiskmap("example_diskmap.txt", diskmap);
    FileParser::parseDiskmap("diskmap.txt", diskmap);

    std::vector<int> decompressed;
    decompressDiskMap(diskmap, decompressed);

    DiskDefragmenter defragmenter = DiskDefragmenter(decompressed);

    std::vector<int> rearranged;
    defragmenter.rearrangeFileFragments(rearranged);

    std::cout << "Checksum: " << calculateChecksum(rearranged) << std::endl;

    defragmenter.createMemoryBlocks(diskmap);
    std::vector<int> rearrangedWhole;

    defragmenter.rearrangeWholeFiles(rearrangedWhole);

    std::cout <<"Checksum: " << calculateChecksum(rearrangedWhole) << std::endl;



    return 0;
}