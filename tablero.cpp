#include <iostream>
#include <random>
#include "tablero.h"
#include "bits.h"

using namespace std;

unsigned char** crearTablero (short filas, short columnas) {

    int bytesFila = (columnas * 3 + 7) / 8;  // el 7 obliga a redondear hacia arriba
    unsigned char** tablero = new unsigned char*[filas];
    short numFila = 0;
    short numColumna = 0;
    bool banderaColumna = true;


    for (int i = 0; i < filas; ++i) {
        cout << "    ";
        if (banderaColumna) {
            while (numColumna < columnas) {
                cout << numColumna;
                numColumna++;
            }
            cout << endl;
            banderaColumna = false;
            for (int g = 0; g < (numColumna+4); ++g) {
                cout << "-";
            }
        }
        if (numFila < filas) {
            cout << endl << numFila << " | ";
            numFila++;
            tablero[i] = new unsigned char[bytesFila]();

            for (int j = 0; j < columnas; ++j) {
                tablero[i][j] = obtenerCaracter(generarFichaAleatoria());
                cout << tablero[i][j];
            }



        }

    }

    return tablero;
}