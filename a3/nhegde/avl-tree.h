#ifndef SYDE223_A3_AVL_TREE_H
#define SYDE223_A3_AVL_TREE_H

#include "binary-search-tree.h"

class AVLTree: public BinarySearchTree
{
public:
    // Overriden insert and remove functions
    // Do not modify these definitions

    //The AVL tree should be kept balanced after calling just insert or remove.
    bool insert(DataType val);
    bool remove(DataType val);

    // Define additional functions and attributes below if you need
private:
    int findDiff(Node* node);
    void checkBalance(Node* node);
    void singleLeft(Node* parent);
    void singleRight(Node* parent);
    void leftRight(Node* parent);
    void rightLeft(Node* parent);
};

#endif //SYDE223_A3_AVL_TREE_H
