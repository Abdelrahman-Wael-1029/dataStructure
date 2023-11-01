#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;
template <class T, class V>
class Hash 
{
protected:
    /* data */
    pair<T, V> *arr;
    int siz;
    int capacity;
    bool *filled;
    const float loadFactor = .75;
    virtual void resize() = 0;
public:
    Hash(int siz = 0)
    {
        this->capacity = max(1, (int)(siz / this->loadFactor));
        this->siz = siz;
        this->arr = new pair<T, V>[capacity];
        this->filled = new bool[capacity];
        memset(this->filled, false, sizeof(this->filled));
    }
    virtual bool insertItem(T key, V value) = 0;
    virtual bool deleteItem(T key) = 0;
    virtual bool searchItem(T key) = 0;
    virtual V getItem(T key) = 0;
    virtual int next(T key, int add) = 0;
    virtual int hashFunction(T key)
    {
        // make hashing using hash
        hash<T> hash;
        return hash(key);
    }
    virtual int size()
    {
        return this->siz;
    }
    virtual bool empty()
    {
        return !this->siz;
    }

    ~Hash()
    {
        delete[] this->arr;
        delete[] this->filled;
    }
};

#endif // !HASH_H