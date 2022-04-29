#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "operaciones.h"

int main(void) {

	setbuf(stdout,NULL);

	char palabra[20];

	utn_getString(palabra, "\nEscriba Nombre:", "Te equivocaste",sizeof(palabra),2);

	//myGets(palabra, sizeof(palabra));
	printf("\nEscribiste: %s",palabra);

	return 0;


}

