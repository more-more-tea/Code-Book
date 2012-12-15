/*
 * BinaryTreeNode.cpp -- implementation of binary tree node
 */
namespace interview {

    template<typename T, typename U>
    BinaryTreeNode<T, U>::BinaryTreeNode(void) {
        // empty tree node
        _satellite = NULL;
        _left  = NULL;
        _right = NULL;
    }

    template<typename T, typename U>
    BinaryTreeNode<T, U>::BinaryTreeNode(U &key, T *data,
                                         BinaryTreeNode<T, U> left,
                                         BinaryTreeNode<T, U> right) {
        _key = key;
        _satellite = data;
        _left  = left;
        _right = right;
    }

    template<typename T, typename U>
    BinaryTreeNode<T, U> *BinaryTreeNode<T, U>::left() {
        return _left;
    }

    template<typename T, typename U>
    BinaryTreeNode<T, U> *BinaryTreeNode<T, U>::right() {
        return _right;
    }

    template<typename T, typename U>
    U *BinaryTreeNode<T, U>::data() {
        return _satellite;
    }

}
