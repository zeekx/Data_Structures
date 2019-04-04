//
//  BinarySearchTree.hpp
//  Data Structures
//
//  Created by Milo on 2019/1/29.
//  Copyright © 2019 Zeek. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "BinaryTree.hpp"
#include "BinaryNode.hpp"

template <typename Key, typename Value> struct Entry {
    Key key;
    Value value;
    
    Entry(Key key = Key(), Value value = Value()): key(key), value(value) {
        
    }
    
    Entry(Entry<Key, Value> const& entry): key(entry.key), value(entry.value) {
        
    }
    
    bool operator<(Entry<Key, Value> const& entry) {
        return this->key < entry.key;
    }

    
    bool operator>(Entry<Key, Value> const& entry) {
        return this->key > entry.key;
    }

    
    bool operator==(Entry<Key, Value> const& entry) {
        return this->key == entry.key;
    }
    
    bool operator!=(Entry<Key, Value> const& entry) {
        return this->key != entry.key;
    }

};

template <typename T> class BinarySearchTree : public BinaryTree<T> {
protected:
    BinaryNodePosition(T) _hot;
    BinaryNodePosition(T) _connect34(BinaryNodePosition(T), BinaryNodePosition(T), BinaryNodePosition(T),
                              BinaryNodePosition(T), BinaryNodePosition(T), BinaryNodePosition(T), BinaryNodePosition(T));
    
    BinaryNodePosition(T) rotateAt(BinaryNodePosition(T) x);
    
public:
    virtual BinaryNodePosition(T)& search(const T& e);
    virtual BinaryNodePosition(T) insert(const T& e);
    virtual bool remove(const T& e);
};
#endif /* BinarySearchTree_hpp */
