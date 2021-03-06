//
//  BinaryNode.hpp
//  Data Structures
//
//  Created by Milo on 2018/9/4.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef BinaryNode_hpp
#define BinaryNode_hpp

#include <stdio.h>
#include <cstdlib>
#include "Queue.hpp"

#define BinaryNodePosition(T) BinaryNode<T>* //节点位置
#define stature(p) ((p) ? (p)->height : -1) //节点高度（和“空树高度为-1”约定一致）
typedef enum {RB_RED, RB_BLACK} RBColor;    //节点颜色

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x)     (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x)   (!HasChild(x))

#define sibling(p) ( \
IsLChild(*(p)) ? \
(p)->parent->rChild : \
(p)->parent->lChild \
)

#define uncle(x) ( \
IsChild(*((x)->parent)) ? \
(x)->parent->parent->rChild : \
(x)->parent->parent->lChild \
)

#define FromParentTo(x) ( \
IsRoot(x) ? _root : ( \
IsLChild(x) ? (x).parent->lChild : (x).parent->rChild) \
)

template <typename T> struct BinaryNode {

    T data;
    BinaryNodePosition(T) parent;
    BinaryNodePosition(T) lChild;
    BinaryNodePosition(T) rChild;
    int height;
    int npl;    //Null path length
    RBColor color;
    
    BinaryNode() :parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {
        
    }
    
    BinaryNode(T e,
            BinaryNodePosition(T) p = nullptr,
            BinaryNodePosition(T) lc = nullptr,
            BinaryNodePosition(T) rc = nullptr,
            int h = 0, int l = 1, RBColor c = RB_RED) {
        data = e;
        
        parent = p;
        lChild = lc;
        rChild = rc;
        
        height = h;
        npl = 1;
        color = c;
    }
    
    
    //
    int size() {
        int size = 1;
        if (lChild) {
            size += lChild->size();
        }
        if (rChild) {
            size += rChild->size();
        }
        return size;
    }
    BinaryNodePosition(T) insertAsLC(T const &);
    BinaryNodePosition(T) insertAsRC(T const &);
    BinaryNodePosition(T) succ();
    
    template <typename VST> void travLevel(VST &);
    template <typename VST> void travPre(VST &);
    template <typename VST> void travIn(VST &);
    template <typename VST> void travPost(VST &);
    
    bool operator< (BinaryNode const& bn) {
        return data < bn.data;
    }
    
    bool operator== (BinaryNode const& bn) {
        return  data == bn.data;
    }
public:
    
};

template <typename T>
BinaryNodePosition(T) BinaryNode<T>::insertAsLC(T const& e) {
    return lChild = new BinaryNode(e, this);
}

template <typename T>
BinaryNodePosition(T) BinaryNode<T>::insertAsRC(T const& e) {
    return rChild = new BinaryNode(e, this);
}

template <typename T>
template <typename VST>
void BinaryNode<T>::travIn(VST & visit) {
    visit(this->data);
    switch (std::rand() % 5) {
//        case 1:
//            travIn_I1(this, visit);
//            break;
//        case 2:
//            travIn_I2(this, visit);
//            break;
//        case 3:
//            travIn_I3(this, visit);
//            break;
//        case 4:
//            travIn_I4(this, visit);
//            break;
        default:
            travIn_R(this, visit);
            break;
    }
}


template <typename T> template <typename VST>
void BinaryNode<T>::travLevel(VST &visit) {
    Queue<BinaryNodePosition(T)> queue;
    queue.enqueue(this);
    while (!queue.empty()) {
        auto node = queue.dequeue();
        visit(node->data);
        if (HasLChild(*node)) {
            queue.enqueue(node->lChild);
        }
        
        if (HasRChild(*node)) {
            queue.enqueue(node->rChild);
        }
    }
}

template <typename T> template <typename VST>
void BinaryNode<T>::travPost(VST &visitor) {
    if (HasLChild(*this)) {
        this->lChild->travPost(visitor);
    }
    
    if (HasRChild(*this)) {
        this->rChild->travPost(visitor);
    }
    
    visitor(this->data);
}

#endif /* BinaryNode_hpp */
