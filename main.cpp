#include "Matriz.hpp"
#include <iostream>

using namespace MatrizLib;

int main() {
    try {
        std::cout << "== Creando matriz A ==" << std::endl;
        Matriz A = crearMatriz(2, 2);
        A.llenarMatriz();
        A.mostrarMatriz();

        std::cout << "\n== Creando matriz B ==" << std::endl;
        Matriz B = crearMatriz(2, 2);
        B.llenarMatriz();
        B.mostrarMatriz();

        std::cout << "\n== Suma A + B ==" << std::endl;
        Matriz C = A.suma(B);
        C.mostrarMatriz();

        std::cout << "\n== Producto A * B ==" << std::endl;
        Matriz D = A.multiplicacion(B);
        D.mostrarMatriz();

        std::cout << "\n== Transpuesta de A ==" << std::endl;
        Matriz At = A.transpuesta();
        At.mostrarMatriz();

        std::cout << "\n== Determinante de A ==" << std::endl;
        std::cout << A.determinante() << std::endl;

        std::cout << "\n== Comparando A y B ==" << std::endl;
        std::cout << (A.esIgual(B) ? "Son iguales" : "Son diferentes") << std::endl;

        std::cout << "\n== A�adiendo fila y columna a A ==" << std::endl;
        A.anadirFila();
        A.anadirColumna();
        A.mostrarMatriz();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


