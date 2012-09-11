/* List.h -- abstract interface for template list
 *  
 */
#ifndef LIST_H
#define LIST_H

namespace interview {
    template<typename T> class List {
    public:
        virtual bool remove(T &) = 0;
        virtual void insert(T &) = 0;
        virtual void append(T &) = 0;
        virtual bool find(T &) = 0;
        virtual bool isEmpty() = 0;
        virtual int size() = 0;

        /* iterator */
        virtual void begin() = 0;
        virtual bool hasNext() = 0;
        virtual T next() = 0;
    
    protected:
        int _size;                  /* size of list */
    };
}

#endif
