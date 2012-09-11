/*
 * AdjacentGraph.cpp -- adjacent graph impelmentation
 *
 * author: QIU Shuang
 * modified on: Mar 29, 2012
 */
#include <iostream>

#define UNVISITED 0
#define VISITED   1
#define INSTOCK   2

namespace interview {
    template<typename WeightType, typename DataType>
    AdjacentGraph<WeightType, DataType>::AdjacentGraph():_vertices(NULL),
            _edges(NULL) {
        _vertices = new LinkedList<Vertex<DataType> &>();
        _edges    = new LinkedList<Edge<WeightType, DataType> &>();
        _BFSCache = new Queue<Vertex<DataType> *>();
        _DFSCache = new Stack<Vertex<DataType> *>();
    }

    template<typename WeightType, typename DataType>
    AdjacentGraph<WeightType, DataType>::~AdjacentGraph() {
        delete _vertices;
        delete _edges;
        delete _BFSCache;
        delete _DFSCache;

        _vertices = NULL;
        _edges    = NULL;
        _BFSCache = NULL;
        _DFSCache = NULL;
    }

    template<typename WeightType, typename DataType>
    Vertex<DataType> *AdjacentGraph<WeightType, DataType>::getVertex(std::string &vertexName) {
        Vertex<DataType> *vertex = NULL;
        _vertices->begin();
        while (_vertices->hasNext()) {
            vertex = &(_vertices->next());
            if (!(vertex->vertexID == vertexName))
                vertex = NULL;
        }

        return vertex;
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::addVertex(Vertex<DataType> *vertex) {
        bool duplicated = false;
        if (_vertices->find(*vertex)) {
            duplicated = true;
        } else {
            _vertices->insert(*vertex);
        }

        return !duplicated;
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::addEdge(Edge<WeightType, DataType> *edge) {
        bool duplicated = false;
        if (_edges->find(*edge)) {
            duplicated = true;
        } else {
            edge->vertexA->adjacences->insert(*(edge->vertexB));
            addVertex(edge->vertexA);
            addVertex(edge->vertexB);
            _edges->insert(*edge);
        }

        return !duplicated;
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::removeVertex(Vertex<DataType>
        *vertex) {
        return _vertices->remove(*vertex);
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::removeEdge(Edge<WeightType,
            DataType> *edge) {
        return _edges->remove(*edge);
    }

    template<typename WeightType, typename DataType>
    WeightType
    AdjacentGraph<WeightType, DataType>::changeEdgeWeight
            (Edge<WeightType, DataType> *edge, WeightType newWeight) {
        WeightType weight;
        if (_edges->find(*edge)) {
            weight = edge->weight;
            edge->weight = newWeight;
        }

        return weight;
    }

    template<typename WeightType, typename DataType>
    void AdjacentGraph<WeightType, DataType>::BFSBegin
            (const std::string &vertex) {
        _BFSCache->clearAll();
        _vertices->begin();
        while (_vertices->hasNext()) {
            Vertex<DataType> &iterator = _vertices->next();
            if (iterator.vertexID == vertex) {
                iterator.tag = VISITED;
                _BFSCache->enqueue(&iterator);
            } else {
                iterator.tag = UNVISITED;
            }
        }
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::BFSHasNext() {
        return (!_BFSCache->isEmpty());
    }

    template<typename WeightType, typename DataType>
    Vertex<DataType> *AdjacentGraph<WeightType, DataType>::BFSNext() {
        Vertex<DataType> *next = _BFSCache->dequeue();
        next->adjacences->begin();
        while (next->adjacences->hasNext()) {
            Vertex<DataType> &iterator = next->adjacences->next();
            if (iterator.tag == UNVISITED) {
                iterator.tag = VISITED;
                _BFSCache->enqueue(&iterator);
            }
        }

        return next;
    }

    template<typename WeightType, typename DataType>
    void AdjacentGraph<WeightType, DataType>::DFSBegin
            (const std::string &vertexID) {
        _DFSCache->clearAll();
        _vertices->begin();
        while (_vertices->hasNext()) {
            Vertex<DataType> &iterator = _vertices->next();
            if (iterator.vertexID == vertexID) {
                iterator.tag = VISITED;
                _DFSCache->push(&iterator);
            } else {
                iterator.tag = UNVISITED;
            }
            iterator.adjacences->begin();
        }

        Vertex<DataType> *iterator = NULL;
        while ((iterator = _DFSCache->peek())->adjacences->hasNext()) {
            iterator = &iterator->adjacences->next();
            if (iterator->tag == UNVISITED) {
                iterator->tag = INSTOCK;
                _DFSCache->push(iterator);
            }
        }
    }

    template<typename WeightType, typename DataType>
    bool AdjacentGraph<WeightType, DataType>::DFSHasNext() {
        return (!_DFSCache->isEmpty());
    }

    template<typename WeightType, typename DataType>
    Vertex<DataType> *AdjacentGraph<WeightType, DataType>::DFSNext() {
        Vertex<DataType> *top;
        Vertex<DataType> *iterator;
        while ((top = _DFSCache->peek())->adjacences->hasNext()) {
            iterator = &(top->adjacences->next());
            if (iterator->tag == UNVISITED) {
                iterator->tag = INSTOCK;
                _DFSCache->push(iterator);
            }
        }
        iterator = _DFSCache->pop();
        iterator->tag = VISITED;

        return iterator;
    }

    template<typename WeightType, typename DataType>
    AdjacentGraph<WeightType, DataType> &
    AdjacentGraph<WeightType, DataType>::operator=
            (AdjacentGraph<WeightType, DataType> &g) {
        return *this;
    }

    template<typename T, typename U>
    void printAdjacentGraph(std::ostream &output, AdjacentGraph<T, U> &graph) {
        output << "Vertices: " << std::endl;
        graph._vertices->begin();
        while (graph._vertices->hasNext()) {
            Vertex<U> &itr = graph._vertices->next();
            output << itr.vertexID << ": ";
            itr.adjacences->begin();
            while (itr.adjacences->hasNext()) {
                output << itr.adjacences->next().vertexID << " ";
            }
            output << std::endl;
        }
        output << std::endl;

        output << "Edges: " << std::endl;
        graph._edges->begin();
        while (graph._edges->hasNext()) {
            Edge<T, U> &edge = graph._edges->next();
            output << edge.vertexA->vertexID << " -> "
                   << edge.vertexB->vertexID << ": "
                   << edge.weight << std::endl;
        }
        output << std::endl;
    }
}
