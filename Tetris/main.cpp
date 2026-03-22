#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "pieza.h"

using namespace std;

void imprimirJuego(unsigned char* celdas,
                   int ancho,
                   int alto,
                   int bytesPorFila,
                   unsigned short piezaActual,
                   int filaPieza,
                   int colPieza)
{
    for (int fila = 0; fila < alto; fila++) {
        cout << "|";

        for (int columna = 0; columna < ancho; columna++) {

            int filaInterna = fila - filaPieza;
            int colInterna = columna - colPieza;

            bool ocupaPieza = false;

            if (filaInterna >= 0 && filaInterna < 4 &&
                colInterna >= 0 && colInterna < 4) {

                if (bitPiezaEncendido(piezaActual, filaInterna, colInterna)) {
                    ocupaPieza = true;
                }
            }

            if (ocupaPieza || estaOcupado(celdas, bytesPorFila, fila, columna)) {
                cout << "[]";
            } else {
                cout << ". ";
            }
        }

        cout << "|" << endl;
    }
}

int main()
{
    int ancho, alto;
    int bytesPorFila = 0;
    unsigned char* celdas = 0;

    cout << "Ingrese ancho del tablero (minimo 8 y multiplo de 8): ";
    cin >> ancho;

    while (ancho < 8 || ancho % 8 != 0) {
        cout << "Ancho invalido. Debe ser minimo 8 y multiplo de 8: ";
        cin >> ancho;
    }

    cout << "Ingrese alto del tablero (minimo 8): ";
    cin >> alto;

    while (alto < 8) {
        cout << "Alto invalido. Debe ser minimo 8: ";
        cin >> alto;
    }

    crearTablero(celdas, bytesPorFila, ancho, alto);

    srand(time(0));

    unsigned short piezaActual = generarPiezaAleatoria();

    int filaPieza = 0;
    int colPieza = (ancho - 4) / 2;

    bool gameOver = false;
    char comando;

    if (!piezaCabe(celdas, ancho, alto, bytesPorFila,
                   piezaActual, filaPieza, colPieza)) {
        cout << "GAME OVER" << endl;
        destruirTablero(celdas);
        return 0;
    }

    while (!gameOver) {

        cout << endl;
        imprimirJuego(celdas, ancho, alto, bytesPorFila,
                      piezaActual, filaPieza, colPieza);

        cout << endl;
        cout << "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir" << endl;
        cout << "Ingrese comando: ";
        cin >> comando;

        if (comando == 'Q' || comando == 'q') {
            break;
        }

        if (comando == 'A' || comando == 'a') {

            if (piezaCabe(celdas, ancho, alto, bytesPorFila,
                          piezaActual, filaPieza, colPieza - 1)) {
                colPieza--;
            }
        }
        else if (comando == 'D' || comando == 'd') {

            if (piezaCabe(celdas, ancho, alto, bytesPorFila,
                          piezaActual, filaPieza, colPieza + 1)) {
                colPieza++;
            }
        }
        else if (comando == 'W' || comando == 'w') {

            unsigned short piezaRotada = rotarPieza(piezaActual);

            if (piezaCabe(celdas, ancho, alto, bytesPorFila,
                          piezaRotada, filaPieza, colPieza)) {
                piezaActual = piezaRotada;
            }
        }
        else if (comando == 'S' || comando == 's') {

            if (piezaCabe(celdas, ancho, alto, bytesPorFila,
                          piezaActual, filaPieza + 1, colPieza)) {
                filaPieza++;
            }
            else {
                fijarPieza(celdas, bytesPorFila,
                           piezaActual, filaPieza, colPieza);

                limpiarFilasCompletas(celdas, ancho, alto, bytesPorFila);

                piezaActual = generarPiezaAleatoria();
                filaPieza = 0;
                colPieza = (ancho - 4) / 2;

                if (!piezaCabe(celdas, ancho, alto, bytesPorFila,
                               piezaActual, filaPieza, colPieza)) {
                    cout << endl;
                    imprimirJuego(celdas, ancho, alto, bytesPorFila,
                                  piezaActual, filaPieza, colPieza);
                    cout << endl;
                    cout << "GAME OVER" << endl;
                    gameOver = true;
                }
            }
        }
    }

    destruirTablero(celdas);

    return 0;
}
