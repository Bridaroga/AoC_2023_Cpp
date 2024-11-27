#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Convierte cada línea de String a un Vector<int>
std::vector<int> stringToVector(const std::string& linea) {
    std::vector<int> valores {};
    std::string numero { "" };

    for (std::size_t i = 0; i < linea.size(); i++) {
        std::size_t inicioNumero { linea.find_first_of("-0123456789", i) };
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

// Suma el último número de cada vector interno de forma recursiva.
int sumaUltimoNumero(std::vector<int> numeros) {
    std::size_t contador { 0 };
    std::size_t tamaño { numeros.size() };
    for (std::size_t i { 0 }; i < tamaño - 1; i++) {
        numeros[i] = numeros[i + 1] - numeros[i];
        if (numeros[i] == 0) {
            contador++;
        }
    }

    if (contador == tamaño - 1) {
        return numeros[tamaño - 1];
    } else {
        int último {numeros[tamaño - 1]};
        numeros.pop_back();
        return sumaUltimoNumero(numeros) + último;
    }

    return 0;
}



int main() {
    std::ifstream oasisDocument("OASIS.txt");

    std::string lineaReporte{ "" };
    int sumaExtrapolada{ 0 };
    std::vector<int> vectorNumeros{};

    while (!oasisDocument.eof()) {
        std::getline(oasisDocument, lineaReporte);
        vectorNumeros = stringToVector(lineaReporte);
        sumaExtrapolada += sumaUltimoNumero(vectorNumeros);

        vectorNumeros.clear();
    }

    std::cout << sumaExtrapolada << '\n';
}