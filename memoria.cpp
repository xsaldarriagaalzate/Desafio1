#include <iostream>
#include "memoria.h"
#include "bits.h"
#include "tablero.h"
#include "juego.h"

int calcularBytesFila (short columnas) {

    int bits = columnas * 3;
    int bytes = (bits + 7) / 8;

    return bytes;

}