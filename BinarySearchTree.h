/*
 * BinarySearchTree.h -- implementation for template BST
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Tree.h"
#include "BinaryTreeNode.h"

#include "BSTPreOrderIterator.h"
#include "BSTInOrderIterator.h"
#include "BSTPostOrderIterator.h"

namespace interview {
    template<typename T> class BinaryTreeNode;

    template<typename T> class BinarySearchTree:Tree<T> {
        // friendship declaration
        friend class BSTPreOrderIterator<T>;
        friend class BSTInOrderIterator<T>;
        friend class BSTPostOrderIterator<T>;

    public:
        virtual bool add(T &data);
        virtual bool del(T &data);
        BinarySearchTree(void);
        ~BinarySearchTree(void);

        // iterator
        // USER should delete the iterator object after use
        Iterator<T> *preorder();
        Iterator<T> *inorder();
        Iterator<T> *postorder();
    private:
        BinaryTreeNode<T> *_root;

        // find binary tree node
        // return the pointer to the pointer pointing to the node
        // in its parent node
        // if returned pointer points to a NULL object
        // object is not found.
        BinaryTreeNode<T> **find(T &data);
    };
}

#include "BinarySearchTree.cpp"

#endif    // BINARY_SEARCH_TREE_H
