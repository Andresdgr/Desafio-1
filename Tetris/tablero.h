#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
using namespace std;

//  DIMENCIONES GLOBALES
/*
 *  Se declaran como extern porque su definición vive en tablero.cpp.
 *  Se inicializan una sola vez al inicio con inicializarDimensiones().
 *
 *  Por qué variables globales y no parámetros:
 *    Pasar ancho/alto/bytesporFila a cada función generaría
 *    firmas de 5+ argumentos en todos los módulos. Al ser
 *    globales de configuración no cambian durante la partida.
 */
extern int ANCHO;
extern int ALTO;
extern int BYTES_POR_FILA;
extern int TOTAL_BYTES;      // ALTO  × BYTES_POR_FILA


// Inicializar las 4 variables de dimensión
void inicializarDimensiones(int ancho, int alto);

unsigned char* crearTablero();
void           liberarTablero (unsigned char* t);
void           copiarTablero  (unsigned char* dest, unsigned char* src);
void           limpiarTablero (unsigned char* t);

void imprimirTablero(unsigned char* t, char ocupado = '#', char vacio = '.');

#endif
