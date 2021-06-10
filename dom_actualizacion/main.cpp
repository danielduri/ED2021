//DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
//C37 y C38

#include <sstream> //para strinstream
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TreeMap.h"

/*
 * coste:
 * La funcion calcularCambios tiene coste lineal en el número de claves del diccionario, ya que tiene que pasar
 * por todas las claves para comprobar si existen en el otro diccionario y viceversa. La gestión de las listas de cambios
 * tiene coste constante. Por tanto O(n), donde n=el número de entradas del diccionario (en realidad, la suma del
 * número de entradas de los dos diccionarios, por tanto se asemejará a O(2n); en coste asintótico O(n)).
 *
 * La funcion printCambios tiene coste lineal en la suma del número de elementos de las tres listas.
 * O(n), donde n=la suma del número de elementos de las tres listas
 */

//Hay que elegir un diccionario.
//¿Necesitamos que esté ordenado? ¿Que no lo esté?
typedef TreeMap <string, int> Diccionario;

void leerDiccionario(Diccionario& diccionario){
    string linea;
    getline(cin, linea);
    stringstream lin(linea); //procesar la línea
    string clave;
    int valor;
    while (lin >> clave) {
       lin >> valor;
       diccionario.insert(clave,valor);
    }
}

//Método que hace el problema. Recibe los diccionarios antiguo y nuevo.
//Debe devolver los cambios en alguna/s estructura/s adecuada/s
void calcularCambios(const Diccionario& DiccionarioAntiguo,const Diccionario& DiccionarioNuevo, vector<string> & listNuevos, vector<string> & listEliminados, vector<string> & listCambios){
	Diccionario::ConstIterator itNuevo = DiccionarioNuevo.cbegin();
    while (itNuevo!=DiccionarioNuevo.cend()){
        if (!(DiccionarioAntiguo.contains(itNuevo.key()))){
            listNuevos.push_back(itNuevo.key());
        }else{
            if(itNuevo.value()!=DiccionarioAntiguo.at(itNuevo.key())){
                listCambios.push_back(itNuevo.key());
            }
        }
        itNuevo++;
    }

    Diccionario::ConstIterator itAntiguo = DiccionarioAntiguo.cbegin();
    while (itAntiguo!=DiccionarioAntiguo.cend()){
        if (!(DiccionarioNuevo.contains(itAntiguo.key()))){
            listEliminados.push_back(itAntiguo.key());
        }
        itAntiguo++;
    }
}

//Método para escribir por pantalla los cambios en los diccionarios.
void printCambios( vector<string> const & listNuevos, vector<string> const & listEliminados, vector<string> const & listCambios) {
    if (listNuevos.empty() && listEliminados.empty() && listCambios.empty()) {
        std::cout << "Sin cambios";
        std::cout << std::endl;
    } else {
        if(!(listNuevos.empty())){
            std::cout << "+ ";
            for (int i = 0; i < listNuevos.size(); ++i) {
                std::cout << listNuevos[i] << " ";
            }
            std::cout << std::endl;
        }
        if(!(listEliminados.empty())){
            std::cout << "- ";
            for (int i = 0; i < listEliminados.size(); ++i) {
                std::cout << listEliminados[i] << " ";
            }
            std::cout << std::endl;
        }
        if(!(listCambios.empty())){
            std::cout << "* ";
            for (int i = 0; i < listCambios.size(); ++i) {
                std::cout << listCambios[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << "---";
    std::cout << std::endl;
}


//Esqueleto para resuelve caso: leemos los diccionarios, calculamos
//los cambios y los sacamos por pantalla.
void resuelveCaso(){
    Diccionario DiccionarioAntiguo, DiccionarioNuevo;
    std::vector<string> listNuevos, listEliminados, listCambios;
    leerDiccionario(DiccionarioAntiguo);
    leerDiccionario(DiccionarioNuevo);
    calcularCambios(DiccionarioAntiguo,DiccionarioNuevo, listNuevos, listEliminados, listCambios);
    printCambios(listNuevos, listEliminados, listCambios);
}

//Método main.
int main(){
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos;
  	std::cin >> numCasos;
    std::cin.ignore(1); //ignorar salto de línea
    for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

return 0;
}
