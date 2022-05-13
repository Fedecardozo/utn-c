
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM 200

int main(void) {

	setbuf(stdout, NULL);


	Usuario arrayUsuario[TAM];
	eUsuario_Inicializar(arrayUsuario, TAM);
	harcodeoUsuario(arrayUsuario, TAM);

	Producto arrayProducto[TAM];
	eProducto_Inicializar(arrayProducto, TAM);
	harcodeoProducto(arrayProducto, TAM);
	int x= eProducto_Sort(arrayProducto, TAM, 1);
	printf("\n%d\n",x);
	eProducto_MostrarTodos(arrayProducto, TAM);


	if(menu(arrayUsuario, TAM) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
