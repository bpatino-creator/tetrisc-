#include "rotacion.h"

/*
void rotarPieza(unsigned char pieza[], int &altoPieza, int tipo, int &rotacion)
{
    // ==========================
    // PIEZA O → no rota
    // ==========================
    if(tipo == 1) return;

    // ==========================
    // PIEZA I → 2 estados
    // ==========================
    if(tipo == 0)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b00111100;
            altoPieza = 1;
        }
        else
        {
            pieza[0] = 0b00100000;
            pieza[1] = 0b00100000;
            pieza[2] = 0b00100000;
            pieza[3] = 0b00100000;
            altoPieza = 4;
        }
    }

    // ==========================
    // PIEZA T → 4 rotaciones
    // ==========================
    if(tipo == 2)
    {
        rotacion = (rotacion + 1) % 4;

        if(rotacion == 0)
        {
            pieza[0] = 0b00111000;
            pieza[1] = 0b00010000;
            altoPieza = 2;
        }
        else if(rotacion == 1)
        {
            pieza[0] = 0b00100000;
            pieza[1] = 0b00110000;
            pieza[2] = 0b00100000;
            altoPieza = 3;
        }
        else if(rotacion == 2)
        {
            pieza[0] = 0b00010000;
            pieza[1] = 0b00111000;
            altoPieza = 2;
        }
        else if(rotacion == 3)
        {
            pieza[0] = 0b00100000;
            pieza[1] = 0b01100000;
            pieza[2] = 0b00100000;
            altoPieza = 3;
        }
    }

    // ==========================
    // PIEZA S → 2 rotaciones
    // ==========================
    if(tipo == 3)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b00011000;
            pieza[1] = 0b00110000;
            altoPieza = 2;
        }
        else
        {
            pieza[0] = 0b00100000;
            pieza[1] = 0b00110000;
            pieza[2] = 0b00010000;
            altoPieza = 3;
        }
    }

    // ==========================
    // PIEZA Z → 2 rotaciones
    // ==========================
    if(tipo == 4)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b00110000;
            pieza[1] = 0b00011000;
            altoPieza = 2;
        }
        else
        {
            pieza[0] = 0b00010000;
            pieza[1] = 0b00110000;
            pieza[2] = 0b00100000;
            altoPieza = 3;
        }
    }
}*/


void rotarPieza(unsigned char pieza[], int &altoPieza, int tipo, int &rotacion)
{
    // ==========================
    // PIEZA O → no rota
    // ==========================
    if(tipo == 1) return;

    // ==========================
    // PIEZA I → 2 estados
    // ==========================
    if(tipo == 0)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b11110000;
            altoPieza = 1;
        }
        else
        {
            pieza[0] = 0b10000000;
            pieza[1] = 0b10000000;
            pieza[2] = 0b10000000;
            pieza[3] = 0b10000000;
            altoPieza = 4;
        }
    }

    // ==========================
    // PIEZA T → 4 rotaciones
    // ==========================
    if(tipo == 2)
    {
        rotacion = (rotacion + 1) % 4;

        if(rotacion == 0)
        {
            pieza[0] = 0b11100000;
            pieza[1] = 0b01000000;
            altoPieza = 2;
        }
        else if(rotacion == 1)
        {
            pieza[0] = 0b10000000;
            pieza[1] = 0b11000000;
            pieza[2] = 0b10000000;
            altoPieza = 3;
        }
        else if(rotacion == 2)
        {
            pieza[0] = 0b01000000;
            pieza[1] = 0b11100000;
            altoPieza = 2;
        }
        else if(rotacion == 3)
        {
            pieza[0] = 0b01000000;
            pieza[1] = 0b11000000;
            pieza[2] = 0b01000000;
            altoPieza = 3;
        }
    }

    // ==========================
    // PIEZA S → 2 rotaciones
    // ==========================
    if(tipo == 3)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b01100000;
            pieza[1] = 0b11000000;
            altoPieza = 2;
        }
        else
        {
            pieza[0] = 0b10000000;
            pieza[1] = 0b11000000;
            pieza[2] = 0b01000000;
            altoPieza = 3;
        }
    }

    // ==========================
    // PIEZA Z → 2 rotaciones
    // ==========================
    if(tipo == 4)
    {
        rotacion = (rotacion + 1) % 2;

        if(rotacion == 0)
        {
            pieza[0] = 0b11000000;
            pieza[1] = 0b01100000;
            altoPieza = 2;
        }
        else
        {
            pieza[0] = 0b01000000;
            pieza[1] = 0b11000000;
            pieza[2] = 0b10000000;
            altoPieza = 3;
        }
    }
}
