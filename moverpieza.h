#ifndef MOVERPIEZA_H
#define MOVERPIEZA_H


//aca se mieven todas piezas
bool puedeMover(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int dx, int ancho, int alto);

//aca se verifica si puede bajar
bool puedeBajar(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int alto, int ancho);

#endif // MOVERPIEZA_H
