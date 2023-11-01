#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include <iostream>
#include <string.h>
#include "Hash.h"
using namespace std;

template <class T, class V>
class linearProbing : public Hash<T, V>
{
private:
    void resize()
    {
        int oldCapacity = this->capacity;
        this->capacity *= 2;
        pair<T, V> *newArr = new pair<T, V>[this->capacity];
        bool *newFilled = new bool[this->capacity];
        memset(newFilled, false, sizeof(newFilled));
        for (int i = 0; i < oldCapacity; i++)
        {
            if (this->filled[i])
            {
                int index = this->hashFunction(this->arr[i].first) % this->capacity;
                int j = 1;
                while (j < this->capacity)
                {
                    if (newFilled[index])
                    {
                        index = this->next(this->arr[i].first, j);
                        j++;
                    }
                    else
                    {
                        newArr[index] = this->arr[i];
                        newFilled[index] = true;
                        break;
                    }
                }
            }
        }
        delete[] this->arr;
        delete[] this->filled;
        this->arr = newArr;
        this->filled = newFilled;
        newArr = nullptr;
        newFilled = nullptr;
    }

public:
    linearProbing(int siz = 0) : Hash<T, V>(siz)
    {
    }

    int next(T key, int add)
    {
        return (this->hashFunction(key) + add) % this->capacity;
    }

    bool insertItem(T key, V value)
    {
        if (this->capacity * this->loadFactor <= this->siz + 1)
        {
            this->resize();
        }
        int index = this->hashFunction(key) % this->capacity;
        int i = 1;
        while (i < this->capacity)
        {
            if (this->filled[index] && this->arr[index].first != key)
            {
                index = this->next(key, i);
                i++;
            }
            else
            {
                this->siz += !this->filled[index];
                this->arr[index].first = key;
                this->arr[index].second = value;
                this->filled[index] = true;
                return true;
            }
        }
        return false;
    }

    V getItem(T key)
    {
        int index = this->hashFunction(key) % this->capacity;
        int i = 1;
        while (i < this->capacity)
        {
            if (this->filled[index])
            {
                if (this->arr[index].first == key)
                {
                    return this->arr[index].second;
                }
                index = this->next(key, i);
                i++;
            }
            else
            {
                return V{};
            }
        }
        return V{};
    }

    bool deleteItem(T key)
    {
        int index = this->hashFunction(key) % this->capacity;
        int i = 1;
        while (i < this->capacity)
        {
            if (this->filled[index])
            {
                if (this->arr[index].first == key)
                {
                    this->siz--;
                    this->filled[index] = false;
                    return true;
                }
                index = this->next(key, i);
                i++;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    bool searchItem(T key)
    {
        int index = this->hashFunction(key) % this->capacity;
        int i = 1;
        while (i < this->capacity)
        {
            if (this->filled[index])
            {
                if (this->arr[index].first == key)
                {
                    return true;
                }
                index = this->next(key, i);
                i++;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    ~linearProbing()
    {
    }
};

#endif // !LINEAR_PROBING_H