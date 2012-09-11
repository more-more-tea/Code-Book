/* LinkedList.h -- implementation of a linked list
 *
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "List.h"

namespace interview {
    template<typename T> struct ListNode {
    public:
        ListNode(ListNode<T> *prev, ListNode<T> *next, T &data);

        ListNode *prev;                     /* pointer to previous node */
        ListNode *next;                     /* pointer to next node */
        T        data;
    };

    template<typename T> class LinkedList: public List<T> {
    public:
        LinkedList();
        virtual ~LinkedList();
        virtual void insert(T &);
        virtual void append(T &);
        virtual bool find(T &);
        bool isEmpty();
        virtual bool remove(T &);
        
        int  size();

        /* iterator */
        void begin();
        virtual T next();
        virtual bool hasNext();

    private:
        ListNode<T> *_head;
        ListNode<T> *_tail;

        ListNode<T> *_iterator;              /* iterator */
    };

    template<typename T> void dumpList(LinkedList<T> *list) {
        ListNode<T> *iterator = NULL;

        list->begin();
        std::cout << "[";
        while (list->hasNext()) {
            iterator = list->next();
            std::cout << "(" << iterator->prev << "|" << iterator->data
                      << "|" << iterator->next << ")->";
        }
        std::cout << "NULL]" << std::endl;
    }

}
#include "LinkedList.cpp"    

#endif
