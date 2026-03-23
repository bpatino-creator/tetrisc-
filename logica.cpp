#include "logica.h"

void eliminarFilas(char** tablero, int alto, int ancho)
{
    int bytesPorFila = ancho / 8;

    for(int i = 0; i < alto; i++)
    {
        bool filaLlena = true;

        // verificar si la fila está llena
        for(int j = 0; j < bytesPorFila; j++)
        {

            if((unsigned char)tablero[i][j] != 0xFF)

            {
                filaLlena = false;
                break;
            }
        }

        // si está llena → eliminar
        if(filaLlena)
        {
            // bajar todo
            for(int k = i; k > 0; k--)
            {
                for(int j = 0; j < bytesPorFila; j++)
                {
                    tablero[k][j] = tablero[k-1][j];
                }
            }

            // limpiar fila 0
            for(int j = 0; j < bytesPorFila; j++)
            {
                tablero[0][j] = 0;
            }

            // volver a revisar esta fila
            i--;
        }
    }
}
