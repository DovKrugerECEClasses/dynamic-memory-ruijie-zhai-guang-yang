//
// Created by Jarry on 2018/11/18.
//

#pragma once

#include <iostream>
using namespace std;

template<typename T>
class GrowArray {
private:
    int used;
    int capacity;
    T* data;
    void checkGrow() {
        if (used<capacity)
            return; // don't grow unless you have to
        T* old = data;

        if(capacity==0)
            capacity=1;
        else
            capacity*=2;
        //TODO: every time the list grows, double it!!!

        data = new T[capacity]; // calls T::T()
        for (int i = 0; i < used; i++)
            data[i] = old[i];
        delete [] old;
    }
public:
    GrowArray() : used(0), capacity(0), data(nullptr) {}
    GrowArray(int  initialCapacity) : used(0), capacity(initialCapacity), data(new T[capacity]) {}//TODO: fix!

    ~GrowArray(){
        delete [] data;
    }

    GrowArray& operator=(const GrowArray<T>& g){
        GrowArray copy(g);
        used = g.used;
        capacity = g.capacity;
        swap(data,copy.data);
        return *this;
    }
//TODO: add destructor, copy constructor, operator =
void addEnd(const T& v) {
    checkGrow();
    data[used] = v;
    used ++;
}

T removeEnd() {
    used--;
    return data[used];
}
T operator [](int i) const {
    return data[i];
}

T& operator [](int i) {
    return data[i];
}

friend ostream& operator <<(ostream& s, const GrowArray<T>& list) {
    for (int i = 0; i < list.used; i++)
        s << list[i] << ' ';
    return s;
}
};