//
// Created by abdelrahman wael on 6/12/2023.
//



template<class T>
class nodeCLL {
    T value;
    nodeCLL<T> *next;

public:
    nodeCLL() : value(0), next(nullptr) {}

    explicit nodeCLL(T value) : value(value), next(nullptr) {}

    nodeCLL<T> *&getNext() {
        return next;
    }

    T getValue() {
        return value;
    }

    void setNext(nodeCLL<T> *next) {
        this->next = next;
    }

    void setValue(T value) {
        this->value = value;
        }
};
