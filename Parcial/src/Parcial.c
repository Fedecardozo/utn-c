
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM_USUARIO 200
#define TAM_PRODUCTO 200
#define TAM_TRACKING 200

int main(void) {

	setbuf(stdout, NULL);



	Usuario arrayUsuario[TAM_USUARIO];
	eUsuario_Inicializar(arrayUsuario, TAM_USUARIO);

	Producto arrayProducto[TAM_PRODUCTO];
	eProducto_Inicializar(arrayProducto, TAM_PRODUCTO);

	Tracking arrayTracking[TAM_TRACKING];
	eTracking_Inicializar(arrayTracking, TAM_TRACKING);

	harcodeo(arrayProducto, TAM_PRODUCTO, arrayUsuario, TAM_USUARIO);

	//harcodeoTracking(arrayTracking, TAM_TRACKING,arrayProducto, TAM_PRODUCTO);

	adminHar(arrayUsuario, TAM_USUARIO);

	//eTracking_MostrarTodos(arrayTracking, TAM_TRACKING);

	/*eUsuario_MostrarTodos(arrayUsuario, TAM_USUARIO);
	eUsuario_remove(arrayUsuario, TAM_USUARIO);
	eUsuario_MostrarTodos(arrayUsuario, TAM_USUARIO);*/

	/*eProducto_MostrarTodos(arrayProducto, TAM_PRODUCTO);
	eProducto_remove(arrayProducto, TAM_PRODUCTO);
	eProducto_MostrarTodos(arrayProducto, TAM_PRODUCTO);*/

	//eProducto_PrintOrdenCategoria_Nombre(arrayProducto, TAM_PRODUCTO, 1);

	if(menu(arrayUsuario, TAM_USUARIO,arrayProducto,TAM_PRODUCTO,arrayTracking,TAM_TRACKING) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
