#ifndef TABLERO_H
#define TABLERO_H

void crearTablero(unsigned char*& celdas, int& bytesPorFila, int ancho, int alto);
void destruirTablero(unsigned char*& celdas);
bool estaOcupado(unsigned char* celdas,int bytesPorFila,int fila,int columna);
void ocuparCelda(unsigned char* celdas,int bytesPorFila,int fila,int columna);
void limpiarCelda(unsigned char* celdas,int bytesPorFila,int fila,int columna);
void imprimirTablero(unsigned char* celdas,int ancho,int alto,int bytesPorFila);
bool filaLlena(unsigned char* celdas,int bytesPorFila,int fila);
#endif // TABLERO_H
