/*
#13 - HARD

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.

Date: 06/07/2020
*/
#ifdef VS_IDE
#include "helper.h"
#endif

#include <string>
/*
struct SystemNode {
    std::string name = "";
    size_t subLevel = 0;
    bool file = false;
};

size_t getNextSubLevel(std::string fileSys) {
    size_t sub = 0;

    for (size_t i = 0; i < fileSys.size(); i++)
    {
        if (fileSys[i] == '\t')
            sub++;
        else
            break;
    }

    return sub;
}

SystemNode* getLastFromLevel(std::vector<SystemNode*>& arr, size_t level) {
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i]->subLevel == level - 1)
            return arr[i];
    }

    return nullptr;
}

void constructArray2(const std::string& s, std::vector<SystemNode*>& elems)
{
    std::stringstream ss(s + ' ');
    std::string item;
    while (std::getline(ss, item, '\n'))
    {
        SystemNode* nnode = new SystemNode();
        nnode->subLevel = getNextSubLevel(item);
        nnode->name = item.substr(nnode->subLevel);
        nnode->file = (nnode->name.find('.') != std::string::npos);

        elems.push_back(nnode);
    }
}

std::string hard_17(std::string fileSys) {
    std::vector<SystemNode*> subStringLevels;
    constructArray2(fileSys, subStringLevels);

    std::string longestPath;
    for (int i = subStringLevels.size() - 1; i >= 0; i--)
    {
        //if finds a childs, get the first (in reverse order) from one level deeper.
        if (subStringLevels[i]->file) {
            std::string currPath = subStringLevels[i]->name;
            SystemNode* currNode = subStringLevels[i];

            while (currNode->subLevel != 0) {
                currNode = getLastFromLevel(subStringLevels, currNode->subLevel);

                currPath.insert(0, "/");
                currPath.insert(0, currNode->name.c_str());
            }

            if (currPath.size() > longestPath.size())
                longestPath = currPath;
        }
    }

    return longestPath;
}
*/
#ifdef VS_IDE
void problem17()
#else
void main()
#endif
{/*
    std::string dir1 = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    std::cout << "Dir 1: " << hard_17(dir1) << std::endl;
    std::cout << "Expected result Dir 1: " << "dir/subdir2/subsubdir2/file2.ext" << std::endl;
*/
}
