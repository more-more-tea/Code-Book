/*
 * Tree.h -- abstract interfaces for tree data structure
 */
#ifndef TREE_H
#define TREE_H

namespace interview {
    template<typename T> class Tree {
    public:
        // insert object into tree
        virtual bool add(T &data) = 0;
        // delete object specified by key
        virtual bool del(T &data) = 0;

        virtual ~Tree() {};
    };
}

#endif    // TREE_H
