/*
 * BinarySearchTree.h -- implementation for template BST
 */
#include "Tree.h"

#include "BSTPreOrderIterator.h"
#include "BSTInOrderIterator.h"
#include "BSTPostOrderIterator.h"

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

namespace interview {
    template<typename T, typename U> class BinarySearchTreeNode;

    template<typename T, typename U> class BinarySearchTree:Tree<T, U> {
    public:
        virtual U &get(T &key);
        virtual bool add(T &key, U &satellite);

        // iterator
        Iterator<U> preorder();
        Iterator<U> inorder();
        Iterator<U> postorder();
    private:
        BinarySearchTreeNode<T, U> *_root;
    };
}

#include "BinarySearchTree.cpp"

#endif    // BINARY_SEARCH_TREE_H
