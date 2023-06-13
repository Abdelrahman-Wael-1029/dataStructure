//
// Created by abdelrahman wael on 6/12/2023.
//

#include "Queue.h"


template<class T>
Queue<T>::Queue() : list() {

}

template<class T>
void Queue<T>::enqueue(T value) {
    list.insertAtEnd(value);
}


template<class T>
bool Queue<T>::empty() {
    return list.empty();
}

template<class T>
int Queue<T>::size() {
    return list.size();
}

template<class T>
T Queue<T>::front() {
    return list.retrieveAt(0);
}

template<class T>

T Queue<T>::back() {
    return list.retrieveAt(list.size() - 1);
}

template<class T>
void Queue<T>::dequeue() {
    list.removeAtHead();
}

template
class Queue<int>;

template
class Queue<double>;

template
class Queue<std::string>;

template
class Queue<char>;

template
class Queue<float>;

template
class Queue<long>;

template
class Queue<long long>;

template
class Queue<unsigned int>;

template
class Queue<unsigned long>;

template
class Queue<unsigned long long>;

template
class Queue<short>;

template
class Queue<unsigned short>;

template
class Queue<bool>;

template
class Queue<long double>;

template
class Queue<unsigned char>;

template
class Queue<signed char>;

