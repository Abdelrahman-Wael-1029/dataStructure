//
// Created by abdelrahman wael on 6/12/2023.
//
#include"doubleLL.h"

template<class T>
doubleLL<T>::doubleLL() : head(nullptr), tail(nullptr), siz(0) {}

template<class T>
doubleLL<T>::doubleLL(T value) : head(new nodeDLL<T>(value)), tail(head), siz(1) {}

template<class T>
bool doubleLL<T>::empty() {
    return !siz;
}

template<class T>
void doubleLL<T>::insertAtHead(T value) {
    auto *newEl = new nodeDLL<T>(value);
    if (empty()) {
        head = newEl;
        tail = head;
    } else {
        newEl->setNext(head);
        head->setPrev(newEl);
        head = newEl;
    }
    siz++;
}

template<class T>
void doubleLL<T>::insertAtEnd(T value) {
    auto *newEl = new nodeDLL<T>(value);
    if (empty()) {
        head = newEl;
        tail = head;
    } else {
        tail->setNext(newEl);
        newEl->setPrev(tail);
        tail = newEl;
    }
    siz++;
}

template<class T>
void doubleLL<T>::insertAt(T value, int index) {
    if (index < 0 || index > siz) {
        throw std::runtime_error("Invalid position");
    }
    if (!index) {
        insertAtHead(value);
        return;
    }
    if (index == siz) {
        insertAtEnd(value);
        return;
    }
    auto *newEl = new nodeDLL<T>(value);
    nodeDLL<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->getNext();
    }
    newEl->setNext(temp->getNext());
    newEl->setPrev(temp);
    temp->getNext()->setPrev(newEl);
    temp->setNext(newEl);
    siz++;
}

template<class T>
void doubleLL<T>::removeAtHead() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    nodeDLL<T> *temp = head;
    head = head->getNext();
    delete temp;
    siz--;
}

template<class T>
void doubleLL<T>::removeAtEnd() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    nodeDLL<T> *temp = tail;
    tail = tail->getPrev();
    delete temp;
    siz--;
}

template<class T>
void doubleLL<T>::removeAt(int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    if (!index) {
        removeAtHead();
        return;
    }
    if (index == siz - 1) {
        removeAtEnd();
        return;
    }
    nodeDLL<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->getNext();
    }
    nodeDLL<T> *toDelete = temp->getNext();
    temp->setNext(toDelete->getNext());
    toDelete->getNext()->setPrev(temp);
    delete toDelete;
    siz--;
}

template<class T>
T doubleLL<T>::retrieveAt(int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeDLL<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
    return temp->getValue();
}

template<class T>
void doubleLL<T>::replaceAt(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeDLL<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
    temp->setValue(value);
}

template<class T>
bool doubleLL<T>::isExit(T value) {
    nodeDLL<T> *temp = head;
    while (temp) {
        if (temp->getValue() == value) {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

template<class T>
bool doubleLL<T>::isEqual(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeDLL<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
    return temp->getValue() == value;
}

template<class T>
void doubleLL<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= siz || secondItemIdx < 0 || secondItemIdx >= siz) {
        throw std::runtime_error("Index out of bounds");
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    } else if (firstItemIdx > secondItemIdx) {
        swap(firstItemIdx, secondItemIdx);
    }

    nodeDLL<T> *firstItem = head, *secondItem = head;
    for (int i = 0; i < secondItemIdx; i++) {
        if (i == firstItemIdx) {
            firstItem = secondItem;
        }
        secondItem = secondItem->getNext();
    }

    std::swap(*firstItem, *secondItem);
    std::swap(firstItem->getNext(), secondItem->getNext());
    std::swap(firstItem->getPrev(), secondItem->getPrev());

}

template<class T>
int doubleLL<T>::size() {
    return siz;
}

template<class T>
void doubleLL<T>::clear() {
    while (!empty()) {
        removeAtHead();
    }
}

template<class T>
void doubleLL<T>::print() {
    nodeDLL<T> *temp = head;
    while (temp) {
        std::cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

template<class T>
doubleLL<T>::~doubleLL() {
    clear();
}

template
class doubleLL<int>;

template
class doubleLL<double>;

template
class doubleLL<std::string>;

template
class doubleLL<char>;

template
class doubleLL<float>;

template
class doubleLL<long>;

template
class doubleLL<long long>;

template
class doubleLL<unsigned int>;

template
class doubleLL<unsigned long>;

template
class doubleLL<unsigned long long>;

template
class doubleLL<short>;

template
class doubleLL<unsigned short>;

template
class doubleLL<bool>;

template
class doubleLL<long double>;

template
class doubleLL<unsigned char>;

template
class doubleLL<signed char>;
