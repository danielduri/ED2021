//
// Created by Daniel Durán on 26/3/21.
//

#include "Complejo.h"
#include <cmath>

Complejo::Complejo(float real, float imaginary) : real(real), imaginary(imaginary) {}

Complejo Complejo::operator+(const Complejo &rhs) const {
    return {real+rhs.real, imaginary+rhs.imaginary};
}

Complejo Complejo::operator*(const Complejo &rhs) const {
    float r = real*rhs.real - imaginary*rhs.imaginary;
    float i = real*rhs.imaginary + rhs.real*imaginary;
    return {r, i};
}

double Complejo::mod() const {
    return sqrt(real*real + imaginary*imaginary);
}

bool Complejo::mandelbrot(int n) {
    bool result=true;
    int i=0;
    Complejo anterior(0,0);
    while (i<n && result){
        anterior = anterior*anterior + Complejo(real, imaginary);
        if (anterior.mod()>2){
            result=false;
        }
        i++;
    }
    return result;
}
