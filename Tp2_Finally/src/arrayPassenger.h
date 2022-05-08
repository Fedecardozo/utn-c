

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
int altaPassenger(Passenger* p1,int tam);
int bajaPassenger(Passenger* p1,int tam);
int modificionPassenger(Passenger* p1,int tam);
/*eGen eGen_CargarDatos(void);
//int eGen_Alta(eGen array[], int TAM);
int eGen_Baja(eGen array[], int TAM);
//eGen eGen_ModificarUno(eGen Gen);

int eGen_Modificacion(eGen array[], int TAM);*/


int cargaDatos(Passenger* p1, int tam);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);
int removePassenger(Passenger* list, int len, int id);
int editPassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
int printSortPassengersByCode(Passenger* list, int len, int order,int estado);
int printSortPassengers(Passenger* list, int len, int order);
int imprimirUnPassengerColumna(Passenger p1);
int promedioPassenger(Passenger* list, int len, float* promedio);
int superanPricePromedio(Passenger* list, int len, float promedio);

//**** FIN CABECERAS DE FUNCION****

#endif /* ARRAYPASSENGER_H_ */
