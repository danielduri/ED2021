//
// Created by Daniel Durán on 26/3/21.
//

#ifndef DOM_MANDELBROT_COMPLEJO_H
#define DOM_MANDELBROT_COMPLEJO_H


class Complejo {
public:
    Complejo(float real, float imaginary);

    Complejo operator+(const Complejo &rhs) const;
    Complejo operator*(const Complejo &rhs) const;
    double mod() const;
    bool mandelbrot(int n);

private:
    float real;
    float imaginary;
};


#endif //DOM_MANDELBROT_COMPLEJO_H
