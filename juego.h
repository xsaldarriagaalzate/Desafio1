#ifndef JUEGO_H
#define JUEGO_H

short eliminarFicha (unsigned char** tablero, short posi, short posj, short columnas);
int* detectarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);
short eliminarCombinaciones (unsigned char** tablero, short filas, short columnas, bool* eliminar);
void agregarFila (unsigned char** &tablero, short &filas, short columnas, short posicion);
void eliminarFila (unsigned char** &tablero, short &filas, short columnas, short posicion);
void agregarColumna (unsigned char** &tablero, short filas, short &columnas, short posicion);
void eliminarColumna (unsigned char** &tablero, short filas, short &columnas, short posicion);
void informacion (unsigned char** tablero,int* &arr, short filas, short columnas, int &numFichasEliminadas, int &numCombinaciones, int puntos);

#endif // JUEGO_H
