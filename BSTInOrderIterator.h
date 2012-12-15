/*
 * BSTInOrderIterator.h -- inorder traversal iterator
 */
#ifndef BSTINITER_H
#define BSTINITER_H

#include "BinarySearchTree.h"
#include "Stack.h"

namespace interview {
    template<typename T> class BSTInOrderIterator:Iterator<T> {
    public:
        BSTInOrderIterator(BinarySearchTree<T> *bst);
        ~BSTInOrderIterator();

        // interface
        T &next();
        bool hasNext();

    private:
        Stack<BinaryTreeNode<T> *> *_stack;
    };
}

#endif       // BSTINITER_H
