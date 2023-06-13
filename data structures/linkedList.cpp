//
// Created by abdelrahman wael on 6/12/2023.
//
#include"linkedList.h"

template<class T>
linkedList<T>::linkedList() : head(nullptr), siz(0) {}

template<class T>
linkedList<T>::linkedList(T value) : head(new nodeLL<T>(value)), siz(1) {}

template<class T>
bool linkedList<T>::empty() {
    return !siz;
}

template<class T>
void linkedList<T>::insertAtHead(T value) {
    auto *newEl = new nodeLL<T>(value);
    if (empty()) {
        head = newEl;
    } else {
        newEl->setNext(head);
        head = newEl;
    }
    siz++;
}

template<class T>
void linkedList<T>::insertAtEnd(T value) {
    auto *newEl = new nodeLL<T>(value);
    if (empty()) {
        head = newEl;
    } else {
        nodeLL<T> *temp = head;
        while (temp->getNext())
            temp = temp->getNext();
        temp->setNext(newEl);
    }
    siz++;
}

template<class T>
void linkedList<T>::insertAt(T value, int index) {
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
    auto *newEl = new nodeLL<T>(value);
    nodeLL<T> *temp = head;
    while (--index)
        temp = temp->getNext();
    newEl->setNext(temp->getNext());
    temp->setNext(newEl);
    siz++;
}

template<class T>
void linkedList<T>::removeAtHead() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    nodeLL<T> *temp = head;
    head = head->getNext();
    delete temp;
    siz--;
}

template<class T>
void linkedList<T>::removeAtEnd() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    if (siz == 1) {
        removeAtHead();
        return;
    }
    nodeLL<T> *temp = head;
    while (temp->getNext()->getNext())
        temp = temp->getNext();
    delete temp->getNext();
    temp->setNext(nullptr);
    siz--;
}

template<class T>
void linkedList<T>::removeAt(int index) {
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
    nodeLL<T> *temp = head;
    while (--index)
        temp = temp->getNext();
    nodeLL<T> *temp2 = temp->getNext();
    temp->setNext(temp->getNext()->getNext());
    delete temp2;
    siz--;
}

template<class T>
T linkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");
    }
    nodeLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    return temp->getData();
}

template<class T>
void linkedList<T>::replaceAt(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");
    }
    nodeLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    temp->setData(value);
}

template<class T>
bool linkedList<T>::isExit(T value) {
    nodeLL<T> *temp = head;
    while (temp) {
        if (temp->getData() == value)
            return true;
        temp = temp->getNext();
    }
    return false;
}

template<class T>
bool linkedList<T>::isEqual(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");
    }

    nodeLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    return temp->getData() == value;
}

template<class T>
void linkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= siz || secondItemIdx < 0 || secondItemIdx >= siz) {
        throw std::runtime_error("Index out of bounds");
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    } else if (firstItemIdx > secondItemIdx) {
        swap(firstItemIdx, secondItemIdx);
    }

    nodeLL<T> *firstItem = head, *secondItem = head;
    for (int i = 0; i < secondItemIdx; i++) {
        if (i == firstItemIdx) {
            firstItem = secondItem;
        }
        secondItem = secondItem->getNext();
    }

    std::swap(*firstItem, *secondItem);
    std::swap(firstItem->getNext(), secondItem->getNext());
}

template<class T>
int linkedList<T>::size() {
    return siz;
}

template<class T>
void linkedList<T>::clear() {
    while (!empty())
        removeAtHead();
}

template<class T>
void linkedList<T>::print() {
    nodeLL<T> *temp = head;
    while (temp) {
        std::cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

template<class T>
linkedList<T>::~linkedList() {
    clear();
}


template
class linkedList<int>;

template
class linkedList<float>;

template
class linkedList<double>;

template
class linkedList<std::string>;

template
class linkedList<char>;

template
class linkedList<bool>;

template
class linkedList<long>;

template
class linkedList<long long>;

template
class linkedList<long double>;

template
class linkedList<unsigned int>;

template
class linkedList<unsigned long>;

template
class linkedList<unsigned long long>;

template
class linkedList<unsigned char>;

template
class linkedList<unsigned short>;

template
class linkedList<short>;

template
class linkedList<signed char>;




