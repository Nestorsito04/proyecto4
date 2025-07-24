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

public:
        Matriz();
        Matriz(int f, int c);
        Matriz(const Matriz& otra);
        Matriz& operator=(const Matriz& otra);
        ~Matriz();

        void llenarMatriz();
        void mostrarMatriz() const;
        Matriz transpuesta() const;
        double determinante() const;
        Matriz suma(const Matriz& otra) const;
        Matriz multiplicacion(const Matriz& otra) const;
        bool esIgual(const Matriz& otra) const;

        void setValor(int f, int c, double valor);
        double getValor(int f, int c) const;
        int getFilas() const;
        int getColumnas() const;

        void anadirFila();
        void anadirColumna();
    };

    Matriz crearMatriz(int filas, int columnas);

}

#endif



