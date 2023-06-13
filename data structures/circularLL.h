//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include <iostream>
#include"nodeLL.cpp"

template<class T>
class circularLL {
    nodeLL<T> *head;
    nodeLL<T> *tail;
    int siz;
public:
    circularLL();

    explicit circularLL(T value);

    bool empty();

    void insertAtHead(T value);

    void insertAtEnd(T value);

    void insertAt(T value, int index);

    void removeAtHead();

    void removeAtEnd();

    void removeAt(int index);

    T retrieveAt(int index);

    void replaceAt(T value, int index);

    bool isExit(T value);

    bool isEqual(T value, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    int size();

    void clear();

    void print();

    ~ circularLL();
};

#endif //CIRCULARLL_H
