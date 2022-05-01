
#include <stdio.h>
#include <stdlib.h>

#define TAM 2


#include "Arraypassenger.h"

int main(void) {

	setbuf(stdout,NULL);

	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);

	printf("%d",pasajero[0].isEmpty);
	printf("%d",pasajero[1].isEmpty);

	if(addPassenger(pasajero, TAM) ==-1 || imprimirArrayPasajero(pasajero,TAM)==-1){

		printf("\nAlgo salio mal!");

	}





	return EXIT_SUCCESS;
}
