/*
 * AdjacentGraph.h -- an adjacent graph implementation
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#ifndef ADJACENTGRAPH_H
#define ADJACENTGRAPH_H

#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"

namespace interview {
    template<typename WeightType, typename DataType>
    class AdjacentGraph:public Graph<WeightType, DataType> {
        template<typename T, typename U> friend void printAdjacentGraph
            (std::ostream &, AdjacentGraph<T, U> &);
    public:
        AdjacentGraph();
        ~AdjacentGraph();

        Vertex<DataType> *getVertex(std::string &);

        bool addVertex(Vertex<DataType> *vertex);
        bool addEdge(Edge<WeightType, DataType> *edge);
        bool removeVertex(Vertex<DataType> *vertex);
        bool removeEdge(Edge<WeightType, DataType> *edge);
        WeightType changeEdgeWeight(Edge<WeightType, DataType> *,
             WeightType);

        /* begin Broad-First-Search on the graph from specified vertex */
        void BFSBegin(const std::string &);
        bool BFSHasNext();
        Vertex<DataType> *BFSNext();

        /* begin Depth-First-Search on the graph from specified vertex */
        void DFSBegin(const std::string &);
        bool DFSHasNext();
        Vertex<DataType> *DFSNext();

        AdjacentGraph<WeightType, DataType> &
        operator=(AdjacentGraph<WeightType, DataType> &g);

    private:
        List<Vertex<DataType> &> *_vertices;
        List<Edge<WeightType, DataType> &> *_edges;
        Queue<Vertex<DataType> *> *_BFSCache;
        Stack<Vertex<DataType> *> *_DFSCache;
    };
}

#include "AdjacentGraph.cpp"

#endif
