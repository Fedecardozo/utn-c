
#include <stdio.h>
#include <stdlib.h>

#define TAM 2


#include "Arraypassenger.h"

int main(void) {

	setbuf(stdout,NULL);

	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);
	harcodeo(pasajero);

	int indice=findPassengerById(pasajero, TAM, 1);

	if(indice==-1){

		printf("\n No joya %d",indice);

	}else{

		printf("\njoya %d",indice);

	}


	/*if(addPassenger(pasajero, TAM) ==-1 || imprimirArrayPasajero(pasajero,TAM)==-1){

		printf("\nAlgo salio mal!");

	}*/






	return EXIT_SUCCESS;
}
