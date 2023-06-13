//
// Created by abdelrahman wael on 6/12/2023.
//

#ifndef NODELL_H
#define NODELL_H

template<class T>
class nodeLL {
    T data;
    nodeLL<T> *next;
public:
    explicit nodeLL(T value) : data(value), next(nullptr) {}

    nodeLL() : data(0), next(nullptr) {}

    void setData(T value) {
        data = value;
    }

    void setNext(nodeLL<T> *next) {
        this->next = next;
    }

    T getData() {
        return data;
    }

    nodeLL<T> *&getNext() {
        return next;
    }
};

#endif // NODELL_H