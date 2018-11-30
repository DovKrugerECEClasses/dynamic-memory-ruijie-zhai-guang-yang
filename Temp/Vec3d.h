//
// Created by Guang Yang on 11/29/18.
//
#include <iostream>
#pragma once
using namespace std;

template <typename T>
class Vec3d {
private:
    T a, b, c;
public:
    Vec3d(const T& a=0, const T& b=0, const T& c=0):a(a), b(b), c(c){}

    friend Vec3d<T> operator +(const Vec3d<T>& l, const Vec3d<T>& r){
        return Vec3d(l.a + r.a, l.b + r.b, l.c + r.c);
    }

    friend ostream& operator << (ostream& s, const Vec3d<T>& c){
        return  s << c.a << ", " << c.b << ", " << c.c << '\n';
    }
};
