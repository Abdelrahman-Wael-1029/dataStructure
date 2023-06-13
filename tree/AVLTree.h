//
// Created by abdelrahman wael on 6/13/2023.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
#include"nodeTree.cpp"

template<class T>
class AVLTree {
    int siz;
    node<T> *root;

    void preorder(node<T> *temp);

    node<T> *insert(node<T> *temp, T data);

    node<T> *remove(node<T> *&temp, T data);

    node<T> *RRRotation(node<T> *temp);

    node<T> *LLRotation(node<T> *temp);

    node<T> *RLRotation(node<T> *temp);

    node<T> *LRRotation(node<T> *temp);

    node<T> *rightRotation(node<T> *temp);

    node<T> *leftRotation(node<T> *temp);

public:

    int size();

    node<T> *successor(T data);

    int calcHeight(node<T> *temp);

    int calcBalance(node<T> *temp);

    bool search(T data);

    void preorder();

    void insert(T data);

    void remove(T data);

    bool isEmpty();

    T findMin(node<T> *temp);

    T findMax(node<T> *temp);

    explicit AVLTree();
};




#endif //AVLTREE_H
