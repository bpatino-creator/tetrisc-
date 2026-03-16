#ifndef PIEZAS_H
#define PIEZAS_H

void generarPieza(unsigned char pieza[], int &altoPieza);

void centrarPieza(unsigned char pieza[], int altoPieza, int anchoTablero);

void imprimirPieza(unsigned char pieza[], int altoPieza);

void colocarPieza(char** tablero, unsigned char pieza[], int altoPieza);

#endif
