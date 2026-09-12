#include <iostream>
#include <random>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"

using namespace std;

unsigned char** crearTablero (short filas, short columnas) {

    int bytesFila = calcularBytesFila(columnas);
    unsigned char** tablero = new unsigned char*[filas];

    for (int i = 0; i < filas; ++i) {
        tablero[i] = new unsigned char[bytesFila]();
        for (int j = 0; j < columnas; ++j) {
            escribirFicha(tablero,i,j,generarFichaAleatoria(),columnas);
        }
    }

    return tablero;
}

void mostrarTableroNormal (unsigned char **tablero, short filas, short columnas) {

    cout << "    ";
    for (int j = 0; j < columnas; ++j) {
        cout << j << " ";
    }
    cout << endl;
    for (int j = 0; j < (columnas + 4 + (columnas - 1)); ++j) {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < filas; ++i) {
        cout << i << " | ";
        for (int j = 0; j < columnas; ++j) {
            int valor = leerFicha(tablero, i, j, columnas);
            cout << obtenerCaracter(valor) << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void mostrarTableroBinario (unsigned char** tablero, short filas, short columnas) {

    cout << "    ";
    for (int j = 0; j < columnas; ++j) {
        cout << " " << j << "  ";
    }
    cout << endl;
    for (int j = 0; j < (columnas*3 + 4 + (columnas-1)); ++j) {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < filas; ++i) {
        cout << i << " | ";
        for (int j = 0; j < columnas; ++j) {
            int valor = leerFicha(tablero, i, j, columnas);
            cout << obtenerNumero(obtenerCaracter(valor)) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
