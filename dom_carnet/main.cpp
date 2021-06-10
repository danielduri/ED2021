#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

//DANIEL DURÁN RIVERO y JULIÁN ENCINAS FUENTES
//C37 y C38

using namespace std;
using dni=string;
using puntos=int;

class carnet_puntos {
private:
    unordered_map<dni, puntos> puntosConductores;
    unordered_map<puntos, int> recuentoPuntos;
public:
    void nuevo(const dni& conductor){
        if(puntosConductores.find(conductor)==puntosConductores.end()){
            puntosConductores.insert(pair<dni, puntos>(conductor, 15));
            recuentoPuntos[15]++;
        }else{
            throw domain_error("Conductor duplicado");
        }
    }

    void quitar(const dni& conductor, puntos cantidad){
        if(puntosConductores.find(conductor)!=puntosConductores.end()){
            recuentoPuntos[puntosConductores[conductor]]--;
            puntosConductores[conductor]-=cantidad;
            if(puntosConductores[conductor]<0){
                puntosConductores[conductor]=0;
            }
            recuentoPuntos[puntosConductores[conductor]]++;
        }else{
            throw domain_error("Conductor inexistente");
        }
    }

    puntos consultar(const dni& conductor){
        if(puntosConductores.find(conductor)!=puntosConductores.end()){
            return puntosConductores[conductor];
        }else{
            throw domain_error("Conductor inexistente");
        }
    }

    int cuantos_con_puntos(puntos num){
        if(num>=0 && num<=15){
            return recuentoPuntos[num];
        }else{
            throw domain_error("Puntos no validos");
        }
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    carnet_puntos DGT;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo") {
                dni conductor;
                cin >> conductor;
                DGT.nuevo(conductor);
            } else if (comando == "quitar") {
                dni conductor;
                puntos num;
                cin >> conductor >> num;
                DGT.quitar(conductor, num);
            } else if (comando == "consultar") {
                dni conductor;
                cin >> conductor;
                puntos num = DGT.consultar(conductor);
                cout << "Puntos de " << conductor << ": " << num << "\n";
            } else if (comando == "cuantos_con_puntos") {
                puntos num;
                cin >> num;
                puntos result = DGT.cuantos_con_puntos(num);
                cout << "Con "<< num << " puntos hay " << result << "\n";
            }
        } catch (std::exception &e) {
            cout << "ERROR: " << e.what() << "\n";
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
