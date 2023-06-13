//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef STACK_H
#define STACK_H

#include<iostream>
#include"linkedList.h"

template<class T>
class Stack {
    linkedList<T> list;
public:
    Stack();

    void push(T value);

    void pop();

    T top();

    bool empty();

    int size();

};


#endif //STACK_H
