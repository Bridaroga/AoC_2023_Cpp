#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> valorExtrapolado(const std::string& linea) {
    std::vector<int> valores {};
    std::string numero { "" };
    std::size_t inicioNumero { 0 };

    for (std::size_t i = 0; i < linea.size(); i++) {
        inicioNumero = linea.find_first_of("-0123456789", i);
        std::size_t tempIndex = linea.find(' ', inicioNumero);
        if (tempIndex != std::string::npos) {
            i = tempIndex;
            numero = linea.substr(inicioNumero, tempIndex);
            valores.push_back(std::stoi(numero));
            inicioNumero = tempIndex;
        } else {
            i = linea.size();
            numero = linea.substr(inicioNumero);
            valores.push_back(std::stoi(numero));
        }
        
        numero = "";
    }

    return valores;
}

void restaValores(std::vector<int> numeros) {
    
}



int main() {
    std::ifstream oasisDocument("OASIS.txt");

    std::string lineaReporte{ "" };
    int sumaExtrapolada{ 0 };
    std::vector<int> vectorNumeros{};

    while (!oasisDocument.eof()) {
        std::getline(oasisDocument, lineaReporte);
        vectorNumeros = valorExtrapolado(lineaReporte);


        vectorNumeros.clear();
    }

    std::cout << sumaExtrapolada << '\n';
}