#include <iostream>
#include "tablero.h"

using namespace std;

int main()
{
    short filas,columnas;
    cout << "Ingrese dimensiones iniciales: " << endl;
    cin >> filas;
    cin >> columnas;
    crearTablero(filas,columnas);

    return 0;
}
