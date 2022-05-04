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
#define MAX_CARACTER 51
#define MAX_CHARFLYCODE 10
#define PRICE_MAX 1000000.00
#define PRICE_MIN 1000.00

typedef struct{

	int id;
	char name[MAX_CARACTER];
	char lastName[MAX_CARACTER];
	float price;
	char flycode[MAX_CHARFLYCODE];
	int typePassanger;
	int statusFlight;
	int isEmpty;


}Passenger;

//Esto no va aca
int harcodeo(Passenger* p1,int len);

// ****INICIO CABECERAS DE FUNCION****
int initPassengers(Passenger *list, int len);
int ObtenerIndexLibre(Passenger* p1, int tam);
int findPassengerById(Passenger *list, int len, int id);
int imprimirUnPassenger(Passenger p1);
int printPassengers(Passenger* p1,int tam);
//int eGen_MostrarDadosDeBaja(eGen array[], int TAM);

//*** SORT ****
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
//int eGen_Sort(eGen array[], int TAM, int criterio);

//Funciones que interactuan con el usuario
int pedirDatoUnSoloPassenger(Passenger* p1);

//ABM
/*eGen eGen_CargarDatos(void);
//int eGen_Alta(eGen array[], int TAM);
int eGen_Baja(eGen array[], int TAM);
//eGen eGen_ModificarUno(eGen Gen);
int eGen_Modificacion(eGen array[], int TAM);*/


int cargaDatos(Passenger* p1, int tam);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int removePassenger(Passenger* list, int len, int id);
int editPassenger(Passenger* list, int len, int id);



//**** FIN CABECERAS DE FUNCION****

#endif /* ARRAYPASSENGER_H_ */
