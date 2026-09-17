#ifndef TABLERO_H
#define TABLERO_H

unsigned char** crearTablero (short filas, short columnas);
void mostrarTableroNormal (unsigned char** tablero, short filas, short columnas);
void mostrarTableroBinario (unsigned char** tablero, short filas, short columnas);
short reorganizarTablero (unsigned char** tablero,short filas, short columnas);
int* procesarCascada (unsigned char** tablero, short filas, short columnas);
void redimensionar (unsigned char** &tablero, short filas, short columnas, short &capacidadFilas, short &capacidadColumnas);

#endif // TABLERO_H
