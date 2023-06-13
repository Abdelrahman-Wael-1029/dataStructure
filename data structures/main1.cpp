#include<iostream>
#include<random>
#include"doubleLL.cpp"
//#include"linkedList.cpp"
#include"circularLL.cpp"
#include"Stack.h"
#include"Queue.h"
#include "LinkedList.h"
#include "doubleLL.h"
#include "circularLL.h"
#include"AVLTree.cpp"

#include"priorityQueue.cpp"

using namespace std;

int main() {
    try {
        Queue<int> q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << q.front() << endl;
        cout << q.back() << endl;
        q.dequeue();
        cout << q.front() << endl;
        cout << q.back() << endl;


    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
}




