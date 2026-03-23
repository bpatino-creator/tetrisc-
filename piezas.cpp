#include "piezas.h"

// ========================================
// GENERADOR PSEUDOALEATORIO
// ========================================
int pseudoRandom()
{
    static int seed = 12345;

    seed = (seed * 1103515245 + 12345) & 0x7fffffff;

    return seed;
}


void generarPieza(unsigned char pieza[], int &altoPieza, int &tipo)
{
    tipo = pseudoRandom() % 5;

    if(tipo == 0) // I
    {
        altoPieza = 1;
        pieza[0] = 0b11110000;
    }

    if(tipo == 1) // O
    {
        altoPieza = 2;
        pieza[0] = 0b11000000;
        pieza[1] = 0b11000000;
    }

    if(tipo == 2) // T
    {
        altoPieza = 2;
        pieza[0] = 0b11100000;
        pieza[1] = 0b01000000;
    }

    if(tipo == 3) // S
    {
        altoPieza = 2;
        pieza[0] = 0b01100000;
        pieza[1] = 0b11000000;
    }

    if(tipo == 4) // Z
    {
        altoPieza = 2;
        pieza[0] = 0b11000000;
        pieza[1] = 0b01100000;
    }
}



// ==========================
// DIBUJAR PIEZA (SIN FIJAR)
// ==========================
void dibujarPieza(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int ancho)
{
    //ya definida en el main cuando se genera el tamaño de la pieza.
    int byteIndex = x / 8;
    int bitOffset = x % 8;

    for(int i = 0; i < altoPieza; i++)
    {
        unsigned char fila = pieza[i] >> bitOffset;

        tablero[y + i][byteIndex] |= fila;

        if(bitOffset != 0 && byteIndex + 1 < ancho / 8)
        {
            tablero[y + i][byteIndex + 1] |= (pieza[i] << (8 - bitOffset));
        }
    }
}


// ==========================
// FIJAR PIEZA EN TABLERO
// ==========================
void fijarPieza(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int ancho)
{
    int byteIndex = x / 8;
    int bitOffset = x % 8;

    for(int i = 0; i < altoPieza; i++)
    {
        unsigned char fila = pieza[i] >> bitOffset;

        tablero[y + i][byteIndex] |= fila;

        if(bitOffset != 0 && byteIndex + 1 < ancho / 8)
        {
            tablero[y + i][byteIndex + 1] |= (pieza[i] << (8 - bitOffset));
        }
    }
}




