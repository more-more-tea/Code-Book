/*
 * Queue.cpp
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#include <iostream>

namespace interview {
    template<typename T> Queue<T>::Queue():_head(NULL), _tail(NULL) {}

    template<typename T> Queue<T>::~Queue() {
        clearAll();
    }

    template<typename T> bool Queue<T>::isEmpty() const {
        return (_head == NULL);
    }

    template<typename T> void Queue<T>::enqueue(T data) {
        if (!_head) {
            _head = _tail = new QueueNode<T>(data, NULL);
        } else {
            _tail->next = new QueueNode<T>(data, NULL);
            _tail = _tail->next;
        }
    }

    template<typename T> T Queue<T>::dequeue() {
        T data;
        QueueNode<T> *prev = NULL;
        if (_head) {
            data = _head->data;
            prev = _head;
            _head = _head->next;
            delete  prev;
        }

        return data;
    }

    template<typename T> void Queue<T>::clearAll() {
        QueueNode<T> *itr = NULL;
        while (_head) {
            itr = _head;
            _head = _head->next;
            delete itr;
        }
    }

    template<typename T> void printQueue(std::ostream &output,
            Queue<T> &queue) {
        QueueNode<T> *cursor = queue._head;
        while (cursor) {
            output << cursor->data << " ";
            cursor = cursor->next;
        }
        output << std::endl;
    }
}
