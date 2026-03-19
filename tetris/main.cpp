#include <iostream>
#include "tablero.h"
#include "piezas.h"

using namespace std;

int main()
{
    int alto;
    int ancho;

    // ==========================
    // VALIDACIÓN DE DATOS
    // ==========================
    cout << "Ingrese alto del tablero: ";
    cin >> alto;

    cout << "Ingrese ancho del tablero (multiplo de 8): ";
    cin >> ancho;

    if (alto < 8 || ancho < 8 || ancho % 8 != 0)
    {
        cout << "Dimensiones invalidas." << endl;
        return 0;
    }

    // ==========================
    // CREAR TABLERO
    // ==========================
    char** tablero;
    crearTablero(tablero, alto, ancho);

    // ==========================
    // CREAR PRIMERA PIEZA
    // ==========================
    unsigned char pieza[4];
    int altoPieza;

    generarPieza(pieza, altoPieza);

    int x = ancho / 2 - 2;
    int y = 0;

    char opcion;

    // ==========================
    // CICLO PRINCIPAL
    // ==========================
    while(true)
    {
        // -------- COPIAMOS PARA MOSTRAR --------
        char** copia;
        crearTablero(copia, alto, ancho);

        for(int i = 0; i < alto; i++)
        {
            for(int j = 0; j < ancho/8; j++)
            {
                copia[i][j] = tablero[i][j];
            }
        }

        // dibujar pieza temporal
        dibujarPieza(copia, pieza, altoPieza, x, y, ancho);

        // mostrar
        imprimirTablero(copia, alto, ancho);

        liberarTablero(copia, alto);

        // -------- ENTRADA --------
        cout << "a: izquierda | d: derecha | s: bajar: ";
        cin >> opcion;

        // -------- MOVIMIENTO --------
        if(opcion == 'a' && puedeMover(tablero, pieza, altoPieza, x, y, -1, ancho, alto))
        {
            x--;
        }

            if(opcion == 'd' && puedeMover(tablero, pieza, altoPieza, x, y, 1, ancho, alto))
        {
            x++;
        }

        if(opcion == 's')
        {
            if(puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
            {
                y++;
            }
        }

        // -------- GRAVEDAD --------
        if(puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
        {
            y++;
        }
        else
        {
            fijarPieza(tablero, pieza, altoPieza, x, y, ancho);

            generarPieza(pieza, altoPieza);
            x = ancho / 2 - 2;
            y = 0;

            // GAME OVER
            if(!puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
            {
                cout << "GAME OVER" << endl;
                break;
            }
        }
    }

    // ==========================
    // LIBERAR MEMORIA
    // ==========================
    liberarTablero(tablero, alto);

    return 0;
}

