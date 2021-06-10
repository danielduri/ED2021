//
// Created by Daniel Durán on 1/3/21.
//

#ifndef DOM_POLINOMIO_POLINOMIO_H
#define DOM_POLINOMIO_POLINOMIO_H


#include <vector>

class Polinomio {
private:
    std::vector<std::vector<int>> monomios;

public:
    Polinomio();
    void addMonomio(int const & coeficiente, int const & exponente);
    int evaluar(int const & valor) const;

    void sort();
};


#endif //DOM_POLINOMIO_POLINOMIO_H
