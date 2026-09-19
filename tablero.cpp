#include <iostream>
#include <random>
#include "tablero.h"
#include "bits.h"
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


short reorganizarTablero (unsigned char **tablero, short filas, short columnas) {

    bool huboMovimiento = false;

    for (int j = 0; j < columnas; ++j) {
        int posicion = filas - 1;
        for (int i = filas-1; i >= 0; --i) {
            int ficha = leerFicha(tablero,i,j,columnas);
            if (ficha != 0) {
                escribirFicha(tablero,posicion,j,ficha,columnas);
                posicion--;
            }
        }
        while (posicion >= 0) {
            huboMovimiento = true;
            escribirFicha(tablero,posicion,j,generarFichaAleatoria(),columnas);
            posicion--;
        }
    }

    return huboMovimiento ? 1 : 0;

}

int* procesarCascada(unsigned char **tablero, short filas, short columnas) {

    bool hayCombinaciones = true;
    short numCombinaciones = 0;
    short numCascadas = 0;
    int puntos = 0;

    while (hayCombinaciones) {

        bool* eliminar = new bool[filas * columnas]();

        numCascadas += reorganizarTablero(tablero, filas, columnas);

        int* arrComb = detectarCombinaciones(tablero, filas, columnas, eliminar);
        numCombinaciones += arrComb[0];
        puntos += arrComb[1];
        delete[] arrComb;

        hayCombinaciones = false;

        for (int i = 0; i < filas * columnas; ++i) {
            if (eliminar[i]) {
                hayCombinaciones = true;
                break;
            }
        }

        if (hayCombinaciones) {
            eliminarCombinaciones(tablero, filas, columnas, eliminar);
            numCascadas += reorganizarTablero(tablero, filas, columnas);
        }

        delete[] eliminar;
    }
    int* arr = new int[3]{numCombinaciones,numCascadas,puntos};
    return arr;
}


void redimensionar (unsigned char** &tablero, short filas, short columnas, short &capacidadFilas, short &capacidadColumnas) {

    short nuevaCapacidadFilas = filas;
    short nuevaCapacidadColumnas = columnas;

    int bytesFila = calcularBytesFila(nuevaCapacidadColumnas);

    unsigned char** nuevoTablero = new unsigned char*[nuevaCapacidadFilas];

    for (int i = 0; i < nuevaCapacidadFilas; ++i) {
        nuevoTablero[i] = new unsigned char[bytesFila]();

        for (int j = 0; j < nuevaCapacidadColumnas; ++j) {
            int ficha = leerFicha(tablero,i,j,columnas);
            escribirFicha(nuevoTablero,i,j,ficha,nuevaCapacidadColumnas);
        }
    }

    for (int i = 0; i < capacidadFilas; ++i) {
        delete[] tablero[i];
    }

    delete[] tablero;

    tablero = nuevoTablero;
    capacidadFilas = nuevaCapacidadFilas;
    capacidadColumnas = nuevaCapacidadColumnas;

}