#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
public:
    Tablero();                                 // constructor que ya te generó Qt

    // === AQUÍ VA TU FUNCIÓN ===
    unsigned char** crearTablero(int alto, int ancho);

    // (más adelante pondremos aquí otras funciones y variables privadas)
private:
    unsigned char** tablero;   // aquí guardaremos el tablero una vez creado
    int ALTO;
    int BYTES_POR_FILA;
};

#endif // TABLERO_H
