#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <tuple>

typedef std::tuple<int, int> coordenadas;
typedef std::map<coordenadas, char> mapa;

// Ver si guardar cada char, linea o mapa
mapa guardarLinea(std::string linea) {


    return { 0, 0 };
}

int main() {
    std::ifstream loopDocument("Loop.txt");
    std::string lineaLoop{ "" };
    mapa mapaTubos{};

    while (!loopDocument.eof()) {
        std::getline(loopDocument, lineaLoop);
        
    }
}