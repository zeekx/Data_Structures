//
//  Tree.hpp
//  Data Structures
//
//  Created by Milo on 2018/9/4.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <algorithm>
#include "BinNode.hpp"
#include "Visitor.hpp"
#include "../Chapter4_Stack/Stack.hpp"
#include <vector>

#define release(ptr_) \
const BinTree<char> *ptr = ptr_; \
//        delete ptr_; \
        ptr_ = nullptr; \



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
    if ((x->lChild = tree->root())) {
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
    if ((x->rChild = tree->root())) {
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
    if (!x) {
      return;
    }
    visit(x->data);
    travPre_R(x->lChild, visit);
    travPre_R(x->rChild, visit);
}

template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit) {
    if (!x) return;
    
    travIn_R(x->lChild, visit);
    visit(x->data);
    travIn_R(x->rChild, visit);
}


template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit) {
    if (x == nullptr) return;
    travPost_R(x->lChild, visit);
    travPost_R(x->rChild, visit);
    visit(x->data);
}

template <typename T, typename VST>
void travPre_I(BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> stack;
    while (true) {
        visit(x->data);
        if (x->rChild != nullptr) {
            stack.push(x->rChild);
        }
        if (x->lChild != nullptr) {
            x = x->lChild;
        } else {
            if (stack.empty()) {
                return;
            }
            x = stack.pop();
        }
    }
}

template <typename T, typename VST>
void travPre_I_teacher(BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> stack;
    if(x != nullptr) {
        stack.push(x);
    }
    while (!stack.empty()) {
        auto node = stack.pop();
        visit(node->data);
        if (node->rChild != nullptr) {
            stack.push(node->rChild);
        }
        if (node->lChild != nullptr) {
            stack.push(node->lChild);
        }
    }
}

template <typename T>
void travIn_I_leftMost(BinNodePosi(T) root, std::vector<BinNodePosi(T)>& stack) {
    while (root != nullptr) {
        stack.push_back(root);
        root = root->lChild;
    }
}

template <typename T, typename VST>
void travIn_I(BinNodePosi(T) root, VST& visit) {
    std::vector<BinNodePosi(T)> stack;
    while (true) {
        travIn_I_leftMost(root, stack);
        if (stack.empty()) {
            break;
        }
        root = stack.back();
        stack.pop_back();
        visit(root->data);
        root = root->rChild;
    }
}

template <typename T>
void travPo_I_leftMost(BinNodePosi(T) root, std::vector<BinNodePosi(T)>& stack) {
    while (root->lChild != nullptr) {
        stack.push_back(root);
        root = root->lChild;
    }
}

template <typename T, typename VST>
void travePost_I(BinNodePosi(T) root, VST& visit) {
    std::vector<BinNodePosi(T)> stack;
    while (true) {
        travPo_I_leftMost(root, stack);
        if (stack.empty()) {
            break;
        }
        root = stack.back();
        visit(root->lChild->data);
        root = root->rChild;
        if (root == nullptr) {
            root = stack.back();
            stack.pop_back();
            visit(root->data);
        }
    }
}

template <typename T, typename VST>
void travePost(BinNodePosi(T) root, VST& visit) {
    if (HasLChild(*root)) {
        travePost(root->lChild, visit);
    }
    if (HasRChild(*root)) {
        travePost(root->rChild, visit);
    }
    visit(root->data);
}
#endif /* Tree_hpp */
