//
//  Graph.hpp
//  Data Structures
//
//  Created by Milo on 2018/10/19.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "Stack.hpp"

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //顶点状态
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus; //边状态
template <typename Tv, typename Te> //顶点类型、边类型
class Graph { //图Graph模板类
private:
void reset() { //所有顶点、边癿辅劣信息复位
    for (int i=0; i<n; i++) {//所有顶点
        status(i) = UNDISCOVERED;
        dTime(i) = fTime(i) = -1; //状态，时间标签
        parent(i) = -1;
        priority(i) = INT_MAX; //(在遍历树中的)父节点，优先级数
        for (int j=0; j<n; j++)//所有边的 {
            if (exists(i, j)) {
                status(i, j) = UNDETERMINED; //状态
            }
        
    }//for
    
}
void BFS(int, int&); //(连通域)广度优先搜索算法
void DFS(int, int&); //(连通域)深度优先搜索算法
void BCC(int, int&, Stack<int>&); //(连通域)基亍DFS癿双连通分量分解算法
bool TSort(int, int&, Stack<Tv>*); //(连通域)基亍DFS癿拓扑排序算法
template <typename PU>
void PFS(int, PU); //(连通域)优先级搜索框架
public:
    int n;
    int e;
    virtual int insert(Tv const&) = 0;
    virtual VStatus& status(int) = 0; //statue of vertex
    virtual int& dTime(int) = 0;
    virtual int& fTime(int) = 0;
    virtual int& parent(int) = 0;
    virtual int& priority(int) = 0;
    virtual bool exists(int, int) = 0;
};
#endif /* Graph_hpp */
