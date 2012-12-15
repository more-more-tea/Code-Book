/*
 * Tree.h -- abstract interfaces for tree data structure
 */
#ifndef TREE_H
#define TREE_H

namespace interview {
    template<typename T, typename U> class Tree {
    public:
        // get object by key
        virtual U *get(T &key) = 0;
        // insert object into tree
        virtual bool add(T &key, U *satellite) = 0;
    };
}

#endif    // TREE_H
