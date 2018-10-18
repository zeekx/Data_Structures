//
//  main.cpp
//  Chapter4_Queue
//
//  Created by Milo on 2018/9/12.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <iostream>
#define QueueSize 4

typedef char DataType;

typedef struct {
    int front;
    int rear;
    int count;
    DataType data[QueueSize];
} CircleQueue;

void InitQueue(CircleQueue *q) {
    q->front = 0;
    q->rear = q->front;
    q->count = 0;
}

int QueueEmpty(CircleQueue *q) {
    return q->count == 0;
}

int QueueFull(CircleQueue *q) {
    return q->count == QueueSize;
}

void EnQueue(CircleQueue *q, DataType x) {
    if (QueueFull(q)) {
        assert(false);
    } else {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % QueueSize;
        q->count += 1;
    }
}

DataType DeQueue(CircleQueue *q) {
    if (QueueEmpty(q)) {
        return (DataType)0;
    } else {
        DataType e = q->data[q->front];
        q->front = (q->front + 1) % QueueSize;
        q->count -= 1;
        return e;
    }
}

DataType QueueFront(CircleQueue *q) {
    if (QueueEmpty(q)) {
        return (DataType)0;
    } else {
        return q->data[q->front];
    }
}

int Factorial(int n) {
    if (0 == n) {
        return 1;
    } else {
        return n * Factorial(n-1);
    }
}

int main(int argc, const char * argv[]) {
    int n = 4;
    printf("%d!=%d\n",n ,Factorial(n));
    return EXIT_SUCCESS;
    CircleQueue queue;
    InitQueue(&queue);
    EnQueue(&queue, 'A');
    EnQueue(&queue, 'B');
    EnQueue(&queue, 'C');
    EnQueue(&queue, 'D');
    
    DeQueue(&queue);
    DeQueue(&queue);
    DeQueue(&queue);
    DeQueue(&queue);

    printf("\nQueue empty:%d", QueueEmpty(&queue));
    printf("\nQueue full:%d", QueueFull(&queue));
    for (int i = 0; i < 100; i++) {
        EnQueue(&queue, 'A');
        EnQueue(&queue, 'B');
        DeQueue(&queue);
        DeQueue(&queue);
    }
    assert(!QueueFull(&queue));
    assert(QueueEmpty(&queue));
    
    
    return 0;
}
