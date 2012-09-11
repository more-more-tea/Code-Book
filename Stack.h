/*
 * Stack.h
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>

namespace interview {
    template<typename T> struct StackNode {
        T data;
        StackNode *next;

        StackNode(T data, StackNode *next) {
            this->data = data;
            this->next = next;
        }
    };

    template<typename T> class Stack {
        template<typename U> friend void printStack(std::ostream &, Stack<U> &);
    public:
        /* constructor */
        Stack();
        ~Stack();

        bool isEmpty() const;
        T pop();
        T peek() const;
        void push(T data);

        void clearAll();
        /* iterator */
        /* generally speaking, there is no iterator on stack */
    private:
        StackNode<T> *_top;
    };
}

#include "Stack.cpp"

#endif
