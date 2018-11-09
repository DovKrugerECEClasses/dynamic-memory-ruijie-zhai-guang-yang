//
// Created by Jarry on 2018/11/8.
//
#include "Color.h"
#include <iostream>

using namespace std;

Color::Color():Color(255, 255, 255) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
    rgba = r;
    rgba <<= 8;
    rgba += g;
    rgba <<= 8;
    rgba += b;
    rgba <<= 8;
}


uint32_t Color::getValue() const {
    return rgba;
}

