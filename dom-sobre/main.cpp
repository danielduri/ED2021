// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int sobres, n;
    std::cin >> sobres >> n;
    if (sobres==0)
        return false;

    std::vector<int> resultado;
    std::queue<int> cola;
    std::set<int> contenidos;
    std::unordered_map<int, int> repeticiones;

    int maxActual=0;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if(num>maxActual){
            maxActual=num;
        }
        cola.push(num);
        contenidos.insert(num);
        repeticiones[num]++;
    }

    int count=n;
    resultado.push_back(maxActual);

    while (count<sobres){
        int num;
        std::cin >> num;
        repeticiones[cola.front()]--;
        if(repeticiones[cola.front()]==0){
            contenidos.erase(cola.front());
        }
        cola.pop();
        contenidos.insert(num);
        cola.push(num);
        repeticiones[num]++;
        count++;
        resultado.push_back(*contenidos.rbegin());
    }


    for (int i = 0; i < resultado.size(); ++i) {
        std::cout << resultado[i] << " ";
    }

    std::cout << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
