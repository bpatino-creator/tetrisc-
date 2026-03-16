#include <iostream>
#include "piezas.h"

using namespace std;


// Genera una pieza aleatoria
void generarPieza(unsigned char pieza[], int &altoPieza)
{
    int tipo = rand() % 5;

    if(tipo == 0) // pieza I
    {
        altoPieza = 1;
        pieza[0] = 0b11110000;
    }

    if(tipo == 1) // pieza O
    {
        altoPieza = 2;
        pieza[0] = 0b11000000;
        pieza[1] = 0b11000000;
    }

    if(tipo == 2) // pieza T
    {
        altoPieza = 2;
        pieza[0] = 0b11100000;
        pieza[1] = 0b01000000;
    }

    if(tipo == 3) // pieza S
    {
        altoPieza = 2;
        pieza[0] = 0b01100000;
        pieza[1] = 0b11000000;
    }

    if(tipo == 4) // pieza Z
    {
        altoPieza = 2;
        pieza[0] = 0b11000000;
        pieza[1] = 0b01100000;
    }
}


// Centra la pieza horizontalmente
void centrarPieza(unsigned char pieza[], int altoPieza, int anchoTablero)
{
    int desplazamiento = (anchoTablero / 2) - 2;

    for(int i = 0; i < altoPieza; i++)
    {
        pieza[i] = pieza[i] >> desplazamiento;
    }
}


// Coloca la pieza en la parte superior del tablero
void colocarPieza(char** tablero, unsigned char pieza[], int altoPieza)
{
    for(int i = 0; i < altoPieza; i++)
    {
        tablero[i][0] = tablero[i][0] | pieza[i];
    }
}


// Imprime la pieza (solo para pruebas)
void imprimirPieza(unsigned char pieza[], int altoPieza)
{
    for(int i = 0; i < altoPieza; i++)
    {
        for(int bit = 7; bit >= 0; bit--)
        {
            if(pieza[i] & (1 << bit))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
    }
}
