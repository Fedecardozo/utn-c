
#include <stdio.h>
#include <stdlib.h>

#define TAM 2

#include "Passenger.h"

int main(void) {

	setbuf(stdout,NULL);

	Passanger pasajero[TAM];

	cargaDatos(pasajero,TAM);
	imprimirArrayPasajero(pasajero,TAM);


	return EXIT_SUCCESS;
}
