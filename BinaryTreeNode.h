/*
 * BinaryTreeNode.h -- interface for binary tree node
 */

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

namespace interview {
    template<typename T> class BinarySearchTree;
    template<typename T> class BSTPreOrderIterator;
    template<typename T> class BSTInOrderIterator;
    template<typename T> class BSTPostOrderIterator;

    template<typename T> class BinaryTreeNode {
    // friend declaration
    friend class BinarySearchTree<T>;
    friend class BSTPreOrderIterator<T>;
    friend class BSTInOrderIterator<T>;
    friend class BSTPostOrderIterator<T>;

    public:
        // constructor
        BinaryTreeNode();
        BinaryTreeNode(T &data,
                       BinaryTreeNode<T> *left,
                       BinaryTreeNode<T> *right);

        // get left child
        inline BinaryTreeNode<T> *left();
        // get right child
        inline BinaryTreeNode<T> *right();
        // get satellite data
        inline T &data();

    private:
        T &_satellite;

        BinaryTreeNode<T> *_left;
        BinaryTreeNode<T> *_right;
    };
}

#include "BinaryTreeNode.cpp"
#endif       // BINARY_TREE_NODE_H
