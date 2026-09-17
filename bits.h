#ifndef BITS_H
#define BITS_H

int calcularBytesFila (short columnas);
unsigned char generarFichaAleatoria ();
char obtenerCaracter (unsigned char binario);
const char* obtenerNumero (char caracter);
int leerFicha (unsigned char** tablero, short posi, short posj, short columnas);
char escribirFicha (unsigned char** tablero, short posi, short posj, int valor, short columnas);
bool redimensionarSiNo(short filas, short columnas, short capacidadFilas, short capacidadColumnas);

#endif // BITS_H
