#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <tuple>

typedef std::tuple<int, int> coordenadas;
typedef std::map<coordenadas, char> mapa;

int main() {
    std::ifstream loopDocument("Loop.txt");
    std::string lineaLoop{ "" };
    coordenadas coordenadaInicial{};
    mapa mapaTubos{};
    int fila{ 0 };

    while (!loopDocument.eof()) {
        std::getline(loopDocument, lineaLoop);
        for (int columna = 0; columna < lineaLoop.size(); columna++) {
            mapaTubos.insert({ {fila, columna}, lineaLoop[columna] });
            if (lineaLoop[columna] == 'S') {
                coordenadaInicial = {fila, columna};
            }
        }
        fila++;
    }
}