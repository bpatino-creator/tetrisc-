#include <iostream>
#include "tablero.h"
#include "piezas.h"

using namespace std;

int main()
{
    int alto;
    int ancho;

    cout << "Ingrese alto del tablero: ";
    cin >> alto;

    cout << "Ingrese ancho del tablero (multiplo de 8): ";
    cin >> ancho;

    if (alto < 8 || ancho < 8 || ancho % 8 != 0)
    {
        cout << "Dimensiones invalidas." << endl;
        return 0;
    }

    char** tablero;

    // Crear tablero
    crearTablero(tablero, alto, ancho);

    // Crear pieza
    unsigned char pieza[4];
    int altoPieza;

    generarPieza(pieza, altoPieza);

    // Centrar pieza
    centrarPieza(pieza, altoPieza, ancho);

    // Colocar pieza en la parte superior del tablero
    colocarPieza(tablero, pieza, altoPieza);

    cout << endl << "TABLERO:" << endl;

    // Mostrar tablero
    imprimirTablero(tablero, alto, ancho);

    return 0;
}
