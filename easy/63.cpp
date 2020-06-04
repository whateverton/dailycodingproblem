/*
#63 - EASY
This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS', you should return true, since it's the last row.

Date: 04/06/2020
Dev Time: 00h50 - 1h34 = 44min
*/

#define min(a,b) ((a<b)?a:b)

bool findWord(char* matrix, int size_x, int size_y, const char* target)
{
    int size = strlen(target);
    int *up_down = (int*)calloc(size_x, sizeof(int));

    // Allocation problem, windows are you there?
    if (up_down == nullptr)
        return false;

    // If there's no matching size, doesn't go ahead
    if (size != size_x && size != size_y)
        return false;

    // Check left-to-right first, X axis, so it needs to go Y times
    for (int i = 0; i < size_y; ++i)
    {
        char* offset = matrix + i*4;

        if (!memcmp(offset, target, min(size_x, size)))
        {
            free(up_down);
            return true;
        }

        // Then check up-to-down
        for (int j = 0; j < size_x; ++j)
        {
            if (offset[j] == target[i])
                ++up_down[j];

            if (up_down[j] == size_y)
            {
                free(up_down);
                return true;
            }
        }

    }

    free(up_down);
    return false;
}

#ifdef _63_EASY_
void CurrentSolution()
{
char matrix[4][4] = {{'F', 'A', 'C', 'I'},
                      {'O', 'B', 'Q', 'P'},
                      {'A', 'N', 'O', 'B'},
                      {'M', 'A', 'S', 'S'}};

    // X
    std::cout << "Found FOAM? " << (findWord(matrix[0], 4, 4, "FOAM") ? "Y" : "N") << std::endl;
    std::cout << "Found ABNA? " << (findWord(matrix[0], 4, 4, "ABNA") ? "Y" : "N") << std::endl;
    std::cout << "Found CQOS? " << (findWord(matrix[0], 4, 4, "CQOS") ? "Y" : "N") << std::endl;
    std::cout << "Found IPBS? " << (findWord(matrix[0], 4, 4, "IPBS") ? "Y" : "N") << std::endl;

    // Y
    std::cout << "Found FACI? " << (findWord(matrix[0], 4, 4, "FACI") ? "Y" : "N") << std::endl;
    std::cout << "Found OBQP? " << (findWord(matrix[0], 4, 4, "OBQP") ? "Y" : "N") << std::endl;
    std::cout << "Found ANOB? " << (findWord(matrix[0], 4, 4, "ANOB") ? "Y" : "N") << std::endl;
    std::cout << "Found MASS? " << (findWord(matrix[0], 4, 4, "MASS") ? "Y" : "N") << std::endl;

    // Not there
    std::cout << "Found FACE? " << (findWord(matrix[0], 4, 4, "FACE") ? "Y" : "N") << std::endl;
    
    // Backwards
    std::cout << "Found BONA? " << (findWord(matrix[0], 4, 4, "BONA") ? "Y" : "N") << std::endl;

}
#endif