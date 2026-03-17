#include <iostream>
using namespace std;

#include "tablero.h"

int main() {
    // 1. Inicializar dimensiones (ej: 16x8)
    inicializarDimensiones(16, 8);

    cout << "Dimensiones: " << ANCHO << "x" << ALTO << endl;
    cout << "Bytes por fila: " << BYTES_POR_FILA << endl;
    cout << "Total bytes: " << TOTAL_BYTES << endl << endl;

    // 2. Crear tablero
    unsigned char* tablero = crearTablero();

    // 3. Dibujar formas de prueba (modificando bits manualmente)
    // Ejemplo: Pieza L
    for (int x = 7; x <= 8; x++) {
        int byteIndex = (3 * BYTES_POR_FILA) + (x / 8);
        int bitIndex = 7 - (x % 8);
        tablero[byteIndex] |= (1 << bitIndex); // OR con máscara para encender bit
    }

    for (int y = 1; y <= 2; y++) {
        int byteIndex = (y * BYTES_POR_FILA) + (7 / 8);
        int bitIndex = 7 - (7 % 8);
        tablero[byteIndex] |= (1 << bitIndex); // OR con máscara para encender bit
    }

    // 4. Mostrar el tablero
    imprimirTablero(tablero, '#', '.');

    // 5. Probar limpiar
    limpiarTablero(tablero);
    cout << "Tablero limpio:" << endl;
    imprimirTablero(tablero);


    // 6. Liberar memoria
    liberarTablero(tablero);

    return 0;
}
