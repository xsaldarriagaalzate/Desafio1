#include <iostream>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"

using namespace std;

void eliminarFicha (unsigned char **tablero, short posi, short posj,short columnas) {

    int bitPos = posj * 3;
    int byteIndex = bitPos / 8;
    int bitSobrante = bitPos % 8;
    int bytesFila = calcularBytesFila(columnas);

    unsigned short datos = tablero[posi][byteIndex];
    if (byteIndex + 1 < bytesFila) {
        datos |= ((unsigned short)tablero[posi][byteIndex + 1] << 8);
    }

    datos &= ~(0x07 << bitSobrante);

    tablero[posi][byteIndex] = datos & 0xFF;  // 0xFF = 11111111
    if (byteIndex + 1 < bytesFila) {
        tablero[posi][byteIndex + 1] = (datos >> 8) & 0xFF;
    }
}


short detectarCombinaciones (unsigned char **tablero, short filas, short columnas, bool* eliminar) {

    // Horizontal

    short contHorizontales = 0;

    for (int i = 0; i < filas; ++i) {

        short inicio = 0;
        short contador = 1;

        for (int j = 0; j < columnas-1;++j) {
            int actual = leerFicha(tablero, i,j, columnas);
            int siguiente = leerFicha(tablero, i, j+1, columnas);

            if (actual != 0 && actual == siguiente) {
                contador++;
                if (contador >= 3) {
                    contHorizontales++;
                    for (int k = inicio; k <= j + 1; k++) {
                        eliminar[i * columnas + k] = true;
                    }
                }
            }
            else {
                contador = 1;
                inicio = j+1;
            }


        }
    }


    // Vertical

    short contVerticales = 0;

    for (int j = 0; j < columnas; ++j) {

        short inicio = 0;
        short contador = 1;

        for (int i = 0; i < filas-1;++i) {
            int actual = leerFicha(tablero, i,j, columnas);
            int siguiente = leerFicha(tablero, i+1, j, columnas);

            if (actual != 0 && actual == siguiente) {
                contador++;
                if (contador >= 3) {
                    contVerticales++;
                    for (int k = inicio; k <= i + 1; k++) {
                        eliminar[k * columnas + j] = true;
                    }
                }
            }
            else {
                contador = 1;
                inicio = i+1;
            }


        }
    }

    return contHorizontales + contVerticales;

}


short eliminarCombinaciones (unsigned char **tablero, short filas, short columnas, bool *eliminar) {

    short eliminadas = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (eliminar[i*columnas+j]) {
                escribirFicha(tablero,i,j,0,columnas);
                eliminadas++;
            }
        }
    }
    return eliminadas;

}


void agregarFila (unsigned char **&tablero, short &filas, short columnas, short posicion) {

    int bytesFila = calcularBytesFila(columnas);

    unsigned char** nuevoTablero = new unsigned char*[filas + 1];

    for (int i = 0; i < posicion; ++i) {
        nuevoTablero[i] = tablero[i];
    }

    for (int i = posicion; i < filas; ++i) {

        nuevoTablero[i+1] = tablero[i];


    }

    nuevoTablero[posicion] = new unsigned char[bytesFila]();

    for (int j = 0; j < columnas; ++j) {
        escribirFicha(nuevoTablero,posicion,j,generarFichaAleatoria(),columnas);
    }

    delete[] tablero;

    tablero = nuevoTablero;
    filas++;
}

void eliminarFila (unsigned char** &tablero, short &filas, short columnas, short posicion) {

    for (int i = 0; i < filas; ++i) {
        if (i == posicion) {
            delete[] tablero[i];
        }
        else {
            if (i < posicion);
            else {
                tablero[i-1] = tablero[i];
            }
        }
    }

    filas--;

}

void agregarColumna (unsigned char** &tablero, short filas, short &columnas, short posicion) {

    short nuevasColumnas = columnas + 1;
    int bytesFila = calcularBytesFila(columnas);

    unsigned char** nuevoTablero = new unsigned char*[filas];

    for (int i = 0; i < filas; ++i) {

        nuevoTablero[i] = new unsigned char[bytesFila];

        for (int j = 0; j < nuevasColumnas; ++j) {

            if (j == posicion) {
                escribirFicha(tablero,i,j,generarFichaAleatoria(),columnas);
            }
            else {
                short columnaVieja;

                if (j < posicion) {
                    columnaVieja = j;
                }
                else {
                    columnaVieja = j - 1;
                }

                int ficha = leerFicha(tablero,i,columnaVieja,columnas);
                escribirFicha(tablero,i,j,ficha,nuevasColumnas);
            }
        }
    }

    for (int i = 0; i < filas; ++i) {
        delete[] tablero[i];
    }

    delete[] tablero;

    tablero = nuevoTablero;
    columnas = nuevasColumnas;
}

void eliminarColumna (unsigned char **&tablero, short filas, short &columnas, short posicion) {

    for (int i = 0; i < filas; ++i) {

        for (int j = posicion; j < columnas-1; ++j) {
            tablero[i][j] = tablero[i][j + 1];
        }

    }

    columnas--;

}


void informacion (unsigned char** tablero, int* &arr, short filas, short columnas, int numEliminaciones) {
    int numCombinaciones = arr[0];
    numEliminaciones += arr[1];
    int numCascadas = arr[2];

    cout << endl;
    cout << "Dimensiones tablero: " << filas << "," << columnas << endl;
    cout << "Combinaciones hasta el momento: " << numCombinaciones << endl;
    cout << "Fichas eliminadas en combinaciones: " << numEliminaciones << endl;
    cout << "Cascadas en este turno: " << numCascadas << endl;
    cout << endl;

    mostrarTableroNormal(tablero, filas, columnas);
    mostrarTableroBinario(tablero,filas,columnas);
}