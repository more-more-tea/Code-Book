/*
 * BSTPostOrderIterator.h -- post-order traversal iterator
 */
#ifndef BSTPSTITER_H
#define BSTPSTITER_H

#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
#include "Stack.h"

namespace interview {
    template<typename T> class BSTPostOrderIterator:Iterator<T> {
    public:
        BSTPostOrderIterator(BinarySearchTree<T> *bst);
        ~BSTPostOrderIterator();

        // interface
        T &next();
        bool hasNext();

    private:
        Stack<BinaryTreeNode<T> *> *_stack;
    };
}

#endif         // BSTPOSTITER_H
