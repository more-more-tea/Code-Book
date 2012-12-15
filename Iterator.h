/*
 * Iterator.h -- abstract interfaces for iterator
 */
#ifndef ITERATOR_H
#define ITERATOR_H

namespace interview {
    template<typename T> class Iterator {
    public:
        // return true if the underlying data structure has more elements
        virtual bool hasNext() = 0;
        // return object under cursor currently
        virtual T &next() = 0;
    };
}

#endif
