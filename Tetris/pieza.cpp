#include <iostream>
#include "pieza.h"
#include "tablero.h"
using namespace std;

bool bitPiezaEncendido(unsigned short pieza, int filaInterna, int colInterna)
{
    int indice = filaInterna * 4 + colInterna;

    unsigned short mascara = 1 << indice;

    return (pieza & mascara) != 0;
}


unsigned short rotarPieza(unsigned short pieza)
{
    unsigned short rotada = 0;

    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 4; columna++) {

            if (bitPiezaEncendido(pieza, fila, columna)) {

                int filaNueva = columna;
                int colNueva = 2 - fila;

                int nuevoIndice = filaNueva * 4 + colNueva;

                rotada |= (1 << nuevoIndice);
            }
        }
    }

    return rotada;
}
