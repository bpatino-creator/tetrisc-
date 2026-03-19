#include <iostream>
#include "tablero.h"

using namespace std;

void crearTablero(char**& tablero, int alto, int ancho)
{
    int bytesPorFila = ancho / 8;

    tablero = new char*[alto];

    for (int i = 0; i < alto; i++)
    {
        tablero[i] = new char[bytesPorFila];

        for (int j = 0; j < bytesPorFila; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

void imprimirTablero(char** tablero, int alto, int ancho)
{
    int bytesPorFila = ancho / 8;

    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < bytesPorFila; j++)
        {
            for (int b = 7; b >= 0; b--)
            {
                if (tablero[i][j] & (1 << b))
                    cout << "#";
                else
                    cout << ".";
            }
        }
        cout << endl;
    }
}

void liberarTablero(char** tablero, int alto)
{
    for(int i = 0; i < alto; i++)
    {
        delete[] tablero[i];
    }

    delete[] tablero;
}
