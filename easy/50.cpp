/*
#50 - EASY
This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

	*
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).

Date: 28/05/2020
Dev Time: 18h16 - 18h47 = 31min
*/
#include <string.h>

namespace e50 {
    typedef struct myTree
    {
        std::string value;
        myTree* left;
        myTree* right;
    }myTree;

    myTree branch6 = { "5", NULL, NULL };
    myTree branch5 = { "4", NULL, NULL };
    myTree branch4 = { "2", NULL, NULL };
    myTree branch3 = { "3", NULL, NULL };
    myTree branch2 = { "+", &branch5, &branch6 };
    myTree branch1 = { "+", &branch3, &branch4 };
    myTree root = { "*", &branch1, &branch2 };

    int calculateTree(myTree* node)
    {
        int a, b, res;

        // both null, true leaf
        if (!node->left && !node->right)
        {
            return atoi(node->value.c_str());
        }

        if (node->left)
        {
            a = calculateTree(node->left);

            // If theres no matching leaf, don't even calculate
            if (!node->right)
                return a;
        }

        if (node->right)
        {
            b = calculateTree(node->right);

            // If theres no matching leaf, don't even calculate
            if (!node->left)
                return b;
        }

        switch (node->value.c_str()[0])
        {
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        }

        return res;
    }

};

#ifdef _50_EASY_
void CurrentSolution()
{
    std::cout << "Tree result: " << e50::calculateTree(&e50::root) << std::endl;
}
#endif