// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
using medico=string;
using paciente=string;

class fecha{
    int dia;
    int hora;
    int minuto;
public:
    int getDia() const {
        return dia;
    }

    int getHora() const {
        return hora;
    }

    int getMinuto() const {
        return minuto;
    }

    fecha(int dia, int hora, int minuto) : dia(dia), hora(hora), minuto(minuto) {}

    friend bool operator<(const fecha &lhs, const fecha &rhs) {
        if (lhs.dia < rhs.dia)
            return true;
        if (rhs.dia < lhs.dia)
            return false;
        if (lhs.hora < rhs.hora)
            return true;
        if (rhs.hora < lhs.hora)
            return false;
        return lhs.minuto < rhs.minuto;
    }
};

class Consultorio{
private:
    unordered_map<medico, map<fecha, paciente>> consultas;
public:
    void nuevoMedico(const medico& m){
        if(consultas.find(m)==consultas.cend()){
            consultas.insert(pair<medico, map<fecha, paciente>>(m, map<fecha, paciente>()));
        }
    }

    void pideConsulta(const paciente& p, const medico& m, fecha f){
        if(consultas.find(m)==consultas.cend()){
            throw domain_error("Medico no existente");
        }else{
            if(consultas[m].find(f)!=consultas[m].cend()){
                throw domain_error("Fecha ocupada");
            }else{
                consultas[m].insert(pair<fecha, paciente>(f, p));
            }
        }
    }

    paciente siguientePaciente(const medico& m){
        if(consultas.find(m)==consultas.cend()){
            throw domain_error("Medico no existente");
        }else{
            if (consultas[m].empty()){
                throw domain_error("No hay pacientes");
            }else{
                return consultas[m].cbegin()->second;
            }
        }
    }

    void atiendeConsulta(const medico& m){
        if(consultas.find(m)==consultas.cend()){
            throw domain_error("Medico no existente");
        }else{
            if (consultas[m].empty()){
                throw domain_error("No hay pacientes");
            }else{
                consultas[m].erase(consultas[m].begin());
            }
        }
    }

    vector<pair<paciente, fecha>> listaPacientes(const medico& m, int d){
        if(consultas.find(m)==consultas.cend()){
            throw domain_error("Medico no existente");
        }else{
            vector<pair<paciente, fecha>> result;

            map<fecha, paciente>::const_iterator it;
            fecha f = fecha(d, 0, 0);
            it=consultas[m].lower_bound(f);
            while(it->first.getDia()==d && it!=consultas[m].cend()){
                result.emplace_back(pair<paciente, fecha>(it->second, it->first));
                it++;
            }

            return result;
        }
    }
};



bool resuelveCaso() {
    string comando;

    int n;
    cin>>n;
    int count=0;
    Consultorio consultorio;

    while (count < n) {
        if (! std::cin)
            return false;
        cin >> comando;
        try {
            if (comando == "nuevoMedico") {
                medico m;
                cin >> m;
                consultorio.nuevoMedico(m);
            } else if (comando == "pideConsulta") {
                paciente p;
                medico m;
                int dia;
                string hora;
                cin >> p >> m >> dia >> hora;
                int h1 = hora[0]-48;
                int h2 = hora[1]-48;
                int h=h1*10+h2;
                int m1=hora[3]-48;
                int m2=hora[4]-48;
                int min=m1*10+m2;
                fecha f(dia, h, min);
                consultorio.pideConsulta(p, m, f);
            } else if (comando == "siguientePaciente") {
                medico m;
                cin >> m;
                paciente p = consultorio.siguientePaciente(m);
                cout << "Siguiente paciente doctor " << m << "\n" << p << "\n";
            } else if (comando == "atiendeConsulta") {
                medico m;
                cin >> m;
                consultorio.atiendeConsulta(m);
            } else if (comando == "listaPacientes") {
                medico m;
                int d;
                cin >> m >> d;
                cout << "Doctor " << m << " dia " << d << endl;
                vector<pair<paciente, fecha>> result = consultorio.listaPacientes(m, d);
                for (int i=0; i<result.size(); i++) {
                    cout << result[i].first << " " << std::setw(2) << std::setfill('0') << result[i].second.getHora() << ":" << std::setw(2) << std::setfill('0') << result[i].second.getMinuto() << "\n";
                }
            }
        } catch (std::exception &e) {
            cout << e.what() << "\n";
        }
        count++;
    }

    cout << "---\n";
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
