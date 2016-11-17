//
//  ListNode.hpp
//  Data Structures
//
//  Created by yubinqiang on 16/11/1.
//  Copyright © 2016年 Zeek. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>


typedef int Rank;//秩
#define ListNodePosi(T) ListNode<T> *
//template <typename T> typedef ListNode<T>* ListNodePosi;

template <typename T> struct ListNode {
    T data;                 //数据成员
    ListNodePosi(T) pred;   //前驱
    ListNodePosi(T) succ;   //后继
    
    ListNode() {}           //针对header和trailer的构造
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) : data(e), pred(p), succ(s) {}    //默认构造
    
    //操作接口
    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
    ListNodePosi(T) x = new ListNode(e,pred, this);//x->pred=caller->pred; x->succ=this
    pred->succ = x;
    pred = x;
    return x;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
    ListNodePosi(T) x = new ListNode(e,this, succ);//x->pred=caller->succ; x->succ=succ
    succ->pred = x;
    succ = x;
    return x;
}
#endif /* ListNode_hpp */
