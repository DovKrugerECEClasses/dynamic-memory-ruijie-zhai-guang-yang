//
// Created by Guang Yang on 11/29/18.
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
        if(capacity == 1 && used == 0){
            data = new T[capacity];
        }
        used++;
        if (used<capacity)
            return; // don't grow unless you have to
        T*old=data;
        //TODO: every time the list grows, double it!!!
        data = new T[capacity*2]; // calls T::T()
        capacity*=2;
        for (int i = 0; i < used; i++)
            data[i]=old[i];
    }
public:
    GrowArray() : used(0), capacity(1), data(nullptr) {}
    //TODO: fix!
//TODO: add destructor, copy constructor, operator =
void addEnd(const T& v) {
    checkGrow();
    data[used-1] = v;
}

GrowArray operator = (GrowArray &orig){
        GrowArray temp;
        temp.copy(orig);
        used = orig.used;
        capacity = orig.capacity;
        swap(data,orig.data);
        return *this;
}

GrowArray(const GrowArray&orig){
        GrowArray temp;
        temp.copy(orig);
        used = orig.used;
        capacity = orig.capacity;
        swap(data,orig.data);
        return temp;

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

friend std::ostream& operator <<(ostream& s, const GrowArray<T>& list) {
    for (int i = 0; i < list.used; i++)
        s << list[i] << ' ';
    return s;
}
~GrowArray(){
        delete []data;
    }
};
