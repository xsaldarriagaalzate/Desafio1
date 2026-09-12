#ifndef JUEGO_H
#define JUEGO_H

void eliminarFicha (unsigned char** tablero, short posi, short posj, short columnas);
void detectarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);
void eliminarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);

#endif // JUEGO_H
