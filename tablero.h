#ifndef TABLERO_H
#define TABLERO_H

unsigned char** crearTablero (short filas, short columnas);
void mostrarTableroNormal (unsigned char** tablero, short filas, short columnas);
void mostrarTableroBinario (unsigned char** tablero, short filas, short columnas);
int dimensionesTablero(unsigned char** tablero);

#endif // TABLERO_H
