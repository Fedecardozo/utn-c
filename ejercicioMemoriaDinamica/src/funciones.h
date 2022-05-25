
#ifndef FUNCIONES_H_
#define FUNCIONES_H_


#include <time.h>
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>

int buscarEntero(int* arrayEnteros,int len, int num);
void printNum(int* arrayEnteros,int len);
void numAleatorio(int* arrayEnteros,int len);
int modificarTamanio(int** arrayEnteros,int* len, int sizeNew);
void removeArray();
int agregarEntero(int* arrayEnteros,int len, int indice,int num);
void pushArray();


#endif /* FUNCIONES_H_ */
