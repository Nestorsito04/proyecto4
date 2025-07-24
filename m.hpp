#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

namespace MatrizLib {

    class Matriz {
    private:
        double** datos;
        int filas;
        int columnas;

        void asignarMemoria();
        void liberarMemoria();
        double calcularDeterminante(double** m, int n) const;


