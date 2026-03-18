#include "tablero.h"
#include <iostream>
using namespace std;

void crearTablero(unsigned char*& celdas, int& bytesPorFila, int ancho, int alto) {
    bytesPorFila = ancho / 8;

    int totalBytes = alto * bytesPorFila;

    celdas = new unsigned char[totalBytes];

    for (int i = 0; i < totalBytes; i++) {
        celdas[i] = 0;
    }
}
void destruirTablero(unsigned char*& celdas) {
    if (celdas != 0) {
        delete[] celdas;
            celdas = 0;
    }
}


bool estaOcupado(unsigned char* celdas,int bytesPorFila,int fila,int columna)
{
    int byteEnFila = columna / 8;

    int bitEnByte = columna % 8;

    int indice = fila * bytesPorFila + byteEnFila;

    unsigned char byte = celdas[indice];

    unsigned char mascara = 1 << bitEnByte;

    return (byte & mascara) != 0;
}

void ocuparCelda(unsigned char* celdas,int bytesPorFila,int fila,int columna)
{
    int byteEnFila = columna / 8;

    int bitEnByte = columna % 8;

    int indice = fila * bytesPorFila + byteEnFila;

    unsigned char mascara = 1 << bitEnByte;

    celdas[indice] |= mascara;
}
void limpiarCelda(unsigned char* celdas,int bytesPorFila,int fila,int columna)
{
    int byteEnFila = columna / 8;

    int bitEnByte = columna % 8;

    int indice = fila * bytesPorFila + byteEnFila;

    unsigned char mascara = 1 << bitEnByte;

    celdas[indice] &= ~mascara;
}
void imprimirTablero(unsigned char* celdas,int ancho,int alto,int bytesPorFila){
    for (int fila = 0; fila < alto; fila++) {
        cout << "|";

        for (int columna = 0; columna < ancho; columna++) {
            if (estaOcupado(celdas, bytesPorFila, fila, columna)) {
                cout << "[]";
            } else {
                cout << ". ";
            }
        }

        cout << "|" << endl;
    }
}
