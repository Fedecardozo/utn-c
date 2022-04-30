
#include "arrayPassenger.h"

Passanger pasajeros[TAM];

int imprimirArrayPasajero(Passanger* p1,int tam){

	int retorno = 1;
	int i;

	if(p1 != NULL && tam >=0){


		for (i = 0; i < tam; i++) {

			imprimirPasajero(p1[i]);

		}

	}


	return retorno;

}

int cargaDatos(Passanger* p1, int tam){

	int retorno=-1;
	int i;

	if(p1 != NULL && tam>0){


		for (i = 0; i <tam ; i++) {




		}


	}

	return retorno;


}
