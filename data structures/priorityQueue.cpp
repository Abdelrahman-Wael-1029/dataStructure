//
// Created by abdelrahman wael on 6/13/2023.
//

#include "priorityQueue.h"


template<class T>
priorityQueue<T>::priorityQueue() : size(0) {}

template<class T>
void priorityQueue<T>::push(T data) {
    arr.push_back(data);
    ++size;
    builtHeap();
}

template<class T>
T priorityQueue<T>::top() {
    return arr[0];
}

template<class T>
void priorityQueue<T>::remove() {
    std::swap(arr[0], arr[size - 1]);
    arr.pop_back();
    --size;
    heapify(0);
}

template<class T>
bool priorityQueue<T>::empty() {
    return size == 0;
}

template<class T>
int priorityQueue<T>::Size() {
    return size;
}

template<class T>
priorityQueue<T>::~priorityQueue() {
    arr.clear();
    size = 0;
}


template<class T>
void priorityQueue<T>::builtHeap() {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(i);
    }
}

template<class T>
void priorityQueue<T>::heapify(int index) {
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int mx = index;
    if (l < size && arr[index] < arr[l]) {
        mx = l;
    }
    if (r < size && arr[mx] < arr[r]) {
        mx = r;
    }

    if (mx != index) {
        std::swap(arr[index], arr[mx]);
        heapify(mx);
    }
}

template class priorityQueue<int>;

template class priorityQueue<float>;

template class priorityQueue<double>;

template class priorityQueue<char>;

template class priorityQueue<std::string>;

template class priorityQueue<long>;

template class priorityQueue<long long>;

template class priorityQueue<long double>;

template class priorityQueue<unsigned int>;

template class priorityQueue<unsigned long>;

template class priorityQueue<unsigned long long>;

template class priorityQueue<unsigned char>;

template class priorityQueue<bool>;

template class priorityQueue<short>;

template class priorityQueue<unsigned short>;
