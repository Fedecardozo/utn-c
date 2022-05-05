#include <stdio.h>
#include <stdlib.h>

#define TAM 200


#include "Arraypassenger.h"
#include "menu.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);

	//char nombre[50];

	/*opcion=utn_getStringMayusculayMinuscula(nombre, "\nA:", "\nE", 50, 2);
	printf("\n%s-----%d",nombre,opcion);*/

	do{

		if(menu(&opcion)==-1){

			printf("\nError al procesar la opcion. Intentelo mas tarde!");
			break;

		}

		menuIngresado(opcion,pasajero,TAM);


	}while(opcion>0 && opcion<6);

	return EXIT_SUCCESS;
}
