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

// ========================================
// GENERAR PIEZA ALEATORIA
// ========================================
void generarPieza(unsigned char pieza[], int &altoPieza)
{
    int tipo = pseudoRandom() % 5;

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
// VERIFICAR SI PUEDE BAJAR
// ==========================
bool puedeBajar(char** tablero, unsigned char pieza[], int altoPieza, int x, int y, int alto, int ancho)
{
    if(y + altoPieza >= alto)
        return false;

    int byteIndex = x / 8;
    int bitOffset = x % 8;

    for(int i = 0; i < altoPieza; i++)
    {
        unsigned char fila = pieza[i] >> bitOffset;

        // colisión con lo que ya está en el tablero
        if(tablero[y + i + 1][byteIndex] & fila)
            return false;

        if(bitOffset != 0 && byteIndex + 1 < ancho / 8)
        {
            unsigned char parte2 = pieza[i] << (8 - bitOffset);

            if(tablero[y + i + 1][byteIndex + 1] & parte2)
                return false;
        }
    }

    return true;
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

int anchoPieza(unsigned char pieza[], int altoPieza)
{
    int max = 0;

    for(int i = 0; i < altoPieza; i++)
    {
        int anchoFila = 0;

        for(int b = 7; b >= 0; b--)
        {
            if(pieza[i] & (1 << b))
            {
                anchoFila = 8 - b;
            }
        }

        if(anchoFila > max)
            max = anchoFila;
    }

    return max;
}

bool puedeMover(char** tablero, unsigned char pieza[], int altoPieza,
                int x, int y, int dx, int ancho, int alto)
{
    int nuevoX = x + dx;

    // ==========================
    // VALIDAR BORDE IZQUIERDO
    // ==========================
    if(nuevoX < 0)
        return false;

    // ==========================
    // CALCULAR ANCHO DE LA PIEZA
    // ==========================
    int anchoP = 0;

    for(int i = 0; i < altoPieza; i++)
    {
        for(int b = 7; b >= 0; b--)
        {
            if(pieza[i] & (1 << b))
            {
                int pos = 8 - b;
                if(pos > anchoP)
                    anchoP = pos;
            }
        }
    }

    // ==========================
    // VALIDAR BORDE DERECHO
    // ==========================
    if(nuevoX + anchoP > ancho)
        return false;

    // ==========================
    // VALIDAR COLISIONES
    // ==========================
    int byteIndex = nuevoX / 8;
    int bitOffset = nuevoX % 8;

    for(int i = 0; i < altoPieza; i++)
    {
        // evitar salir del tablero verticalmente
        if(y + i >= alto)
            return false;

        unsigned char fila = pieza[i] >> bitOffset;

        // colisión en el mismo byte
        if(tablero[y + i][byteIndex] & fila)
            return false;

        // colisión en el siguiente byte
        if(bitOffset != 0 && byteIndex + 1 < ancho / 8)
        {
            unsigned char parte2 = pieza[i] << (8 - bitOffset);

            if(tablero[y + i][byteIndex + 1] & parte2)
                return false;
        }
    }

    return true;
}
