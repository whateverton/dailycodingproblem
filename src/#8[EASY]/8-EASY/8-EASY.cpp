/*

Original e-mail:

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

Proposed by: Anderson
Date: 03/04/2020
Dev Time: 40min
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct myTree
{
    int value;
    myTree* left;
    myTree* right;
}myTree;

myTree branch4 = { 0, NULL, NULL };
myTree branch6 = { 1, NULL, NULL };
myTree branch5 = { 1, NULL, NULL };
myTree branch3 = { 1, &branch5, &branch6 };
myTree branch2 = { 0, &branch3, &branch4 };
myTree branch1 = { 1, NULL, NULL };
myTree root = { 0, &branch1, &branch2 };

int count_tree = 0;

void isUnivalTree(int value, myTree* tree)
{
    if (tree == NULL)
        return;
    
    isUnivalTree(tree->value, tree->left);
    isUnivalTree(tree->value, tree->right);

    if (tree->value == value)
        ++count_tree;
}

int main(int argc, char** argv)
{
    isUnivalTree(root.value, &root);

    cout << "Total unival subtrees: " << count_tree << endl;

    return 0;
}
