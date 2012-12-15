/*
 * BSTInOrderIterator.h -- inorder traversal iterator
 */
#ifndef BSTINITER_H
#define BSTINITER_H

#include "BinarySearchTree.h"
#include "Stack.h"

namespace interview {
    template<typename T> class BSTInOrderIterator : public Iterator<T> {
    public:
        BSTInOrderIterator(BinarySearchTree<T> *bst);
        ~BSTInOrderIterator();

        // interface
        T &next();
        bool hasNext();

    private:
        Stack<BinaryTreeNode<T> *> _stack;
    };
}

#include "BSTInOrderIterator.cpp"

#endif       // BSTINITER_H
