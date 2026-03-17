#include "tablero.h"

//  Definición de las variables de dimención
int ANCHO          = 0;
int ALTO           = 0;
int BYTES_POR_FILA = 0;
int TOTAL_BYTES    = 0;

void inicializarDimensiones(int ancho, int alto) {
    ANCHO          = ancho;
    ALTO           = alto;
    BYTES_POR_FILA = ancho / 8;
    TOTAL_BYTES    = alto * BYTES_POR_FILA;
}


unsigned char* crearTablero() {
    return new unsigned char[TOTAL_BYTES](); // Se crea un solo bloque de tamaño TOTAL_BYTES
}

void liberarTablero(unsigned char* t) {
    delete[] t;
}

void copiarTablero(unsigned char* dest, unsigned char* src) {
    for (int i = 0; i < TOTAL_BYTES; i++)
        dest[i] = src[i];
}

void limpiarTablero(unsigned char* t) {
    for (int i = 0; i < TOTAL_BYTES; i++)
        t[i] = 0x00;
}

void imprimirTablero(unsigned char* t, char ocupado, char vacio) {
    for (int y = 0; y < ALTO; y++) {
        for (int x = 0; x < ANCHO; x++) {
            // Calcular índice del byte y posición del bit dentro del byte
            int byteIndex = (y * BYTES_POR_FILA) + (x / 8);
            int bitIndex = 7 - (x % 8);  // MSB primero (bit 7 es el primero de izquierda a derecha)

            // Extraer el bit
            bool activo = (t[byteIndex] >> bitIndex) & 1;
            cout << (activo ? ocupado : vacio);
        }
        cout << endl;
    }
    cout << endl;
}
