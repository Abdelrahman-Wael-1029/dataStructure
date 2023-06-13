//
// Created by abdelrahman wael on 6/13/2023.
//

#ifndef UNTITLED1_PRIORITYQUEUE_H
#define UNTITLED1_PRIORITYQUEUE_H

#include<iostream>
#include<vector>

template<class T>
class priorityQueue {
    std::vector<T> arr;
    int size;

    void builtHeap();

    void heapify(int index);

public:

    priorityQueue();

    void print();

    void push(T data);

    T top();

    void remove();

    bool empty();

    int Size();

    ~priorityQueue();
};


#endif //UNTITLED1_PRIORITYQUEUE_H
