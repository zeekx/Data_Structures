//
//  GraphMatrix.hpp
//  Data Structures
//
//  Created by Milo on 2018/10/19.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef GraphMatrix_hpp
#define GraphMatrix_hpp
#include "Graph.hpp"
#include <vector>
#include <string>


template <typename Tv>
struct Vertex {
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    
    int dTime, fTime;
    int parent;
    int priority;
    
    Vertex(Tv const& d = (Tv)0 ):
    data(d), inDegree(0), outDegree(0),
    status(UNDISCOVERED),
    dTime(-1),
    fTime(-1),
    parent(-1),
    priority(INT_MAX) {
        
    }
};


template <typename Te>
struct Edge {
    Te data;
    int weight;
    EStatus status;
    Edge(Te const& d, int w): data(d), weight(w), status(UNDETERMINED) {
        
    }
    
};

template <typename Tv, typename Te>
class GraphMatrix: public Graph<Tv, Te> {
private:
    std::vector<Vertex<Tv>> V;
    std::vector<std::vector<Edge<Te>*>> E;
    
public:
    GraphMatrix() {
        this->n = 0;
        this->e = 0;
    }
    
    ~GraphMatrix() {
#if false
        delete [] this->E;
#else
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                delete E[i][j];
            }
        }
#endif
    }
    
    virtual Tv& vertex(int i) {
        return V[i].data;
    }
    
    virtual int inDegree(int i) {
        return V[i].inDegree;
    }
    
    virtual int outDegree(int i) {
        return V[i].outDegree;
    }
    
    virtual VStatus& status(int i) {
        return V[i].status;
    }
    
    virtual int& dTime(int i) {
        return V[i].dTime;
    }
    
    virtual int& fTime(int i) {
        return V[i].fTime;
    }
    
    virtual int& parent(int i) {
        return V[i].parent;
    }
    
    virtual int& priority(int i) {
        return V[i].priority;
    }
    
    
    virtual int insert(Tv const& vertex) {
        for (int j = 0; j < this->n; j++) {
            E[j].push_back(nullptr);
            this->n++;
        }
        E.push_back(std::vector<Edge<Te>*>(this->n, (Edge<Te>*)nullptr));
        V.push_back(Vertex<Tv>(vertex));
        return (int)V.size();
    }
    
    //边(i, j)是否存在
    virtual bool exists(int i, int j) {
        return (0<=i) && (i< this->n)
        && (0<=j) && (j< this->n)
        && E[i][j] != nullptr;
    }
    
    std::string description() {
        std::string des = "";
        for (Vertex<Tv> t : V) {
                des += t.data;
        }
        des += "\n";
        return des;
    }
};


#endif /* GraphMatrix_hpp */
