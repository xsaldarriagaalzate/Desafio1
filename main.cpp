#include <iostream>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"

using namespace std;

int main()
{

    cout << "SWEET CRUSH" << endl;
    cout << "Tome en cuenta los siguientes numeros para dar las instrucciones al programa: " << endl;
    cout << "\t 1: Eliminar ficha" << endl
         << "\t 2: Eliminar fila" << endl
         << "\t 3: Eliminar columna" << endl
         << "\t 4: Agregar fila" << endl
         << "\t 5: Agragr columna" << endl
         << "\t 6: Salir de la partida" << endl;


    bool filaColumnaValidos = false;

    short filas, columnas;
    while (!filaColumnaValidos) {
        cout << "Ingrese la cantidad de filas y columnas iniciales para el juego, separadas por coma (,)" << endl;
        char coma;
        cin >> filas >> coma >> columnas;
        if (coma == ',') filaColumnaValidos = true;
    }


    unsigned char** tablero = crearTablero(filas,columnas);


    int* arr = nullptr;

    arr = procesarCascada(tablero, filas, columnas);

    informacion(tablero,arr,filas,columnas);

    delete[] arr;

    short opcion;

    do {

        cout << "Ingrese una opcion del menu: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 6) {

            switch (opcion) {

                case 1:

                    short posi, posj;
                    char coma;
                    cout << "Ingrese la coordenada separada por coma (,): ";
                    cin >> posi >> coma >> posj;

                    if (posi < 0 || posi >= filas || posj < 0 || posj >= columnas) {
                        cout << "Coordenadas fuera de rango" << endl;
                        break;
                    }

                    eliminarFicha(tablero,posi,posj,columnas);

                    arr = procesarCascada(tablero, filas, columnas);

                    informacion(tablero,arr,filas,columnas);


                    delete[] arr;

                    break;


                case 4:

                    short posAgregarFila;
                    cout << "Ingrese el indice en el que quiere agregar la fila: ";
                    cin >> posAgregarFila;

                    if (posAgregarFila < 0 || posAgregarFila > filas) {
                        cout << "Posicion invalida" << endl;
                        break;
                    }

                    agregarFila(tablero,filas,columnas,posAgregarFila);

                    arr = procesarCascada(tablero,filas,columnas);

                    informacion(tablero,arr,filas,columnas);

                    delete[] arr;
                    break;

                case 5:
                    short posAgregarColumna;
                    cout << "Ingrese el indice en el que quiere agregar la columna: ";
                    cin >> posAgregarColumna;

                    if (posAgregarColumna < 0 || posAgregarColumna > columnas) {
                        cout << "Posicion invalida" << endl;
                        break;
                    }

                    agregarColumna(tablero,filas,columnas,posAgregarColumna);

                    arr = procesarCascada(tablero,filas,columnas);

                    informacion(tablero,arr,filas,columnas);

                    delete[] arr;
                    break;
            }

        }
        else {
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 6);

    return 0;
}
