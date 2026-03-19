#ifndef PIEZAS_H
#define PIEZAS_H

// Genera una pieza aleatoria
void generarPieza(unsigned char pieza[], int &altoPieza, int &tipo);


// Dibuja la pieza sobre el tablero (temporal o definitiva)
void dibujarPieza(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int ancho);

// Verifica si la pieza puede bajar
bool puedeBajar(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int alto, int ancho);

// Fija la pieza en el tablero
void fijarPieza(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int ancho);

int anchoPieza(unsigned char pieza[], int altoPieza);



#endif

