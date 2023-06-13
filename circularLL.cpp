#include"circularLL.h"

template<class T>
bool circularLL<T>::empty() {
    return !siz;
}

template<class T>
circularLL<T>::circularLL(): head(nullptr), tail(nullptr), siz(0) {}

template<class T>
circularLL<T>::circularLL(T value): head(new nodeCLL<T>(value)), siz(1) {
    tail = head;
    tail->setNext(head);
}

template<class T>
void circularLL<T>::insertAtHead(T value) {
    auto *newEl = new nodeCLL<T>(value);
    if (empty()) {
        head = newEl;
        tail = head;
        tail->setNext(head);
    } else {
        newEl->setNext(head);
        head = newEl;
        tail->setNext(head);
    }
    siz++;
}

template<class T>
void circularLL<T>::insertAtEnd(T value) {
    auto *newEl = new nodeCLL<T>(value);
    if (empty()) {
        head = newEl;
        tail = head;
        tail->setNext(head);
    } else {
        tail->setNext(newEl);
        tail = newEl;
        tail->setNext(head);
    }
    siz++;
}

template<class T>
void circularLL<T>::insertAt(T value, int index) {
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
    auto *newEl = new nodeCLL<T>(value);
    nodeCLL<T> *temp = head;
    while (--index)
        temp = temp->getNext();
    newEl->setNext(temp->getNext());
    temp->setNext(newEl);
    siz++;
}

template<class T>
void circularLL<T>::removeAtHead() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    if (siz == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        nodeCLL<T> *temp = head;
        head = head->getNext();
        tail->setNext(head);
        delete temp;
    }
    siz--;
}

template<class T>
void circularLL<T>::removeAtEnd() {
    if (empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (siz == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        nodeCLL<T> *temp = head;
        while (temp->getNext() != tail)
            temp = temp->getNext();
        delete tail;
        tail = temp;
        tail->setNext(head);
    }
    siz--;
}

template<class T>
void circularLL<T>::removeAt(int index) {
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
    nodeCLL<T> *temp = head;
    while (--index)
        temp = temp->getNext();
    nodeCLL<T> *temp2 = temp->getNext();
    temp->setNext(temp2->getNext());
    delete temp2;
    siz--;
}

template<class T>
T circularLL<T>::retrieveAt(int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeCLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    return temp->getValue();
}

template<class T>
void circularLL<T>::replaceAt(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeCLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    temp->setValue(value);
}

template<class T>
bool circularLL<T>::isExit(T value) {
    nodeCLL<T> *temp = head;
    do {
        if (temp->getValue() == value)
            return true;
        temp = temp->getNext();
    } while (temp != head);
    return false;
}

template<class T>
bool circularLL<T>::isEqual(T value, int index) {
    if (index < 0 || index >= siz) {
        throw std::runtime_error("Invalid position");

    }
    nodeCLL<T> *temp = head;
    while (index--)
        temp = temp->getNext();
    return temp->getValue() == value;
}

template<class T>
void circularLL<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= siz || secondItemIdx < 0 || secondItemIdx >= siz) {
        throw std::runtime_error("Index out of bounds");
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    } else if (firstItemIdx > secondItemIdx) {
        swap(firstItemIdx, secondItemIdx);
    }
    nodeCLL<T> *firstItem = head, *secondItem = head;
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
int circularLL<T>::size() {
    return siz;
}

template<class T>
void circularLL<T>::clear() {
    while (!empty())
        removeAtHead();
}

template<class T>
void circularLL<T>::print() {
    if (empty()) {
        return;
    }
    nodeCLL<T> *temp = head;
    do {
        std::cout << temp->getValue() << " ";
        temp = temp->getNext();
    } while (temp != head);
    std::cout << std::endl;
}

template<class T>
circularLL<T>::~circularLL() {
    clear();
}

//define all the types of the template class

template
class circularLL<int>;

template
class circularLL<float>;

template
class circularLL<double>;

template
class circularLL<std::string>;

template
class circularLL<char>;

template
class circularLL<bool>;

template
class circularLL<long>;

template
class circularLL<long long>;

template
class circularLL<long double>;

template
class circularLL<unsigned int>;

template
class circularLL<unsigned long>;

template
class circularLL<unsigned long long>;

template
class circularLL<short>;




/*
 *
 */


