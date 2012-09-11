/*
 * Queue.h
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

namespace interview {
    template<typename T> struct QueueNode {
        T data;
        QueueNode<T> *next;

        QueueNode(T data, QueueNode<T> *next) {
            this->data = data;
            this->next = next;
        }
    };

    template<typename T> class Queue {
       template<typename U> friend void printQueue (std::ostream &, Queue<U> &);
    public:
        Queue();
        ~Queue();

        bool isEmpty() const;
        void enqueue(T);
        T dequeue();

        void clearAll();
    private:
        QueueNode<T> *_head;
        QueueNode<T> *_tail;
    };
}

#include "Queue.cpp"

#endif
