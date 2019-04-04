//
//  BinaryTree.hpp
//  Data Structures
//
//  Created by Milo on 2018/9/4.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <algorithm>
#include "BinaryNode.hpp"
#include "Visitor.hpp"
#include "../Chapter4_Stack/Stack.hpp"
#include <vector>

template <typename T> class BinaryTree {
protected:
    int _size;
    BinaryNodePosition(T) _root;
    virtual int updateHeight(BinaryNodePosition(T) x);
    void updateHeightAbove(BinaryNodePosition(T) x);
    
public:
    BinaryTree(): _size(0), _root(nullptr) {
        
    }
    
    
    ~BinaryTree() {
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
    
    BinaryNodePosition(T) root() const {
        return _root;
    }
    
    BinaryNodePosition(T) insertAsRoot(T const& e);
    BinaryNodePosition(T) insertAsLC(BinaryNodePosition(T) x, T const& e);
    BinaryNodePosition(T) insertAsRC(BinaryNodePosition(T) x, T const& e);
    BinaryNodePosition(T) attachAsLC(BinaryNodePosition(T) x,  BinaryTree<T>* );
    BinaryNodePosition(T) attachAsRC(BinaryNodePosition(T) x,  BinaryTree<T>* );
    
    int remove(BinaryNodePosition(T));
    
    BinaryTree<T>* secede(BinaryNodePosition(T) x) {
        FromParentTo(*x) = nullptr; //切断父节点通过左|右子树的引用
        updateHeightAbove(x->parent);
        x->parent = nullptr;
        
        _size -= x->size();
        
        auto tree = new BinaryTree<T>();
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
    
    
    bool operator< (BinaryTree<T> const& t) {
        return _root && t._root && lt(_root, t._root);
    }
    
    bool operator== (BinaryTree<T> const& t) {
        return _root && t._root && (_root == t._root);
    }
    
};

template <typename T>
int BinaryTree<T>::updateHeight(BinaryNodePosition(T) x) {
    return x->height = 1 + std::max(stature(x->lChild), stature(x->rChild));
}

template <typename T>
void BinaryTree<T>::updateHeightAbove(BinaryNodePosition(T) x) {
    while (x) {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
BinaryNodePosition(T) BinaryTree<T>::insertAsRoot(const T &e) {
    _size = 1;
    return _root = new BinaryNode<T>(e);
}


template <typename T>
BinaryNodePosition(T) BinaryTree<T>::insertAsLC(BinaryNodePosition(T) x, T const& e) {
    _size ++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lChild;
}


template <typename T>
BinaryNodePosition(T) BinaryTree<T>::insertAsRC(BinaryNodePosition(T) x, T const& e) {
    _size ++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rChild;
}

template <typename T>
BinaryNodePosition(T) BinaryTree<T>::attachAsLC(BinaryNode<T> *x, BinaryTree<T> * tree) {
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
BinaryNodePosition(T) BinaryTree<T>::attachAsRC(BinaryNode<T> *x, BinaryTree<T> * tree) {
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
int BinaryTree<T>::remove(BinaryNode<T> * x) {
    return  -1;
}

template <typename T, typename VST>
void travPre_R(BinaryNodePosition(T) x, VST& visit) {
    if (!x) {
      return;
    }
    visit(x->data);
    travPre_R(x->lChild, visit);
    travPre_R(x->rChild, visit);
}

template <typename T, typename VST>
void travIn_R(BinaryNodePosition(T) x, VST& visit) {
    if (!x) return;
    
    travIn_R(x->lChild, visit);
    visit(x->data);
    travIn_R(x->rChild, visit);
}


template <typename T, typename VST>
void travPost_R(BinaryNodePosition(T) x, VST& visit) {
    if (!x) return;
    travPost_R(x->lChild, visit);
    travPost_R(x->rChild, visit);
    visit(x->data);
}

template <typename T, typename VST>
void travPre_I(BinaryNodePosition(T) x, VST& visit) {
    Stack<BinaryNodePosition(T)> stack;
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
void travPre_I_teacher(BinaryNodePosition(T) x, VST& visit) {
    Stack<BinaryNodePosition(T)> stack;
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
void travIn_I_leftMost(BinaryNodePosition(T) root, std::vector<BinaryNodePosition(T)>& stack) {
    while (root != nullptr) {
        stack.push_back(root);
        root = root->lChild;
    }
}

template <typename T, typename VST>
void travIn_I(BinaryNodePosition(T) root, VST& visit) {
    std::vector<BinaryNodePosition(T)> stack;
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
void travPo_I_leftMost(BinaryNodePosition(T) root, std::vector<BinaryNodePosition(T)>& stack) {
    while (root->lChild != nullptr) {
        stack.push_back(root);
        root = root->lChild;
    }
}

template <typename T, typename VST>
void travePost_I(BinaryNodePosition(T) root, VST& visit) {
    std::vector<BinaryNodePosition(T)> stack;
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
#endif /* BinaryTree_hpp */
