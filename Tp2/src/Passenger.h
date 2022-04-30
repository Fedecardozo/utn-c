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

int pedirDatos(Passanger* p1);
int imprimirPasajero(Passanger p1);

#endif /* PASSENGER_H_ */
