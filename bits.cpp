#include <iostream>
#include <random>
#include "bits.h"

using namespace std;

unsigned char generarFichaAleatoria () {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(0, 7);

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
        default: return '0';
    }


}