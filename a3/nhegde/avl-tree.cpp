#include "avl-tree.h";
using namespace std;

// INSERT
bool AVLTree::insert(DataType val)
{
    // Insert as BST
    if (!BinarySearchTree::insert(val)) {
        return false;
    }

    // Check balance and fix issues
    Node* root = getRootNode();
    checkBalance(root);

    return true;
}

//REMOVE
bool AVLTree::remove(DataType val)
{
    // Remove as BST
    if(!BinarySearchTree::remove(val)) {
        return false;
    }

    // Check balance and fix issues
    Node* root = getRootNode();
    checkBalance(root);

    return true;
}

// CHECKERS & BALANCE FIXERS

// Used to find height difference between the subtrees of a node
int AVLTree::findDiff(Node* node) {
    int leftTree = 0;
    int rightTree = 0;

    if (node->left != nullptr) {
        updateNodeBalance(node->left); // updates height in avlBalance
        leftTree = node->left->avlBalance + 1;
    }

    if (node->right != nullptr) {
        updateNodeBalance(node->right);
        rightTree = node->right->avlBalance + 1;
    }

    return leftTree - rightTree;
}

// Checks if the tree is balanced, if not, determine which rotator to use
void AVLTree::checkBalance(Node* node) {
    // Implement stack architecture and call tree from bottom up
    // can make O(log(n)) but do not have access to predecessor value
    if (node == nullptr) return;
    checkBalance(node->right);
    checkBalance(node->left);

    int primaryHeightDiff = findDiff(node); // collects initial height difference

    // check if tree is unbalanced (initial height difference (absolute value) > 1)
    if (primaryHeightDiff > 1) { // left subtree is larger
        int secondaryHeightDiff = findDiff(node->left); // collects height difference of larger child node
        // if the larger child node (children wise) has a larger left subtree, use single right rotation
        // else, use left right to balance
        if (secondaryHeightDiff >= 0) {
            singleRight(node);
        } else {
            leftRight(node);
        }
    } else if (primaryHeightDiff < -1) { // right subtree is larger
        int secondaryHeightDiff = findDiff(node->right);
        // if the larger child node (children wise) has a larger left subtree, use right left rotation
        // else, use single left to balance
        if (secondaryHeightDiff > 0) {
            rightLeft(node);
        } else {
            singleLeft(node);
        }
    }
}

// ROTATORS

void AVLTree::singleLeft(Node* parent) {
    Node* leftNode = new Node(parent->val);
    leftNode->left = parent->left;
    leftNode->right = parent->right->left;
    parent->val = parent->right->val;
    parent->left = leftNode;
    parent->right = parent->right->right;
}

void AVLTree::singleRight(Node* parent) {
    Node* rightNode = new Node(parent->val);
    rightNode->right = parent->right;
    rightNode->left = parent->left->right;
    parent->val = parent->left->val;
    parent->right = rightNode;
    parent->left = parent->left->left;
}

void AVLTree::leftRight(Node* parent) {
    singleLeft(parent->left);
    singleRight(parent);
}

void AVLTree::rightLeft(Node* parent) {
    singleRight(parent->right);
    singleLeft(parent);
}

