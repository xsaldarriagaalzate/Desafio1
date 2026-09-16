#ifndef JUEGO_H
#define JUEGO_H

void eliminarFicha (unsigned char** tablero, short posi, short posj, short columnas);
short detectarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);
short eliminarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);
void agregarFila (unsigned char** &tablero, short &filas, short columnas, short posicion);
void agregarColumna (unsigned char** &tablero, short filas, short &columnas, short posicion);
void informacion (unsigned char** tablero,int* &arr, short filas, short columnas);

#endif // JUEGO_H
