//
// Created by hugo on 03/03/2020.
//

#ifndef UNTITLED_COLOR_H
#define UNTITLED_COLOR_H


class Color {
private:
    unsigned char red;
    unsigned char Green;
    unsigned char Blue;
public:
    Color(unsigned char red, unsigned char Green, unsigned char Blue);
    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
    unsigned char setRed();
    unsigned char setGreen();
    unsigned char setBlue();
};


#endif //UNTITLED_COLOR_H
