#include "tablero.h"

Tablero::Tablero()
{
    tablero = nullptr;
    ALTO = 0;
    BYTES_POR_FILA = 0;
}

unsigned char** Tablero::crearTablero(int alto, int ancho)
{
    // Validación rápida
    if (alto < 8 || ancho < 8 || ancho % 8 != 0)
        return nullptr;                     // error

    ALTO = alto;
    BYTES_POR_FILA = ancho / 8;             // manejo de bits

    // Reservar el array de punteros (una entrada por fila)
    unsigned char** nuevoTablero = new unsigned char*[ALTO];

    // Para cada fila, reserva los bytes necesarios e inicializa a 0
    for (int i = 0; i < ALTO; i++) {
        nuevoTablero[i] = new unsigned char[BYTES_POR_FILA];
        for (int b = 0; b < BYTES_POR_FILA; b++)
            nuevoTablero[i][b] = 0x00;      // todos los bloques vacíos
    }

    tablero = nuevoTablero;
    return nuevoTablero;
}
