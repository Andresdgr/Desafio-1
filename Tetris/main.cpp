#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main()
{
    int ancho = 16;
    int alto = 8;
    int bytesPorFila = 0;
    unsigned char* celdas = 0;

    crearTablero(celdas, bytesPorFila, ancho, alto);

    // Pieza T
    unsigned short pieza = 0;
    pieza |= (1 << (0*4 + 1));  // fila 0, col 1
    pieza |= (1 << (1*4 + 0));  // fila 1, col 0
    pieza |= (1 << (1*4 + 1));  // fila 1, col 1
    pieza |= (1 << (1*4 + 2));  // fila 1, col 2

    int filaInicio = 1;
    int colInicio  = 5;

    for (int fi = 0; fi < 4; fi++) {
        for (int ci = 0; ci < 4; ci++) {
            if (bitPiezaEncendido(pieza, fi, ci)) {
                int filaTablero = filaInicio + fi;
                int colTablero  = colInicio + ci;

                if (filaTablero < alto && colTablero < ancho) {
                    ocuparCelda(celdas, bytesPorFila, filaTablero, colTablero);
                }
            }
        }
    }

    cout << "Tablero con la pieza inicial sin rotar:" << endl;
    imprimirTablero(celdas, ancho, alto, bytesPorFila);

    destruirTablero(celdas);
    crearTablero(celdas, bytesPorFila, ancho, alto);
    unsigned short piezaRotada = rotarPieza(pieza);

    for (int fi = 0; fi < 4; fi++) {
        for (int ci = 0; ci < 4; ci++) {
            if (bitPiezaEncendido(piezaRotada, fi, ci)) {
                int filaTablero = filaInicio + fi;
                int colTablero  = colInicio + ci;

                // Limitante para evitar salir del tablero
                if (filaTablero < alto && colTablero < ancho) {
                    ocuparCelda(celdas, bytesPorFila, filaTablero, colTablero);
                }
            }
        }
    }

    cout << "Tablero con una pieza (rotada):" << endl;
    imprimirTablero(celdas, ancho, alto, bytesPorFila);

    destruirTablero(celdas);
    return 0;
}
