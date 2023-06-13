//
// Created by abdelrahman wael on 6/12/2023.
//



template<class T>
class nodeDLL {
    T value;
    nodeDLL<T> *next;
    nodeDLL<T> *prev;
public:

    nodeDLL() : value(0), next(nullptr), prev(nullptr) {}

    explicit nodeDLL(T value) : value(value), next(nullptr), prev(nullptr) {}

    nodeDLL<T> *&getNext() {
        return next;
    }

    nodeDLL<T> *&getPrev() {
        return prev;
    }

    T getValue() {
        return value;
    }

    void setNext(nodeDLL<T> *next) {
        this->next = next;
    }

    void setPrev(nodeDLL<T> *prev) {
        this->prev = prev;
    }

    void setValue(T value) {
        this->value = value;
    }

};