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
    mostrarTableroNormal(tablero, filas, columnas);
    mostrarTableroBinario(tablero,filas,columnas);


    int numCombinaciones = 0, numEliminaciones = 0, numCascadas = 0;

    int* arr = procesarCascada(tablero, filas, columnas);
    mostrarTableroNormal(tablero, filas, columnas);
    mostrarTableroBinario(tablero,filas,columnas);

    numCombinaciones += arr[0];
    numEliminaciones += arr[1];
    numCascadas += arr[2];

    cout << "Combinaciones hasta el momento: " << numCombinaciones << endl;
    cout << "Fichas eliminadas en combinaciones: " << numEliminaciones << endl;
    cout << "Cascadas en este turno: " << arr[2] << endl;


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
                    cout << "Coordenadas fuera de rango." << endl;
                    break;
                }

                eliminarFicha(tablero,posi,posj,columnas);

                int* arr = procesarCascada(tablero, filas, columnas);

                numCombinaciones += arr[0];
                numEliminaciones += arr[1];
                numCascadas += arr[2];

                cout << "Combinaciones hasta el momento: " << numCombinaciones << endl;
                cout << "Fichas eliminadas en combinaciones: " << numEliminaciones << endl;
                cout << "Cascadas en este turno: " << arr[2] << endl;

                mostrarTableroNormal(tablero, filas, columnas);
                mostrarTableroBinario(tablero, filas, columnas);


                delete[] arr;

                break;
            }
        }
        else {
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 6);
    // mostrarTableroNormal(tablero,filas,columnas);
    // mostrarTableroBinario(tablero,filas,columnas);
    // int valor = leerFicha(tablero, 2,2, columnas);
    // cout << valor << endl;
    // int arrNums = procesarCascada(tablero,filas,columnas);
    // mostrarTableroNormal(tablero,filas,columnas);

    return 0;
}
