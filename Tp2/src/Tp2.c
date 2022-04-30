
#include <stdio.h>
#include <stdlib.h>

#define TAM 2
#define TRUE 1
#define FALSE 0

#include "Passenger.h"

int main(void) {

	setbuf(stdout,NULL);

	Passanger pasajero;

	if(pedirDatos(&pasajero)==-1 && imprimirPasajero(pasajero)==-1){

		printf("\nAlgo salio mal puto");

	}





	return EXIT_SUCCESS;
}
