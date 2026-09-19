#include <iostream>
#include "tablero.h"
#include "bits.h"
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
         << "\t 6: Salir de la partida" << endl
         << endl << endl;


    bool filaColumnaValidos = false;

    short filas, columnas, capacidadFilas, capacidadColumnas;
    int numFichasEliminadas = 0, numCombinaciones = 0;
    int puntos = 0;

    while (!filaColumnaValidos) {
        cout << "Ingrese la cantidad de filas y columnas iniciales para el juego, separadas por coma (,): ";
        char coma;
        cin >> filas >> coma >> columnas;
        if (coma == ',') filaColumnaValidos = true;
        cout << endl;
    }
    capacidadFilas = filas;
    capacidadColumnas = columnas;

    unsigned char** tablero = crearTablero(filas,columnas);
    mostrarTableroNormal(tablero,filas,columnas);
    mostrarTableroBinario(tablero,filas,columnas);

    int* arr = nullptr;

    arr = procesarCascada(tablero, filas, columnas);
    puntos += arr[2];

    informacion(tablero,arr,filas,columnas,numFichasEliminadas,numCombinaciones,puntos);

    delete[] arr;

    short opcion;

    do {

        cout << endl << "Ingrese una opcion del menu: ";
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

                    numFichasEliminadas += eliminarFicha(tablero,posi,posj,columnas);

                    arr = procesarCascada(tablero, filas, columnas);
                    numCombinaciones += arr[0];
                    puntos += arr[2];

                    informacion(tablero,arr,filas,columnas,numFichasEliminadas, numCombinaciones,puntos);



                    delete[] arr;

                    break;


                case 2:

                    short posEliminarFila;
                    cout << "Ingrese el indice de la fila que quiere eliminar: ";
                    cin >> posEliminarFila;

                    if (posEliminarFila < 0 || posEliminarFila >= filas) {
                        cout << "Posicion invalida" << endl;
                        break;
                    }

                    eliminarFila(tablero,filas,columnas,posEliminarFila);

                    if (redimensionarSiNo(filas,columnas,capacidadFilas,capacidadColumnas)) {
                        redimensionar(tablero,filas,columnas,capacidadFilas,capacidadColumnas);
                    }

                    arr = procesarCascada(tablero,filas,columnas);
                    numCombinaciones += arr[0];
                    puntos += arr[2];

                    informacion(tablero,arr,filas,columnas,numFichasEliminadas,numCombinaciones,puntos);

                    delete[] arr;
                    break;


                case 3:

                    short posEliminarColumna;
                    cout << "Ingrese el indice de la columna que quiere eliminar: ";
                    cin >> posEliminarColumna;

                    if (posEliminarColumna < 0 || posEliminarColumna >= columnas) {
                        cout << "Posicion invalida" << endl;
                        break;
                    }

                    eliminarColumna(tablero,filas,columnas,posEliminarColumna);

                    if (redimensionarSiNo(filas,columnas,capacidadFilas,capacidadColumnas)) {
                        redimensionar(tablero,filas,columnas,capacidadFilas,capacidadColumnas);
                    }

                    arr = procesarCascada(tablero,filas,columnas);
                    numCombinaciones += arr[0];
                    puntos += arr[2];

                    informacion(tablero,arr,filas,columnas,numFichasEliminadas,numCombinaciones,puntos);

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

                    if (redimensionarSiNo(filas,columnas,capacidadFilas,capacidadColumnas)) {
                        redimensionar(tablero,filas,columnas,capacidadFilas,capacidadColumnas);
                    }

                    arr = procesarCascada(tablero,filas,columnas);
                    numCombinaciones += arr[0];
                    puntos += arr[2];

                    informacion(tablero,arr,filas,columnas,numFichasEliminadas,numCombinaciones,puntos);

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

                    if (redimensionarSiNo(filas,columnas,capacidadFilas,capacidadColumnas)) {
                        redimensionar(tablero,filas,columnas,capacidadFilas,capacidadColumnas);
                    }

                    arr = procesarCascada(tablero,filas,columnas);
                    numCombinaciones += arr[0];
                    puntos += arr[2];

                    informacion(tablero,arr,filas,columnas,numFichasEliminadas,numCombinaciones,puntos);

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
