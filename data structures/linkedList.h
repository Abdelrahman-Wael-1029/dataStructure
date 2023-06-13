//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include"nodeLL.cpp"

template<class T>
class linkedList {
    nodeLL<T> *head;
    int siz;
public:
    linkedList();

    explicit linkedList(T value);

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

    ~linkedList();

};

#endif // LINKEDLIST_H
