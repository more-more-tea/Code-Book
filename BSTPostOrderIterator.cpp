/*
 * BSTPostOrderIterator.cpp -- implementation post-order traversal iterator
 */
namespace interview {
    // extend iterator class
    // define some auxilary data structure
    template<typename T> class ExtendedBinaryTreeNode : public
            BinaryTreeNode<T> {
        friend class BSTPostOrderIterator<T>;
    public:
        ExtendedBinaryTreeNode(BinaryTreeNode<T> *node) :
                BinaryTreeNode<T>(node->data(), node->left(),
                    node->right()),
                _book_keeper(0) {
        }
        ~ExtendedBinaryTreeNode() {}
    private:
        int _book_keeper;
    };

    template<typename T> BSTPostOrderIterator<T>::BSTPostOrderIterator(
            BinarySearchTree<T> *bst) : Iterator<T>() {
        BinaryTreeNode<T> *cursor = bst->_root;
        while (cursor) {
            _stack.push(new ExtendedBinaryTreeNode<T>(cursor));
            cursor = cursor->_left;
        }
    }

    template<typename T> BSTPostOrderIterator<T>::~BSTPostOrderIterator() {
        // release all newly created dynamic object
        while (!_stack.isEmpty()) {
            ExtendedBinaryTreeNode<T> *node = _stack.peek();
            _stack.pop();
            delete node;
        }
    }

#include <iostream>

    template<typename T> T &BSTPostOrderIterator<T>::next() {
        BinaryTreeNode<T> *next = NULL;
        while (!next) {
            ExtendedBinaryTreeNode<T> *node =
                dynamic_cast<ExtendedBinaryTreeNode<T> *>(_stack.peek());
            if (node->_book_keeper == 0) {
                node->_book_keeper++;
                BinaryTreeNode<T> *cursor = node->_right;
                while (cursor) {
                    _stack.push(new ExtendedBinaryTreeNode<T>(cursor));
                    cursor = cursor->_left;
                }
            } else {
                _stack.pop();
                next = node;
            }
        }

        return next->data();
    }

    template<typename T> bool BSTPostOrderIterator<T>::hasNext() {
        return !_stack.isEmpty();
    }
}
