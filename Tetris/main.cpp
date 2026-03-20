#include <iostream>
#include "tablero.h"

using namespace std;

int main()
{
    int ancho = 16;
    int alto = 8;
    int bytesPorFila = 0;

    unsigned char* celdas = 0;

    crearTablero(celdas, bytesPorFila, ancho, alto);

    ocuparCelda(celdas, bytesPorFila, 2, 3);
    ocuparCelda(celdas, bytesPorFila, 2, 4);
    ocuparCelda(celdas, bytesPorFila, 3, 10);
    ocuparCelda(celdas, bytesPorFila, 5, 15);
    ocuparCelda(celdas, bytesPorFila, 7, 15);

    cout << "Tablero actual:" << endl;
    imprimirTablero(celdas, ancho, alto, bytesPorFila);

    destruirTablero(celdas);

    return 0;
}
