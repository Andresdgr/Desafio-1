#include <iostream>
#include "pieza.h"
#include "tablero.h"
using namespace std;

//unsigned short ocupa 16 bits (2 Bytes) nos ayuda a no desperdiciar memoria
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
                int colNueva = 3 - fila;

                int nuevoIndice = filaNueva * 4 + colNueva;
                rotada |= (1 << nuevoIndice);
            }
        }
    }

    return rotada;
}

void imprimirPieza(unsigned short pieza)
{
    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 4; columna++) {
            if (bitPiezaEncendido(pieza, fila, columna)) {
                cout << "[]";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

unsigned short generarPiezaAleatoria()
{
    unsigned short pieza = 0;

    int tipo = rand() % 7;

    switch (tipo) {
    case 0: // T
        pieza |= (1 << 1);
        pieza |= (1 << 4);
        pieza |= (1 << 5);
        pieza |= (1 << 6);
        break;

    case 1: // O
        pieza |= (1 << 0);
        pieza |= (1 << 1);
        pieza |= (1 << 4);
        pieza |= (1 << 5);
        break;

    case 2: // I
        pieza |= (1 << 4);
        pieza |= (1 << 5);
        pieza |= (1 << 6);
        pieza |= (1 << 7);
        break;

    case 3: // L
        pieza |= (1 << 0);
        pieza |= (1 << 4);
        pieza |= (1 << 8);
        pieza |= (1 << 9);
        break;

    case 4: // J
        pieza |= (1 << 1);
        pieza |= (1 << 5);
        pieza |= (1 << 9);
        pieza |= (1 << 8);
        break;

    case 5: // S
        pieza |= (1 << 1);
        pieza |= (1 << 2);
        pieza |= (1 << 4);
        pieza |= (1 << 5);
        break;

    case 6: // Z
        pieza |= (1 << 0);
        pieza |= (1 << 1);
        pieza |= (1 << 5);
        pieza |= (1 << 6);
        break;
    }

    return pieza;
}

void fijarPieza(unsigned char* celdas,int bytesPorFila,unsigned short pieza,int filaPieza,int colPieza)
{
    for (int filaInterna = 0; filaInterna < 4; filaInterna++) {
        for (int colInterna = 0; colInterna < 4; colInterna++) {

            if (bitPiezaEncendido(pieza, filaInterna, colInterna)) {

                int filaReal = filaPieza + filaInterna;
                int colReal = colPieza + colInterna;

                ocuparCelda(celdas, bytesPorFila, filaReal, colReal);
            }
        }
    }
}
