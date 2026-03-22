#ifndef PIEZA_H
#define PIEZA_H

bool bitPiezaEncendido(unsigned short pieza, int filaInterna, int colInterna);
unsigned short rotarPieza(unsigned short pieza);
void imprimirPieza(unsigned short pieza);
unsigned short generarPiezaAleatoria();
bool bitPiezaEncendido(unsigned short pieza, int filaInterna, int colInterna);
unsigned short rotarPieza(unsigned short pieza);
void fijarPieza(unsigned char* celdas,int bytesPorFila,unsigned short pieza,int filaPieza,int colPieza);




#endif // PIEZA_H
