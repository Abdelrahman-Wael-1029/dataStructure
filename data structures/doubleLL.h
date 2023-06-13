//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef DOUBLELL_H
#define DOUBLELL_H


#include<iostream>
#include "nodeDLL.cpp"


template<class T>
class doubleLL {
    nodeDLL<T> *head;
    nodeDLL<T> *tail;
    int siz;
public:
    doubleLL();

    explicit doubleLL(T value);

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

//    swap without changing the values and used std::swap
    void swap(int firstItemIdx, int secondItemIdx);

    int size();

    void clear();

    void print();

    ~doubleLL();

};


#endif //DOUBLELL_H
