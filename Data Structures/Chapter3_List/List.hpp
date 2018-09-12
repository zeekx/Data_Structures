//
//  List.hpp
//  Data Structures
//
//  Created by yubinqiang on 16/11/1.
//  Copyright © 2016年 Zeek. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <assert.h>
#include "ListNode.hpp"

template <typename T> class List {
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;
    
protected:
    void init();
    int clear();
    
    void copyNodes(ListNodePosi(T), int);   //复制列表中自位置p开始的n项
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);  //有序列表区间归并
    void mergeSort(ListNodePosi(T)&, int);  //对从p开始连续的n个节点归并排序
    void selectionSort(ListNodePosi(T), int);   //对从p开始的连续n个节点选择排序
    void insertionSort(ListNodePosi(T), int);   //对从p开始的连续n个节点插入排序
    
public:
    List() {init();}
    List(List<T> const& L);//整体复制列表
    List(List<T> const& L, Rank r, int n);
    List(ListNodePosi(T) p , int n);
    
    ~List();
    
public:
    Rank size() const {return _size;}
    bool empty() const {return _size <= 0;}
    T& operator[](Rank r)const; //重载，支持循秩访问（效率低）
    ListNodePosi(T) first() const {return header->succ;}
    ListNodePosi(T) last() const {return trailer->pred;}
    
    bool valid(ListNodePosi(T) p) {return p && (header != p) && (trailer != p);}
    
    int disordered() const;
    ListNodePosi(T) find(T const& e) const {return find(e, _size, trailer);}
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;//无序区间查找
    
    ListNodePosi(T) search(T const& e) const {return  search(e, _size, trailer);}
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;//在有序列表内节点p（可能是trailer）的n个（真）前驱中，找到不大于e的最者
    
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
    ListNodePosi(T) selectMax() {return selectMax(header->succ, _size);}
    
    //可写访问接口
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e);
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);
    
    T remove(ListNodePosi(T) p);    //删除合法位置p处的节点，返回被删除节点
    
    void merge(List<T>& L) {merge(first(), _size, L, L.firt(), L.size());}
    
    void sort (ListNodePosi(T) p, int n);
    void sort() {sort(first(), _size);}
    
    int deduplicate();
    int uniquify(); //惟一化
    void reverse();
    
    //遍历
    void traverse(void(*)(T&));//遍历，依次实施visit操作（函数指针，只读或局部性修改）
    template <typename VST> //操作器
    void traverse(VST &);   //遍历，依次实施visit操作（函数对象，可全局性修改）

};



template <typename T>
void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer; header->pred = nullptr;
    trailer->pred = header; trailer->succ = nullptr;
    _size = 0;
}

template <typename T>
void List<T>::copyNodes(ListNode<T> * p, int n) {
    init();
    while (n--) {
        insertAsLast(p->data);
        p = p->succ;
    }
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
    copyNodes(p, n);
}

template <typename T>
List<T>::List(List<T> const& L) {
    copyNodes(L.first(), L.size());//复制全部
}

template <typename T>
List<T>::List(List<T> const& L, int r, int n) {
    copyNodes(L[r], n);
}

template <typename T>
T& List<T>::operator[](Rank r) const {//assert: 0 <= r < size
    assert(0 <=r && r < size());
    ListNodePosi(T) p = first();
    while (0 < r--) {
        p = p->succ;
    }
    return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(const T &e, int n, ListNode<T> *p) const {
    assert(0 <= n && n <= Rank(p) && Rank(p) < size());
    while (0 < n --) {
        if (e == (p = p->pred)->data) {
            return p;
        }
    }
    return nullptr;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(const T &e) {
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(const T &e) {
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsPred(e);//把e当作p的后继
}

template <typename T>
T List<T>::remove(ListNode<T> *p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p; _size--;
    return e;
}

template <typename T>
List<T>::~List() {
    clear();
    delete header;
    delete trailer;
}

template <typename T>
int List<T>::clear() {
    int oldSize = size();
    while (0 < size()) {
        remove(header->succ);
    }
//    remove(oldSize);
    return oldSize;
}

template <typename T>
int List<T>::deduplicate() {
    int oldSize = size();
    if (oldSize < 2) {
        return 0;
    }
    ListNodePosi(T) p = header; Rank r = 0; //从P首节点开始
    while ( trailer != (p = p->succ)) {
        ListNodePosi(T) q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - size();
}

//向量有序化时，数据相同的结点也必然在（逻辑上）彼此相邻
template <typename T>
int List<T>::uniquify() {
    if (size() < 2) {
        return 0;
    }
    
    int oldSize = size();
    ListNodePosi(T) p; ListNodePosi(T) q;
    for (p = header->succ; trailer != q; p = q,q = q->succ) {
        if (p->data == q->data) {
            remove(q);
            q = p;
        }
    }
    return oldSize - size();
}
template <typename T>
void List<T>::traverse(void (*)(T &)) {
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}
template <typename T> template <typename VST>
void List<T>::traverse(VST &) {
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}

template <typename T>
ListNodePosi(T) List<T>::search(const T &e, int n, ListNode<T> *p) const {
    assert(0 <= n && n <= Rank(p));
    while (0 <= n--) {
        if (((p = p->pred)->data) <= e) break;
    }
    return p;
}
#endif /* List_hpp */
