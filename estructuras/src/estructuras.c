/*
1) Definir un tipo de dato que represente un producto.
El producto tiene un nombre, una descripcion y un precio

2) Definir un array de 200 productos, indicar de alguna manera que la
info de cada item no esta cargada.

3) Realizar una funcion que reciba el array, un indice, y le permita al usuario
cargar los datos en el item de la posicion especificada por el indice.

4) Realizar una funcion que reciba el array y un indice e
imprima los datos del item de la posicion especificada por el indice.

5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).
 */

#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#define tam 200

int main(void) {

	setbuf(stdout,NULL);

	Producto productos[tam];
	int indice;

	inicializar(productos,tam);

	utn_getNumero(&indice, "\nIngrese el numero del cliente que quiere cargar: ", "\nError: ", 0, 200, 2);
	cargarDatos(productos,indice);
	utn_getNumero(&indice, "\nIngrese el numero del cliente que quiere ver: ", "\nError: ", 0, 200, 2);
	imprimirIndice(productos, indice);

	indiceVacio(productos, tam, &indice);

	printf("\nEl indice vacio es: %d",indice);
	imprimirArrayProducto(tam, productos);

	return EXIT_SUCCESS;
}
