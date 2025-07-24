#include "Matriz.hpp"
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <iostream>

namespace MatrizLib {

 Matriz crearMatriz(int filas, int columnas) {
        if (filas <= 0 || columnas <= 0) {
            throw std::invalid_argument("Dimensiones inv�lidas.");
        }

        Matriz nueva(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                nueva.setValor(i, j, 0);
            }
        }

        return nueva;
    }
    
    void Matriz::asignarMemoria() {
        datos = new double*[filas];
        for (int i = 0; i < filas; ++i) {
            datos[i] = new double[columnas];
            for (int j = 0; j < columnas; ++j) {
                datos[i][j] = 0.0;
            }
        }
    }

    void Matriz::liberarMemoria() {
        if (datos) {
            for (int i = 0; i < filas; ++i) {
                delete[] datos[i];
            }
            delete[] datos;
            datos = nullptr;
        }
    }

    double Matriz::calcularDeterminante(double** m, int n) const {
        if (n == 1) return m[0][0];
        if (n == 2) return m[0][0]*m[1][1] - m[0][1]*m[1][0];

        double det = 0.0;
        for (int p = 0; p < n; ++p) {
            double** submatriz = new double*[n-1];
            for (int i = 0; i < n-1; ++i)
                submatriz[i] = new double[n-1];

            for (int i = 1; i < n; ++i) {
                int sub_j = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == p) continue;
                    submatriz[i-1][sub_j++] = m[i][j];
                }
            }

            int signo = (p % 2 == 0) ? 1 : -1;
            double cofactor = signo * m[0][p] * calcularDeterminante(submatriz, n-1);
            det += cofactor;

            for (int i = 0; i < n-1; ++i)
                delete[] submatriz[i];
            delete[] submatriz;
        }
        return det;
    }

    Matriz::Matriz(): filas(0), columnas(0), datos(nullptr) {}

    Matriz::Matriz(int f, int c): filas(f), columnas(c) {
        if (filas <= 0 || columnas <= 0)
            throw std::invalid_argument("Dimensiones deben ser positivas.");
        asignarMemoria();
    }

    Matriz::Matriz(const Matriz& otra): filas(otra.filas), columnas(otra.columnas) {
        asignarMemoria();
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                datos[i][j] = otra.datos[i][j];
    }

    Matriz& Matriz::operator=(const Matriz& otra) {
        if (this != &otra) {
            liberarMemoria();
            filas = otra.filas;
            columnas = otra.columnas;
            asignarMemoria();
            for (int i = 0; i < filas; ++i)
                for (int j = 0; j < columnas; ++j)
                    datos[i][j] = otra.datos[i][j];
        }
        return *this;
    }

    Matriz::~Matriz() {
        liberarMemoria();
    }

    void Matriz::llenarMatriz() {
        std::cout << "Ingrese los elementos de la matriz (" << filas << "x" << columnas << "):\n";
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "[" << i << "," << j << "]: ";
                while (!(std::cin >> datos[i][j])) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Valor inv�lido. Ingrese nuevamente: ";
                }
            }
        }
    }

    void Matriz::mostrarMatriz() const {
        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << std::setw(8) << datos[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

