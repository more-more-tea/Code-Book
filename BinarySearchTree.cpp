/*
 * BinarySearchTree.cpp -- implementation of interfaces
 */
#include "Queue.h"

namespace interview {
    template<typename T>
    BinarySearchTree<T>::BinarySearchTree(void)
            : Tree<T>(), _root(NULL) {
    }

    template<typename T>
    BinarySearchTree<T>::~BinarySearchTree(void) {
        // release all the node row by row
        Queue<BinaryTreeNode<T> *> q;
        if (_root) {
            q.enqueue(_root);
        }

        while (!q.isEmpty()) {
            BinaryTreeNode<T> *node = q.dequeue();
            if (node->_left) {
                q.enqueue(node->_left);
            }
            if (node->_right) {
                q.enqueue(node->_right);
            }
            delete node;
        }
    }

    template<typename T> bool
    BinarySearchTree<T>::add(T &data) {
        bool succ = true;
        BinaryTreeNode<T> **prev = &_root;
        while (*prev) {
            T &prev_data = (*prev)->data();
            if (data > prev_data) {
                // data is larger than current key, turn right
                prev = &((*prev)->_right);
            } else if (data < prev_data) {
                // data is smaller than current key, turn left
                prev = &((*prev)->_left);
            } else {
                // duplicated keys
                succ = false;
                break;
            }
        }

        if (succ) {
            *prev = new BinaryTreeNode<T>(data, NULL, NULL);
        }

        return succ;
    }

    template<typename T> bool
    BinarySearchTree<T>::del(T &data) {
        bool succ = false;
        BinaryTreeNode<T> **pnode = this->find(data);

        if (*pnode) {
            // find largest node in left sub-tree
            if ((*pnode)->_left) {
                // left sub-tree is not empty
                // find largest tree node in left sub-tree
                BinaryTreeNode<T> **largest_left = &(*pnode)->_left;
                BinaryTreeNode<T> **parent = largest_left;
                while ((*largest_left)->_right) {
                    parent = largest_left;
                    largest_left = &(*largest_left)->_right;
                }
                // copy data
                (*pnode)->_satellite = (*largest_left)->_satellite;
                // change link
                *parent = (*largest_left)->_left;
                delete *largest_left;
            } else if ((*pnode)->_right) {
                // right sub-tree is not empty
                BinaryTreeNode<T> **smalest_right = &(*pnode)->_right;
                BinaryTreeNode<T> **parent = smalest_right;
                while ((*smalest_right)->_left) {
                    parent = smalest_right;
                    smalest_right = &(*smalest_right)->_left;
                }
                // copy data
                (*pnode)->_satellite = (*smalest_right)->_satellite;
                // change link
                *parent = (*smalest_right)->_right;
                delete *smalest_right;
            } else {
                // no sub-tree, remove link directly
                delete *pnode;
                *pnode = NULL;
            }
            succ = true;
        }

        return succ;
    }

    template<typename T>
    BinaryTreeNode<T> **BinarySearchTree<T>::find(T &data) {
        BinaryTreeNode<T> **cursor = &_root;
        bool found = false;
        while (*cursor) {
            if (data < (*cursor)->data()) {
                cursor = &(*cursor)->_left;
            } else if (data > (*cursor)->data()) {
                cursor = &(*cursor)->_right;
            } else {
                // found
                break;
            }
        }

        return cursor;
    }

    // pre-order traversal iterator
    template<typename T> Iterator<T> *BinarySearchTree<T>::preorder() {
        return new BSTPreOrderIterator<T>(this);
    }

    // in-order traversal iterator
    template<typename T> Iterator<T> *BinarySearchTree<T>::inorder() {
        return new BSTInOrderIterator<T>(this);
    }

    // post-order traversal iterator
    template<typename T> Iterator<T> *BinarySearchTree<T>::postorder() {
        return new BSTPostOrderIterator<T>(this);
    }
}
