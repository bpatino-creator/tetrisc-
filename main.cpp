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
    // Arreglo de hasta 4 filas donde cada byte representa la pieza en bits
    unsigned char pieza[4];

    // Altura real de la pieza (cuántas filas usa de las 4 posibles)
    int altoPieza;

    // Tipo de pieza generada (I, O, T, S, Z,)
    int tipo;

    // Estado de rotación de la pieza (inicia sin rotar)
    int rotacion = 0;

    // funcion que  Genera una pieza aleatoria y define su forma y altura
    generarPieza(pieza, altoPieza, tipo);

    // Se asegura que la rotación inicial sea 0
    rotacion = 0;

    // ==========================
    // POSICIÓN INICIAL DE LA PIEZA
    // ==========================

    // Posición horizontal (centrada en el tablero)
    int x = ancho / 2 - 2;

    // Posición vertical (parte superior del tablero)
    int y = 0;

    //la opcion que va ingresar el usuario mas adelante para saber que hacer con la pieza
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

        // dibujar pieza temporal sobre la copia del tablero
        dibujarPieza(copia, pieza, altoPieza, x, y, ancho);

        // mostrar el tablero como va en cada instante hasta que no se genere una colision
        imprimirTablero(copia, alto, ancho);

        //se libera el espacio en memoria
        liberarTablero(copia, alto);

        // -------- ENTRADA --------
        cout << "a: izquierda | d: derecha | s: bajar:  | r: rotar:  ";
        cin >> opcion;

        // -------- MOVIMIENTO --------
        //puede mover a la izquierda
        if(opcion == 'a' && puedeMover(tablero, pieza, altoPieza, x, y, -1, ancho, alto))
        {
            x--;
        }
        //puede mover a la derecha
        if(opcion == 'd' && puedeMover(tablero, pieza, altoPieza, x, y, 1, ancho, alto))
        {
            x++;
        }
        // verifica que puede bajar la pieza.
        if(opcion == 's')
        {
            if(puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
                y++;
        }
        //rotacion de las piezas
        if(opcion == 'r')
        {
            //aca se hace un arreglo llamado copia y se trabaja en ella para saber si se puede o no rotar.
            unsigned char copia[4];
            int altoCopia = altoPieza;
            int rotacionTemp = rotacion;

            //aca se pasa la pieza original a copia
            for(int i = 0; i < 4; i++)
                copia[i] = pieza[i];

            //aca se rota la copia que se hizo, ya la copia quedo rotada
            rotarPieza(copia, altoCopia, tipo, rotacionTemp);

            //se verifica si la pieza ya rotada puede o no mover
            if(puedeMover(tablero, copia, altoCopia, x, y, 0, ancho, alto))
            {
                //si todo esta bien se pasa la copia a la original
                for(int i = 0; i < 4; i++)
                    pieza[i] = copia[i];

                //y aca se actuaizan ya del todo para guardarlos en el tablero original
                altoPieza = altoCopia;
                rotacion = rotacionTemp;
            }
        }

        // -------- GRAVEDAD --------
        //en cada iteacion que haya baja automaticamente una posisicion si lo puede hacer
        if(puedeBajar(tablero, pieza, altoPieza, x, y, alto, ancho))
        {
            y++;
        }
        //entra a este condicional cuando ya la pieza choco con otra y no puede avanzar o toco el suelo
        else
        {
            //aca se fija en el tablero la pieza y queda actualizado
            fijarPieza(tablero, pieza, altoPieza, x, y, ancho);

            //verifica si hay filas llenas en uno y las acualiza de nuevo es decir las elimina
            eliminarFilas(tablero, alto, ancho);

            // se genera de nuevo la pieza
            generarPieza(pieza, altoPieza, tipo);

            //hace que la nueva pieza aparezca de nuevo en la mitad
            x = ancho / 2 -2;

            //hace que aparezca en la parte superior
            y = 0;


            // FIN DEL JUEGO SE VERIFICAN SI YA SE LLENO EL TABLERO Y NO PUEDEN HABER MAS PIEZAS
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

