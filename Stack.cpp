/*
 * Stack.cpp
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#include <iostream>

namespace interview {
    template<typename T> Stack<T>::Stack():_top(NULL) {}
    template<typename T> Stack<T>::~Stack() {
        clearAll();
    }

    template<typename T> bool Stack<T>::isEmpty() const {
        return (_top== NULL);
    }

    template<typename T> T Stack<T>::pop() {
        T data;
        if (_top) {
            StackNode<T> *tmp = _top;

            data = _top->data;
            _top= _top->next;

            delete tmp;
        }
        return data;
    }

    template<typename T> T Stack<T>::peek() const {
        T data;

        if (_top) {
            data = _top->data;
        }

        return data;
    }

    template<typename T> void Stack<T>::push(T data) {
        _top= new StackNode<T>(data, _top);
    }

    template<typename T> void Stack<T>::clearAll() {
        StackNode<T> *itr = NULL;
        while (_top) {
            itr = _top;
            _top= _top->next;
            delete itr;
        }
    }

    template<typename T> void printStack(std::ostream &output,
            Stack<T> &stack) {
        StackNode<T> *cursor = stack._top;

        while (cursor) {
            output << cursor->data << " ";
            cursor = cursor->next;
        }
    }
}
