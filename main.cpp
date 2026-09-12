#include <iostream>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"

using namespace std;

int main()
{
    short filas,columnas;
    cout << "Ingrese dimensiones iniciales: " << endl;
    cin >> filas;
    cin >> columnas;
    unsigned char** tablero = crearTablero(filas,columnas);
    mostrarTableroNormal(tablero,filas,columnas);
    mostrarTableroBinario(tablero,filas,columnas);
    int valor = leerFicha(tablero, 2,2, columnas);
    cout << valor << endl;
    procesarCascada(tablero,filas,columnas);
    mostrarTableroNormal(tablero,filas,columnas);

    return 0;
}
