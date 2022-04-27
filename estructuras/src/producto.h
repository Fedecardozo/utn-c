/*
 * producto.h
 *
 *  Created on: 26 abr. 2022
 *      Author: fedec
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{
	//1) Definir un tipo de dato que represente un producto.
	//El producto tiene un nombre, una descripcion y un precio

	int id;
	char nombre[20];
	char descripcion[200];
	float precio;

	//2) Definir un array de 200 productos, indicar de alguna manera que la
	//info de cada item no esta cargada.

	int isEmpty;


}Producto;

int imprimirArrayProducto(int tam, Producto* pr);
int inicializar(Producto* pr,int tam);
int cargarDatos(Producto* pr,int indice);
int imprimirIndice(Producto* pr,int indice);
int indiceVacio(Producto* pr, int tam,int* indice);

#endif /* PRODUCTO_H_ */
