/*
 * arrayPassenger.h
 *
 *  Created on: 30 abr. 2022
 *      Author: fedec
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn.h"
#define TRUE 1
#define FALSE 0

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassanger;
	int statusFlight;
	int isEmpty;


}Passenger;

int initPassengers(Passenger *list, int len);
int addPassenger(Passenger* list, int len);

int pedirDatos(Passenger* p1);
int imprimirPasajero(Passenger p1);


int cargaDatos(Passenger* p1, int tam);
int imprimirArrayPasajero(Passenger* p1,int tam);


#endif /* ARRAYPASSENGER_H_ */
