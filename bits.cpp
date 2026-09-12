#include <iostream>
#include <random>
#include "tablero.h"
#include "bits.h"
#include "memoria.h"
#include "juego.h"


using namespace std;

unsigned char generarFichaAleatoria () {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(1, 6);

    return static_cast<unsigned char>(distribucion(gen));

}

char obtenerCaracter (unsigned char binario) {

    switch (binario) {
        case 0: return 'X';
        case 1: return 'O';
        case 2: return '#';
        case 3: return '$';
        case 4: return '%';
        case 5: return '@';
        case 6: return '1';
        case 7: return '{';
        default: return '?';
    }

}

const char* obtenerNumero (char caracter) {

    switch (caracter) {
        case 'X': return "000";
        case 'O': return "001";
        case '#': return "010";
        case '$': return "011";
        case '%': return "100";
        case '@': return "101";
        case '1': return "110";
        case '{': return "111";
        default: return "?";
    }

}

int leerFicha (unsigned char **tablero, short posi, short posj, short columnas) {

    int bitPos = posj * 3;
    int byteIndex = bitPos / 8;
    int bitSobrante = bitPos % 8;

    int bytesFila = calcularBytesFila(columnas);
    unsigned short datos;
    datos = tablero[posi][byteIndex];

    if (byteIndex + 1 < bytesFila) {
        datos |= ((unsigned short)tablero[posi][byteIndex + 1] << 8);
    }

    return (datos >> bitSobrante) & 0x07;

}


char escribirFicha (unsigned char **tablero, short posi, short posj, int valor, short columnas) {

    char caracter;

    int bitPos = posj * 3;
    int byteIndex = bitPos / 8;
    int bitSobrante = bitPos % 8;
    int bytesFila = calcularBytesFila(columnas);

    unsigned short datos = tablero[posi][byteIndex];
    if (byteIndex + 1 < bytesFila) {
        datos |= ((unsigned short)tablero[posi][byteIndex + 1] << 8);
    }

    datos &= ~(0x07 << bitSobrante);

    datos |= ((valor & 0x07) << bitSobrante);

    tablero[posi][byteIndex] = datos & 0xFF;  // 0xFF = 11111111
    if (byteIndex + 1 < bytesFila) {
        tablero[posi][byteIndex + 1] = (datos >> 8) & 0xFF;
    }

    caracter = obtenerCaracter(valor);

    return caracter;

}