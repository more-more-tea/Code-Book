/*
 * BSTInOrderIterator.cpp -- implementation in-order traversal iterator
 */
namespace interview {
    template<typename T> BSTInOrderIterator<T>::BSTInOrderIterator(
            BinarySearchTree<T> *bst) : Iterator<T>() {
        BinaryTreeNode<T> *cursor = bst->_root;
        while (cursor) {
            _stack.push(cursor);
            cursor = cursor->_left;
        }
    }

    template<typename T> BSTInOrderIterator<T>::~BSTInOrderIterator() {}

#include <iostream>
    template<typename T> T &BSTInOrderIterator<T>::next() {
        BinaryTreeNode<T> *node   = _stack.peek();
        _stack.pop();
        BinaryTreeNode<T> *cursor = node->_right;
        while (cursor) {
            _stack.push(cursor);
            cursor = cursor->_left;
        }

        return node->data();
    }

    template<typename T> bool BSTInOrderIterator<T>::hasNext() {
        return !_stack.isEmpty();
    }
}
