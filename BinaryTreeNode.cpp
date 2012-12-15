/*
 * BinaryTreeNode.cpp -- implementation of binary tree node
 */
namespace interview {

    template<typename T>
    BinaryTreeNode<T>::BinaryTreeNode(void)
            : _satellite(NULL), _left(NULL), _right(NULL) {
    }

    template<typename T>
    BinaryTreeNode<T>::BinaryTreeNode(T &data,
                                      BinaryTreeNode<T> *left,
                                      BinaryTreeNode<T> *right)
            : _satellite(data), _left(left), _right(right){
    }

    template<typename T>
    BinaryTreeNode<T> *BinaryTreeNode<T>::left() {
        return _left;
    }

    template<typename T>
    BinaryTreeNode<T> *BinaryTreeNode<T>::right() {
        return _right;
    }

    template<typename T>
    T &BinaryTreeNode<T>::data() {
        return _satellite;
    }
}
