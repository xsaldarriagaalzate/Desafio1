#include <iostream>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"

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