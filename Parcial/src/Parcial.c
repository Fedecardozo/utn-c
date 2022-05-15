
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM_USUARIO 200
#define TAM_PRODUCTO 200
#define TAM_TRACKING 200

int main(void) {

	setbuf(stdout, NULL);

	long int t1add =time_Add(10);
	long int t2Current =time_Current();

	printf("\nt2Current %ld",t2Current);
	printf("\nt1add %ld",t1add);
	int i;

	do{
		puts("\ni: ");
		scanf("%d",&i);
		printf("\nresta %ld",t1add-time_Current());

	}while(i==1);

	Usuario arrayUsuario[TAM_USUARIO];
	eUsuario_Inicializar(arrayUsuario, TAM_USUARIO);

	Producto arrayProducto[TAM_PRODUCTO];
	eProducto_Inicializar(arrayProducto, TAM_PRODUCTO);

	Tracking arrayTracking[TAM_TRACKING];
	eTracking_Inicializar(arrayTracking, TAM_TRACKING);

	harcodeo(arrayProducto, TAM_PRODUCTO, arrayUsuario, TAM_USUARIO);

	//harcodeoTracking(arrayTracking, TAM_TRACKING);


	if(menu(arrayUsuario, TAM_USUARIO,arrayProducto,TAM_PRODUCTO,arrayTracking,TAM_TRACKING) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
