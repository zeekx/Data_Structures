//
//  Tree.hpp
//  Data Structures
//
//  Created by Milo on 2018/9/4.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <algorithm>
#include "BinNode.hpp"

template <typename T> class BinTree {
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);
    
public:
    BinTree(): _size(0), _root(nullptr) {
        
    }
    
    
    ~BinTree() {
        if (0 < _size) {
            remove(_root);
        }
    }
    
    int size() const {
        return _size;
    }
    
    bool empty() const {
        return !_root;
    }
    
    BinNodePosi(T) root() const {
        return _root;
    }
    
    BinNodePosi(T) insertAsRoot(T const& e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x,  BinTree<T>* );
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x,  BinTree<T>* );
    
    int remove(BinNodePosi(T));
    
    BinTree<T>* secede(BinNodePosi(T) x) {
        FromParentTo(*x) = nullptr; //切断父节点通过左|右子树的引用
        updateHeightAbove(x->parent);
        x->parent = nullptr;
        
        _size -= x->size();
        
        auto tree = new BinTree<T>();
        tree->_size = x->size();
        tree->_root = x;
        
        return tree;
        
    }
    template <typename VST>
    void travLevel(VST& visit) {
        if (_root) {
            _root->travLevel(visit);
        }
    }
    
    template <typename VST>
    void travPre(VST& visit) {
        if (_root) {
            _root->travPre(visit);
        }
    }
    
    template <typename VST>
    void travIn(VST& visit) {
        if (_root) {
            _root->travIn(visit);
        }
    }
    
    template <typename VST>
    void travPost(VST& visit) {
        if (_root) {
            _root->travPost(visit);
        }
    }
    
    
    bool operator< (BinTree<T> const& t) {
        return _root && t._root && lt(_root, t._root);
    }
    
    bool operator== (BinTree<T> const& t) {
        return _root && t._root && (_root == t._root);
    }
};

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x) {
    return x->height = 1 + std::max(stature(x->lChild), stature(x->rChild));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
    while (x) {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T &e) {
    _size = 1;
    return _root = new BinNode<T>(e);
}


template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e) {
    _size ++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lChild;
}


template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e) {
    _size ++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rChild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNode<T> *x, BinTree<T> * tree) {
    if (x->insertAsLC(tree)) {
        x->lChild->parent = x;
    }
    
    _size += tree->size();
    updateHeightAbove(x);
    tree->_size = 0;
    tree->_root = nullptr;
    release(tree);
    tree = nullptr;
    return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNode<T> *x, BinTree<T> * tree) {
    if (x->insertAsRC(tree)) {
        x->rChild->parent = x;
    }
    
    _size += tree->size();
    updateHeightAbove(x);
    tree->_size = 0;
    tree->_root = nullptr;
    release(tree);
    tree = nullptr;
    return x;
}

template <typename T>
int BinTree<T>::remove(BinNode<T> * x) {
    return  -1;
}

template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit) {
    if (!x) return;
    visit(x->data);
    travPre_R(x->lChild, visit);
    travPre_R(x->rChild, visit);
}
#endif /* Tree_hpp */
