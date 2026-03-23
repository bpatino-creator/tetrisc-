#include "moverpieza.h"

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
