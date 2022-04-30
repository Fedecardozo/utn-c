#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "utn.h"

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassanger;
	int statusFlight;
	int isEmpty;


}Passanger;

int cargaDatos(Passanger* p1, int tam);
int imprimirArrayPasajero(Passanger* p1,int tam);

#endif /* PASSENGER_H_ */
