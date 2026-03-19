#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "logica.h"
#include "rotacion.h"
#include "moverpieza.h"

using namespace std;

int main()
{
    int alto=0;
    int ancho=0;

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

    int tipo;
    int rotacion = 0;

    generarPieza(pieza, altoPieza, tipo);
    rotacion = 0;

    //generarPieza(pieza, altoPieza);

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
        cout << "a: izquierda | d: derecha | s: bajar:  | r: rotar:  ";
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


        if(opcion == 's') // bajar rápido (pero no instantáneo)
        {
            if(puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
                y++;
        }

        if(opcion == 'r')
        {
            unsigned char copia[4];
            int altoCopia = altoPieza;
            int rotacionTemp = rotacion;

            for(int i = 0; i < 4; i++)
                copia[i] = pieza[i];

            rotarPieza(copia, altoCopia, tipo, rotacionTemp);

            if(puedeMover(tablero, copia, altoCopia, x, y, 0, ancho, alto))
            {
                for(int i = 0; i < 4; i++)
                    pieza[i] = copia[i];

                altoPieza = altoCopia;
                rotacion = rotacionTemp;
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

            eliminarFilas(tablero, alto, ancho);

            generarPieza(pieza, altoPieza, tipo);
            //generarPieza(pieza, altoPieza);
            x = ancho / 2;
            //x = ancho / 2 - 2;
            y = 0;
            //x = (ancho / 2) - 4;
            //y = 0;


            // GAME OVER
            if(!puedeMover(tablero, pieza, altoPieza, x, y, 0, ancho, alto))
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

