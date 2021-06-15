//
// Created by Daniel Durán on 1/3/21.
//

#include "Polinomio.h"

Polinomio::Polinomio() = default;

void Polinomio::addMonomio(const int &coeficiente, const int &exponente) {
    std::pair<int, int> monomio = std::pair<int, int>(coeficiente, exponente);
    auto it = monomios.begin();
    while(it!=monomios.end() && it->second<exponente){
        it++;
    }
    monomios.insert(it, monomio);
}

int Polinomio::evaluar(const int &valor) const{
    int result=0;
    for (const auto & monomio : monomios) {
        int num=1;
        for (int i = 0; i < monomio.second; ++i) {
            num=num*valor;
        }
        result=result+monomio.first*num;
    }
    return result;
}
