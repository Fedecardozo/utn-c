/*
 * arrayPassenger.h
 *
 *  Created on: 30 abr. 2022
 *      Author: fedec
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn.h"
#define LIBRE 1
#define OCUPADO 0

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

int harcodeo(Passenger* p1);

int buscarLugarVacio(Passenger* p1, int tam);

int initPassengers(Passenger *list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger *list, int len, int id);

int pedirDatos(Passenger* p1);
int imprimirPasajero(Passenger p1);


int cargaDatos(Passenger* p1, int tam);
int printPassengers(Passenger* p1,int tam);
int removePassenger(Passenger* list, int len, int id);
int editPassenger(Passenger* list, int len, int id, int or,char*c);


#endif /* ARRAYPASSENGER_H_ */
