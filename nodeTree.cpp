//
// Created by abdelrahman wael on 6/13/2023.
//

template<class T>
class node {
public:
    T data;
    int height;
    node *left, *right;

    explicit node(T data) : data(data), left(nullptr), right(nullptr), height(1) {}
};