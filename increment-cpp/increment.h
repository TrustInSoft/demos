/*
trustinsoft/demos
Copyright (C) 2024 TrustInSoft
mailto:contact AT trust-in-soft DOT com
*/

#ifndef INCREMENT_H
#define INCREMENT_H

#include <string>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <functional>

template <typename T>
class IncrementableArray {
private:
    int size;
    T* array;
    std::function<T(T&)> lambda;
public:
    IncrementableArray(int s=0,
                       T* arr=nullptr,
                       std::function<T(T&)> l = [](T&t){return t+1;})
        : size(s), array(nullptr), lambda(l)
    {
        if (size > 0) {
            array = new T[size];
            for (int i = 0; i < size; i++)
                array[i] = arr!=nullptr?arr[i]:T();
        }
    }
    // delete copy constructor
    IncrementableArray(const IncrementableArray<T>& arr)=delete;
    ~IncrementableArray() {
        if (array!=nullptr)
            delete[] array;
        array=nullptr;
    }
    T sum() {
        T answer=0;
        for (int i=0;i<size;++i) answer += array[i];
        return answer;
    }
    void increment() {
        if (size > 0) {
            int index = size;
            T *item = array;
            while (index >= 0) {
                T value = *item;
                (*item) = lambda(value); // Increment the value of the cell
                item++;                  // Move to next array cell
                index--;                 // Decrement loop counter
            }
        }
    }
    int get_size() const {
        return size;
    }
    T get(int index) const  { return array[index]; }
    T set(int index, T val)  {
        if (index < size) {
            array[index] = val;
        }
        return val;
    }
    friend std::ostream& operator<<(std::ostream& os,
                                    const IncrementableArray & ia)
    {
        return os;
        if (ia.size <1)
            os << "{}";
        else {
            int maxStringCell=10;
            os << "{";
            bool dotted = false;
            for (int i = 0; i < ia.size; i++) {
                if (i<(maxStringCell/2) || i > ia.size-(maxStringCell/2)){
                    os << ia.array[i]
                       << std::string((i == ia.size - 1) ? "" : ", ");
                } else if (!dotted) {
                    os << "..., ";
                    dotted = true;
                }
            }
            os << "}";
        }
        return os;
    }

    void print();
};

#endif
