
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM 3

int main(void) {

	setbuf(stdout, NULL);


	Usuario arrayUsuario[TAM];
	eUsuario_Inicializar(arrayUsuario, TAM);

	if(menu(arrayUsuario, TAM) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
