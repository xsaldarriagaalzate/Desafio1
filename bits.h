#ifndef BITS_H
#define BITS_H

unsigned char generarFichaAleatoria ();
char obtenerCaracter (unsigned char binario);
const char* obtenerNumero (char caracter);
int leerFicha (unsigned char** tablero, short posi, short posj, short columnas);
char escribirFicha (unsigned char** tablero, short posi, short posj, int valor, short columnas);

#endif // BITS_H
