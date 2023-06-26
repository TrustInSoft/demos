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

template <typename T> class IncrementableArray {
private:
    T* array = NULL;
    int size = -1;
 
public:
    IncrementableArray();
    IncrementableArray(T arr[], int s);
    IncrementableArray(int s);
    ~IncrementableArray();
    void increment(T val);
    void decrement(T val);
    int get_size();
    int get(int index);
    bool set(int index, T val);
    std::string toString();
    void print();
};
