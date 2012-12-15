/*
 * Iterator.h -- abstract interfaces for iterator
 */
#ifndef ITERATOR_H
#define ITERATOR_h

namespace interview {
    template<typename T> class Iterator {
    public:
        // return true if the underlying data structure has more elements
        bool hasNext();
        // return object under cursor currently
        T &next();
    };
}

#endif
