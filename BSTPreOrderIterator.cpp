/*
 * BSTPreOrderIterator.cpp -- implementation of binary search tree pre-order
 *   iterator.
 */
namespace interview {
    template<typename T> BSTPreOrderIterator<T>::BSTPreOrderIterator(
            BinarySearchTree<T> *bst):Iterator<T>() {
        _stack = new Stack<BinaryTreeNode<T> *>();
        if (bst->_root) {
            _stack->push(bst->_root);
        }
    }

    template<typename T> BSTPreOrderIterator<T>::~BSTPreOrderIterator() {
        delete _stack;
    }

    template<typename T> T &BSTPreOrderIterator<T>::next() {
        // TODO: boundary checking!!!
        // throw exception if pop on empty iterator.
        BinaryTreeNode<T> *node = _stack->peek();
        _stack->pop();
        // insert non-empty node in next iteration
        if (node->_right) {
            _stack->push(node->_right);
        }
        if (node->_left) {
            _stack->push(node->_left);
        }

        return node->data();
    }

    template<typename T> bool BSTPreOrderIterator<T>::hasNext() {
        return !_stack->isEmpty();
    }
}
