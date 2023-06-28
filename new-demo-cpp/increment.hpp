/*
trustinsoft/demos
Copyright (C) 2023 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#pragma once
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <sstream>

template <typename T> class IncrementableArray {
private:
    T* array = NULL;
    int size = -1;
 
public:
    IncrementableArray();

    IncrementableArray(T arr[], int s);
    IncrementableArray(int s);
    IncrementableArray(const IncrementableArray<T>& arr);
    ~IncrementableArray();
    void increment(T val);
    void decrement(T val);
    int get_size() const;
    int get(int index) const;
    bool set(int index, T val);
    std::string toString();
    void print();
};

#define MAX_STRING_CELLS 10

template <typename T>
IncrementableArray<T>::IncrementableArray() {}

template <typename T>
IncrementableArray<T>::IncrementableArray(T arr[], int s)
{
    this->size = s;
    if (this->size <= 0)
        return;
    this->array = new T[s];
    for (int i = 0; i < size; i++)
        this->array[i] = arr[i];
}

template <typename T>
IncrementableArray<T>::IncrementableArray(int s)
{
    this->array = new T[s];
    this->size = s;
}

template <typename T>
IncrementableArray<T>::IncrementableArray(const IncrementableArray<T>& arr)
{
    this->size = arr.get_size();
    if (this->size <= 0) {
        this->array = NULL;
        return;
    }
    this->array = new T[this->size];
    for (int i = 0; i < this->size; i++)
        this->array[i] = arr.get(i);
}

template <typename T>
IncrementableArray<T>::~IncrementableArray()
{
    delete[] this->array;
}

template <typename T>
void IncrementableArray<T>::increment(T val)
{
    if (this->size <= 0)
        return;
    int index = this->size;
    T *item = this->array;
    while (index >= 0)
    {
        T value = *item;
        (*item) = value + 1; // Increment the value of the array cell
        item++;              // Move to next array cell
        index--;             // Decrement loop counter
    }
}

template <typename T>
void IncrementableArray<T>::decrement(T val)
{
    this.decrement(-val);
}

template <typename T>
int IncrementableArray<T>::get_size() const { return this->size; }

template <typename T>
int IncrementableArray<T>::get(int index) const { return this->array[index]; }

template <typename T>
bool IncrementableArray<T>::set(int index, T val)
{
    if (index < this->size) {
        this->array[index] = val;
        return true;
    }
    return false;
}

template <typename T>
std::string IncrementableArray<T>::toString()
{
    if (this->size == -1)
        return std::string("NULL");
    if (this->size == 0)
        return std::string("{}");

    int string_size = 3;
    if (this->size <= MAX_STRING_CELLS)
        string_size += this->size * 15;
    else
        string_size += MAX_STRING_CELLS * 15 + 5;
    std::string s;
    s.reserve(string_size);
    s = "{";
    bool dotted = false;
    std::ostringstream os;
    for (int i = 0; i < this->size; i++)
    {
        if (i < (MAX_STRING_CELLS / 2) || i > this->size - (MAX_STRING_CELLS / 2))
        {
            os << this->array[i] << std::string((i == this->size - 1) ? "" : ", ");
        }
        else if (!dotted)
        {
            os << "..., ";
            dotted = true;
        }
    }
    s += os.str();
    s += "}";
    return s;
}

template <typename T>
void IncrementableArray<T>::print()
{
    std::cout << this.toString();
}