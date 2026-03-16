#include <iostream>
#include "tablero.h"

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

    crearTablero(tablero, alto, ancho);

    cout << endl << "TABLERO: " << endl;

    imprimirTablero(tablero, alto, ancho);

    return 0;
}
