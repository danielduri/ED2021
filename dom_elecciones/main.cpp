#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

//DANIEL DURÁN RIVERO y JULIÁN ENCINAS FUENTES
//C37 y C38

using namespace std;
using Estado=string;
using Partido=string;

class ConteoVotos {
private:
    struct DatosEstado{
        int num_compromisarios{};
        pair<Partido, int> partidoGanador;
        unordered_map<Partido, int> votosPartidos;
    };
    map<Partido, int> compromisariosPartidos;
    unordered_map<Estado, DatosEstado> resultadosEstatales{};


public:

    //COSTE: constante
  void nuevo_estado(const Estado &nombre, int num_compromisarios) {
      if(resultadosEstatales.find(nombre)==resultadosEstatales.cend()){
          DatosEstado nuevo;
          nuevo.num_compromisarios = num_compromisarios;
          resultadosEstatales.insert(pair<Estado, DatosEstado>(nombre, nuevo));
      }else{
          throw domain_error(
                  "Estado ya existente"
                  );
      }
  }

  //COSTE: logarítmico en el caso peor; si hay que cambiar algo de compromisariosPartidos (mapa ordenado)
  void sumar_votos(const Estado &estado, const Partido &partido, int num_votos) {
      auto it = resultadosEstatales.find(estado);
      if(it!=resultadosEstatales.cend()){
          DatosEstado datos_estado = it->second;
          datos_estado.votosPartidos[partido] += num_votos;
          if (datos_estado.partidoGanador.first!=partido && datos_estado.votosPartidos[partido]>datos_estado.partidoGanador.second){
              Partido perdedor = datos_estado.partidoGanador.first;
              compromisariosPartidos[perdedor] -= datos_estado.num_compromisarios;
              if(compromisariosPartidos[perdedor]<=0){
                  compromisariosPartidos.erase(perdedor);
              }
              datos_estado.partidoGanador=pair<Partido, int>(partido, num_votos);
              compromisariosPartidos[partido] += datos_estado.num_compromisarios;
          }
          resultadosEstatales[estado]=datos_estado;
      }else{
          throw domain_error(
                  "Estado no encontrado"
          );
      }
  }

  //COSTE: constante
  Partido ganador_en(const Estado &estado) const {
      auto it = resultadosEstatales.find(estado);
      if(it!=resultadosEstatales.cend()){
          DatosEstado resultado = it->second;
          return resultado.partidoGanador.first;
      }else{
          throw domain_error(
                  "Estado no encontrado"
          );
      }
  }

  //COSTE: lineal en el número de elementos del mapa; los partidos existentes en él
  vector<pair<Partido,int>> resultados() const {
      vector<pair<Partido,int>> resultados;
      auto it = compromisariosPartidos.cbegin();
      while(it!=compromisariosPartidos.cend()){
          resultados.emplace_back(it->first, it->second);
          it++;
      }
      return resultados;
  }
 }; 


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            } else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            } else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador  = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            } else if (comando == "resultados") {
                for (const auto &[partido, num_comp] : elecciones.resultados()) {
                    cout << partido << " " << num_comp << "\n";
                }
            }
        } catch (std::exception &e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
