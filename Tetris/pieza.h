#ifndef PIEZA_H
#define PIEZA_H

bool bitPiezaEncendido(unsigned short pieza, int filaInterna, int colInterna);

void imprimirPieza(unsigned short pieza);

unsigned short rotarPieza(unsigned short pieza);

unsigned short generarPiezaAleatoria();

bool piezaCabe(unsigned char* celdas,int ancho,int alto,int bytesPorFila,unsigned short pieza, int filaPieza,int colPieza);

void fijarPieza(unsigned char* celdas,int bytesPorFila,unsigned short pieza,int filaPieza,int colPieza);


#endif
