// Day1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    // Variables
    std::string lineaArchivo{ "" };
    std::string::reverse_iterator iReversoLineaArchivo{};
    std::string lineaArchivoReverso{ "" };
    std::string numero{ "" };
    int numeros{ 0 };
    std::size_t lineaArchivoFind{ 0 };
    //std::size_t lineaArchivoFindReverso{ 0 };
    std::size_t lineaArchivoFindFirstOf{ 0 };
    std::size_t lineaArchivoFindLastOf{ 0 };

    std::map<std::string, std::string> numerosLetras{};
    //numerosLetras["zero"] = "0";
    numerosLetras["one"] = "1";
    numerosLetras["two"] = "2";
    numerosLetras["three"] = "3";
    numerosLetras["four"] = "4";
    numerosLetras["five"] = "5";
    numerosLetras["six"] = "6";
    numerosLetras["seven"] = "7";
    numerosLetras["eight"] = "8";
    numerosLetras["nine"] = "9";

    //std::map<std::string, std::string> numerosLetrasReverso{};
    //std::string numerosInversos{ "" };
    //for (auto& iteradorNumerosLetras : numerosLetras) {
    //    for (auto caracter = iteradorNumerosLetras.first.rbegin(); caracter != iteradorNumerosLetras.first.rend(); caracter++) {
    //        numerosInversos += *caracter;
    //    }
    //    numerosLetrasReverso.insert({ numerosInversos, iteradorNumerosLetras.second });
    //    //std::cout << numerosInversos << " + " << iteradorNumerosLetras.second << '\n';
    //    numerosInversos = "";
    //}


    std::map<std::size_t, std::string> numerosEncontrados{};
    std::map<std::size_t, std::string>::iterator iteradorNumerosEncontrados{};
    std::map<std::size_t, std::string>::reverse_iterator iteradorReversoNumerosEncontrados{};

    std::ifstream cDocument("Calibration document.txt");
    //std::cout << "El archivo abrio: " << cDocument.is_open() << '\n';
    while (!cDocument.eof()) {
        cDocument >> lineaArchivo;
        /*for (auto caracter = lineaArchivo.rbegin(); caracter != lineaArchivo.rend(); caracter++) {
            lineaArchivoReverso += *caracter;
        }*/
        lineaArchivoFindFirstOf = lineaArchivo.find_first_of("0123456789");
        lineaArchivoFindLastOf  = lineaArchivo.find_last_of("0123456789");

        //  it para buscar el primero
        for (auto& iteradorNumerosLetras : numerosLetras) {
            lineaArchivoFind = lineaArchivo.find(iteradorNumerosLetras.first);
            if (lineaArchivoFind == std::string::npos) {
                continue;
            }
            numerosEncontrados.insert({ lineaArchivoFind, iteradorNumerosLetras.second });

            lineaArchivoFind = lineaArchivo.rfind(iteradorNumerosLetras.first);
            if (lineaArchivoFind == std::string::npos) {
                continue;
            }
            numerosEncontrados.insert({ lineaArchivoFind, iteradorNumerosLetras.second });
        }

        //  it para buscar el último en reversa
        /*for (auto& iteradorNumerosLetrasReverso : numerosLetrasReverso) {
            lineaArchivoFindReverso = lineaArchivoReverso.find(iteradorNumerosLetrasReverso.first);
            if (lineaArchivoFindReverso == std::string::npos) {
                continue;
            }
            lineaArchivoFind = lineaArchivo.length() - lineaArchivoFindReverso - iteradorNumerosLetrasReverso.first.length();
            numerosEncontrados.insert({ lineaArchivoFind, iteradorNumerosLetrasReverso.second });
        }*/

        if (!numerosEncontrados.empty()) {
            iteradorNumerosEncontrados = numerosEncontrados.begin();

            if (lineaArchivoFindFirstOf != std::string::npos && lineaArchivoFindFirstOf < (*iteradorNumerosEncontrados).first) {
                numero += lineaArchivo[lineaArchivoFindFirstOf];
            }
            else {
                numero += (*iteradorNumerosEncontrados).second;
            }

            iteradorReversoNumerosEncontrados = numerosEncontrados.rbegin();

            if (lineaArchivoFindLastOf != std::string::npos && lineaArchivoFindLastOf > (*iteradorReversoNumerosEncontrados).first) {
                numero += lineaArchivo[lineaArchivoFindLastOf];
            }
            else {
                numero += (*iteradorReversoNumerosEncontrados).second;
            }
        }
        else {
            numero += lineaArchivo[lineaArchivoFindFirstOf];
            numero += lineaArchivo[lineaArchivoFindLastOf];
        }

        //std::cout << numero << '\n';
        numerosEncontrados.clear();


        //std::cout << linea.find_first_of("0123456789") << " " << linea[linea.find_first_of("0123456789")] << '\n';

        numeros += std::stoi(numero);
        numero = "";
    }
    std::cout << numeros << '\n';
}
