/*
 * Graph -- abstract interface for graph
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "LinkedList.h"

#define UNDEF_TAG  -1

namespace interview {
    template<typename T, typename D> struct Edge;
    template<typename D> struct Vertex {
        D     data;
        /* tricks on all graph algortihm is howto devise an efficient
         * tag, it is useful to declare it explicitly in the vertex
         * definition.
         */
        int   tag;
        std::string vertexID;
        LinkedList<Vertex<D> &> *adjacences;

        Vertex(const std::string &vertexID) {
            tag = UNDEF_TAG;
            this->vertexID = vertexID;
            adjacences     = new LinkedList<Vertex<D> &>();
        }

        ~Vertex() {
            delete adjacences;
        }

        bool operator== (Vertex &vertex) {
            return (vertexID == vertex.vertexID);
        }
    };

    template<typename T, typename D> struct Edge {
        T weight;
        Vertex<D> *vertexA;
        Vertex<D> *vertexB;

        Edge(Vertex<D> *a, Vertex<D> *b, T weight) {
            vertexA = a;
            vertexB = b;
            this->weight = weight;
        }
        /*
         * if given vertex is adjacent to the edge, return its neigbor
         * or NULL
         */
        Vertex<D> *neighbor(Vertex<D> *vertex) {
            Vertex<D> *nb = NULL;
            if (vertex == vertexA) {
                nb = vertexB;
            } else if(vertex == vertexB) {
                nb = vertexA;
            }

            return nb;
        }

        bool operator==(Edge<T, D> &edge) {
            return ((*vertexA) == (*edge.vertexA) &&
                    (*vertexB) == (*edge.vertexB));

        }
    };


    template<typename WeightType, typename DataType>
    class Graph {
    public:
        /* accessor */
        virtual Vertex<DataType> *getVertex(std::string &) = 0;
        /*
         * if vertex already exists in graph return false
         *    and graph maintains unchanged
         * else insert vertex into the graph and update edges
         */
        virtual bool addVertex(Vertex<DataType> *) = 0;
        virtual bool addEdge(Edge<WeightType, DataType> *) = 0;
        virtual bool removeVertex(Vertex<DataType> *) = 0;
        virtual bool removeEdge(Edge<WeightType, DataType> *) = 0;
        virtual WeightType changeEdgeWeight(Edge<WeightType, DataType> *,
            WeightType) = 0;

        /* iterator */
        virtual void DFSBegin(const std::string &) = 0;
        virtual bool DFSHasNext() = 0;
        virtual Vertex<DataType> *DFSNext() = 0;

        virtual void BFSBegin(const std::string &) = 0;
        virtual bool BFSHasNext() = 0;
        virtual Vertex<DataType> *BFSNext() = 0;
    };
}

#endif
