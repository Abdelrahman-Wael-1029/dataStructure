//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H

#include"linkedList.h"
template<class T>
class Queue {
    linkedList<T> list;
public:
    Queue();

    void enqueue(T value);

    void dequeue();

    T front();

    T back();

    bool empty();

    int size();
};


#endif //UNTITLED1_QUEUE_H
