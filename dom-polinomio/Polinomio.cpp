//
// Created by Daniel Durán on 1/3/21.
//

#include "Polinomio.h"
#include <cmath>
#include <algorithm>

Polinomio::Polinomio() {

}

void Polinomio::addMonomio(const int &coeficiente, const int &exponente) {
    std::vector<int> par(2);
    par[0]=coeficiente;
    par[1]=exponente;
    monomios.push_back(par);
}

int Polinomio::evaluar(const int &valor) const{
    int result=0;
    for (int i = 0; i < monomios.size(); ++i) {
        result=result+monomios[i][0]*pow(valor, monomios[i][1]);
    }
    return result;
}

void Polinomio::sort() {
    std::sort(monomios[1].begin(), monomios[1].end());
}
