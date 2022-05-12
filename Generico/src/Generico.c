
#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"

#define TAM 2

int main(void) {

	setbuf(stdout,NULL);

	char cuit[20];

	if(utn_getCuit(cuit, "\nIngrese cuit: ", "\nError, de nuevo:", 2,1)==0)
	{
		printf("Entro");
		//printf("\nCuit ingresado: %s",cuit);
		printCuitSeparacion(cuit);

	}
	else
	{

		printf("No entro");

	}


	return EXIT_SUCCESS;
}
