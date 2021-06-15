//DANIEL DURAN RIVERO
//C37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

bool compareNumGreater (const std::pair<std::string, int>& one, const std::pair<std::string, int>& two) {
    if(one.second<two.second){
        return false;
    }else if(one.second>two.second){
        return true;
    }else{
        return one.first<two.first;
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    std::string deporte;
    std::string alumno;
    std::cin >> alumno;

    if(!std::cin){
        return false;
    }

    std::unordered_map<std::string, int> deportes;
    std::unordered_map<std::string, std::string> deportesAlumnos;
    std::unordered_set<std::string> vetados;

    while(alumno!="_FIN_"){
        if (!isupper(alumno[0])){
            if(deportesAlumnos.find(alumno) == deportesAlumnos.cend()){
                deportesAlumnos[alumno]=deporte;
                deportes[deporte]++;
            }else{
                if(deportesAlumnos[alumno] != deporte){
                    if(vetados.find(alumno)==vetados.cend()){
                        vetados.insert(alumno);
                        deportes[deportesAlumnos[alumno]]--;
                        if(deportes[deportesAlumnos[alumno]] < 0){
                            deportes[deporte]=0;
                        }
                        deportesAlumnos[alumno]="TBD";
                    }
                }
            }
            std::cin >> alumno;
        }else{
            deporte=alumno;
            deportes[deporte]=0;
            std::cin >> alumno;
        }
    }


    std::vector<std::pair<std::string, int>> resultados;
    auto it = deportes.cbegin();
    while(it!=deportes.cend()){
        resultados.emplace_back(it->first, it->second);
        it++;
    }

    std::sort(resultados.begin(), resultados.end(), compareNumGreater);

    for (auto & resultado : resultados) {
        std::cout << resultado.first << " " << resultado.second << std::endl;
    }

    std::cout << "---" << std::endl;

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