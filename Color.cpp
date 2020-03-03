//
// Created by hugo on 03/03/2020.
//

#include "Color.h"
#include "Constants.h"

unsigned char Color::getRed() {
    return this->red;
}

unsigned char Color::getGreen() {
    return this-setGreen();
}

unsigned char Color::getBlue() {
    return this->Blue;
}

unsigned char Color::setRed(unsigned char color) {
    return this->red = color;
}

unsigned char Color::setGreen(unsigned char color) {
    return this->red = color;
}

unsigned char Color::setBlue(unsigned char color) {
    return this->red = color;
}

Color::Color(unsigned char red, unsigned char Green, unsigned char Blue) {
    this->red = red;
    this->Green = Green;
    this->Blue = Blue;
}
