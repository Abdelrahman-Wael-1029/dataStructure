//
// Created by abdelrahman wael on 6/12/2023.
//

#include "Stack.h"


template<class T>
Stack<T>::Stack():list() {

}

template<class T>
void Stack<T>::push(T value) {
    list.insertAtEnd(value);
}


template<class T>
bool Stack<T>::empty() {
    return list.empty();
}

template<class T>
int Stack<T>::size() {
    return list.size();
}

template<class T>
T Stack<T>::top() {
    return list.retrieveAt(list.size() - 1);
}

template<class T>
void Stack<T>::pop() {
    list.removeAtEnd();
}

//define all the types of the template class


template
class Stack<int>;

template
class Stack<double>;

template
class Stack<float>;

template
class Stack<char>;

template
class Stack<std::string>;

template
class Stack<bool>;

template
class Stack<long>;

template
class Stack<long long>;

template
class Stack<long double>;

template
class Stack<unsigned int>;

template
class Stack<unsigned long>;

template
class Stack<unsigned long long>;

template
class Stack<unsigned char>;

template
class Stack<unsigned short>;

template
class Stack<short>;
