

#include "menu.h"

/// @fn  menu
/// @param x puntero para guardar la opcion ingresada
/// @return 1 bien 0 mal
int menu(int* x){

	int opc;
	int rta;

	printf("\n\n\t ********* MENU *********");
	printf("\n 1. Alta ");
	printf("\n 2. Modificar ");
	printf("\n 3. Baja ");
	printf("\n 4. Informar ");
	printf("\n 5. Alta forzada de datos");
	printf("\n 6. Salir");

	rta=utn_getNumero(&opc, "\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente:", 1, 6, 2);
	if(rta==0){

		*x=opc;

	}

	return rta;

}

//***FUNCIONES DEL MENU


/// @fn alta Forzada
/// @param pasajero para harcodear
/// @param tam longitud array Passenger
/// @return 0 bien -1 mal
static int altaForzada(Passenger* pasajero,int tam){

	int retorno =-1;

	if(harcodeo(pasajero,tam)==0)
	{

		printf("\nCarga con exito!");
		retorno=0;

	}

	return retorno;

}


/// @fn imprimir Promedio
/// @param pasajero
/// @param tam
/// @return 0 bien -1 mal[parametros pasados]
/// -2 no se puede calcular promedio
/// -3 nadie supera el promedio

int static printPromedio(Passenger* pasajero,int tam){

	int retorno=-1;
	float promedio;
	int totalPromedio;
	int superanPromedio;

	//Calculo promedio
	totalPromedio= promedioPassenger(pasajero, tam, &promedio);

	if(pasajero != NULL && tam >0)
	{

		if(totalPromedio>0)
		{
			superanPromedio = superanPricePromedio(pasajero,tam,promedio);

			if(superanPromedio > 0)
			{

				retorno=0;
				printf("\n\n*** 2 ***\n-Total de los pasajes: %d",totalPromedio);
				printf("\n-Promedio de los pasajes: %f",promedio);
				printf("\n-Cantidad que superan el precio promedio: %d",superanPromedio);

			}
			else
			{

				//Nadie supera el promedio!
				retorno=-3;

			}

	    }
		else
		{
			//No se pudo calcular el promedio!
			retorno=-2;

		}

	}

	//-- Parametros mal
	return retorno;


}

/// @fn informar
/// @param pasajero
/// @param tamaño del array
/// @return 0 bien -1 mal[parametros pasados]
/// -2 No se puede imprimir los pasajeros
/// -3 No se puede calcular promedio
/// -4 Error al ordenar e imprimir pasajero
static int informar(Passenger* pasajero,int tam){

	//printPassengers(pasa, tam);

	/*1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
	promedio.
	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’*/

	int retorno=-1;

	if(pasajero != NULL && tam >0){

		printf("\n*** 1 ***\n-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero");
		//Ordeno array
		if(printSortPassengers(pasajero,tam,1)==0)
		{
			if(printPromedio(pasajero, tam)==0)
			{
				printf("\n\n*** 3 ****");
				if(printSortPassengersByCode(pasajero, tam, 1, 1)<0)
				{
					//Error al ordenar e imprimir pasajero
					retorno=-4;

				}

			}
			else
			{

				//No se puede calcular promedio!
				retorno=-3;

			}


		}
		else
		{

			//No se puede imprimir los pasajeros!
			retorno=-2;

		}



	}
	// retorno =-1Hubo un error!
	return retorno;

}

static void erroresAlInformar(int caso){

	switch(caso){

		case -1: printf("\nHubo un error!"); break;
		case -2: printf("\nNo se pudo ordenar alfabeticamente por apellido!"); break;
		case -3: printf("\nNo se puede calcular promedio!"); break;
		case -4: printf("\nNo se puede imprimir los pasajeros ordenados por codigo de vuelo!"); break;
		default: printf("\nHubo un error en el sistema");
	}



}

void menuIngresado(int opcion,Passenger* pasa,int tam){



	switch(opcion){


		case 1:
			//ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
			//número de Id. El resto de los campos se le pedirá al usuario.
				switch(altaPassenger(pasa, tam)){

				case 0: printf("\nCarga de datos con exito!"); break;
				case -1: printf("\nNo se pudo cargar los datos! Los datos ingresados son invalidos"); break;
				case -2: printf("\nNo hay mas lugar!"); break;

				}
			break;

		case 2:
			switch(modificionPassenger(pasa, tam)){

				case 0: printf("\nModificacion de datos con exito!"); break;
				case -1: printf("\nError! Datos invalidos"); break;
				case -2: printf("\nNo se encontro el ID!"); break;
				case -3: printf("\nError opciones invalidas!"); break;
				case -4: printf("\nNo se puede guardar esos datos"); break;

				}

			break;

		case 3:

				switch(bajaPassenger(pasa, tam)){

				case 0: printf("\nEliminado con exito!"); break;
				case -1: printf("\nDato ingresado incorrecto"); break;
				case -2: printf("\nNo Existe tal ID!"); break;

				}
			break;


		case 4:

			erroresAlInformar(informar(pasa, tam));

			break;

		case 5:

			if(altaForzada(pasa,tam)==0){

				erroresAlInformar(informar(pasa,tam));

			}

			 break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}
