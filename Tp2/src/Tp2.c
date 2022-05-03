
#include <stdio.h>
#include <stdlib.h>

#define TAM 7


#include "Arraypassenger.h"
#include "menu.h"

int main(void) {

	setbuf(stdout,NULL);

	/*int opcion;
	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);
	harcodeo(pasajero);

	do{

		if(menu(&opcion)==-1){

			printf("\nError al procesar la opcion. Intentelo mas tarde!");
			break;

		}

		menuIngresado(opcion,pasajero,TAM);


	}while(opcion>0 && opcion<6);*/

	char c[20];
			utn_getStringLibre(c,"\nIngrese Letras o numeros: " , "\nError no es numero o letra", sizeof(c), 5);
	printf("\n%s",c);

	return EXIT_SUCCESS;
}
