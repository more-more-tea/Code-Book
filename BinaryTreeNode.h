/*
 * BinaryTreeNode.h -- interface for binary tree node
 */

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

namespace interview {
    template<typename T, typename U> class BinaryTreeNode {
    // friend declaration
    friend template<typename T, typename U> class BinarySearchTree;

    public:
        // constructor
        BinaryTreeNode(void);
        BinaryTreeNode(U &key, T *data,
                       BinaryTreeNode<T, U> left,
                       BinaryTreeNode<T, U> right);

        // get left child
        inline BinaryTreeNode<T, U> left();
        // get right child
        inline BinaryTreeNode<T, U> right();
        // get satellite data
        inline U &data();

    private:
        T  _key;                         // key of the satellite data object
        U &_satellite;

        BinaryTreeNode<T, U> *_left;
        BinaryTreeNode<T, U> *_right;
    };
}

#include "BinaryTreeNode.cpp"
#endif       // BINARY_TREE_NODE_H
