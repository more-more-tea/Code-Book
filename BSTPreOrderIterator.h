/*
 * BSTPreOrderIterator.h -- preorder traversal iterator
 */
#ifndef BSTPREITER_H
#define BSTPREITER_H

#include "Iterator.h"
#include "BinarySearchTree.h"
#include "Stack.h"

namespace interview {
    template<typename T> class BSTPreOrderIterator : public Iterator<T> {
    public:
        BSTPreOrderIterator(BinarySearchTree<T> *bst);
        ~BSTPreOrderIterator();

        // interface
        T &next();
        bool hasNext();
    private:
        Stack<BinaryTreeNode<T> *> *_stack;
    };
}

#include "BSTPreOrderIterator.cpp"

#endif        // BSTPREITER_H
