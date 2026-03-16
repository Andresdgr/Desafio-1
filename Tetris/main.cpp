#include <iostream>
#include "tablero.h"
using namespace std;


int main()
{
    Tablero juego;

    int ancho, alto;
    cout << "Ancho: ";
    cin >> ancho;
    cout << "Alto: ";
    cin >> alto;

    unsigned char** tablero = juego.crearTablero(alto, ancho);

    if (tablero == nullptr) {
        cout << "Error en dimensiones\n";
        return 1;
    }

    // ... aquí continua el resto del juego
    return 0;
}
