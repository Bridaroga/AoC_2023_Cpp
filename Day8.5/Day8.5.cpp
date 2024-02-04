// Day8.5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <tuple>
#include <vector>

int main() {
    std::ifstream networkDocument("Network.txt");

    std::string lineaNetwork{ "" };
    std::string instrucciones{ "" };
    std::string::iterator itInstrucciones;
    std::string nodo{ "" };
    std::string izquierda{ "" };
    std::string derecha{ "" };
    std::string posicionNodo{ "" };

    size_t primerParentesis{ 0 };
    size_t segundoParentesis{ 0 };
    size_t coma{ 0 };
    size_t espacioFinal{ 0 };
    size_t contador{ 0 };
    size_t contadorNodos{ 0 };

    std::map<std::string, std::tuple<std::string, std::string>> nodos{};
    //std::map<std::string, std::tuple<std::string, std::string>>::iterator itNodos;

    std::vector<std::string> nodosFinalA{};

    std::getline(networkDocument, instrucciones);
    // Guarda cada nodo en el map.
    while (!networkDocument.eof()) {
        std::getline(networkDocument, lineaNetwork);
        if (lineaNetwork == "") {
            continue;
        }

        primerParentesis = lineaNetwork.find_first_of("(");
        coma = lineaNetwork.find_first_of(",");
        espacioFinal = lineaNetwork.find_last_of(" ");
        segundoParentesis = lineaNetwork.find_last_of(")");

        nodo = lineaNetwork.substr(0, lineaNetwork.find_first_of(" "));
        izquierda = lineaNetwork.substr(primerParentesis + 1, coma - primerParentesis - 1);
        derecha = lineaNetwork.substr(espacioFinal + 1, segundoParentesis - espacioFinal - 1);

        nodos.insert({ nodo, { izquierda, derecha } });
        if (nodo[2] == 'A') {
            nodosFinalA.push_back(nodo);
        }
    }

    itInstrucciones = instrucciones.begin();

    while (contadorNodos != nodosFinalA.size()) {
        contadorNodos = 0;
        for (auto& it : nodosFinalA) {
            if (*itInstrucciones == 'L') {
                it = std::get<0>(nodos.find(it)->second);
            }
            else {
                it = std::get<1>(nodos.find(it)->second);
            }

            if (it[2] == 'Z') {
                contadorNodos++;
            }
        }

        contador++;
        itInstrucciones++;
        if (itInstrucciones == instrucciones.end()) {
            itInstrucciones = instrucciones.begin();
        }
    }

    std::cout << contador << '\n';
}
