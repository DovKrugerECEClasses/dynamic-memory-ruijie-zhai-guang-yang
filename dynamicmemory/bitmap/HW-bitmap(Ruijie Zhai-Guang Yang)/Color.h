//
// Created by Jarry on 2018/10/27.
//


#include <iostream>
#pragma once

class Color {
private:
    uint32_t rgba;
public:
    Color();
    uint32_t getValue() const;
    Color(uint8_t r, uint8_t g, uint8_t b) ;
    //TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}

};

