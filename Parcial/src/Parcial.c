
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM_USUARIO 200
#define TAM_PRODUCTO 200

int main(void) {

	setbuf(stdout, NULL);


	Usuario arrayUsuario[TAM_USUARIO];
	eUsuario_Inicializar(arrayUsuario, TAM_USUARIO);

	Producto arrayProducto[TAM_PRODUCTO];
	eProducto_Inicializar(arrayProducto, TAM_PRODUCTO);

	harcodeo(arrayProducto, TAM_PRODUCTO, arrayUsuario, TAM_USUARIO);


	if(menu(arrayUsuario, TAM_USUARIO,arrayProducto,TAM_PRODUCTO) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
