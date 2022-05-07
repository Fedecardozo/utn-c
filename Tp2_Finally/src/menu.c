

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

//Analizar
static int alta(Passenger* p1,int tam){

	Passenger p;
	int retorno=-1;

	int indice=ObtenerIndexLibre(p1, tam);

	if(indice>=0 && pedirDatoUnSoloPassenger(&p)==0){

		//p1[indice]=p;
		retorno=0;
		if(addPassenger(p1, tam, p.id, p.name, p.lastName, p.price, p.typePassanger, p.flycode,p.statusFlight)==0){

			retorno=0;

		}
		else{

			retorno=-2;

		}


	}else if(indice==-2){

		retorno =-2;

	}

	return retorno;

}

//Analizar
static int modificar(Passenger* p1,int tam){

	int retorno =-1;
	int id;

	//HASTA EL RETORNO ES -1
	if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 0, 1200, 2)==0){

		//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
		retorno=editPassenger(p1,tam,id);

	}



	return retorno;

}

//Analizar
static int baja(Passenger* p1,int tam){

	int retorno=-1;
	int id;

	if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 1200, 2)==0)
	{
		if(removePassenger(p1, tam, id)==0){

			//ESTA OK
			retorno = 0;

		}else{

			//NO EXISTE ID
			retorno=-2;

		}


	}


	return retorno;

}


//Analizar
static int altaForzada(Passenger* pasajero,int tam){

	int retorno =-1;

	if(harcodeo(pasajero,tam)==0){

		printf("\nCarga con exito!");
		retorno=0;

	}

	return retorno;

}


//Analizar
static int pricePromedio(Passenger* list, int len, float promedio){

	int retorno=-1;
	int cont=0;
	int i;

	if (list != NULL && len > 0 && promedio > 0) {


		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == OCUPADO && list[i].price > promedio) {

				cont++;

			}

		}
		if(cont >=0){

			retorno = cont;

		}

	}


		return retorno;

}


//Analizar
static int informar(Passenger* pasajero,int tam){

	//printPassengers(pasa, tam);

	/*1.Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
	2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
	promedio.
	3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�*/

	int retorno=-1;
	float promedio;
	int totalPromedio;
	int superanPromedio;

	if(pasajero != NULL && tam >0){


		if(sortPassengers(pasajero, tam,1)==0){

			printf("\n*** 1 ***\n-Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero");

			if(printPassengers(pasajero, tam)==0){

				totalPromedio= promedioPassenger(pasajero, tam, &promedio);

				if(totalPromedio>0){

					superanPromedio = pricePromedio(pasajero,tam,promedio);

					if(superanPromedio > 0){

						retorno=0;
						printf("\n\n*** 2 ***\n-Total de los pasajes: %d",totalPromedio);
						printf("\n-Promedio de los pasajes: %f",promedio);
						printf("\n-Cantidad que superan el precio promedio: %d",superanPromedio);

					}else{

						//Nadie supera el promedio!
						retorno=-5;

					}

				}
				else{


					//No se puede calcular promedio!
					retorno=-4;

				}


			}else{

				//No se puede imprimir los pasajeros!
				retorno=-3;

			}

		}else{

			//No se pudo ordenar alfabeticamente!
			retorno=-2;

		}
			// retorno =-1Hubo un error!

	}

	printf("\n\n*** 3 ****");
	printf("\n\n %d ", printSortPassengersByCode(pasajero, tam, 0, 1));

	return retorno;

}


void menuIngresado(int opcion,Passenger* pasa,int tam){



	switch(opcion){


		case 1:
			//ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
			//n�mero de Id. El resto de los campos se le pedir� al usuario.
				switch(alta(pasa,tam)){

				case 0: printf("\nCarga de datos con exito!"); break;
				case -1: printf("\nNo se pudo cargar los datos! Los datos ingresados son invalidos"); break;
				case -2: printf("\nNo hay mas lugar!"); break;

				}
			break;

		case 2:
			switch(modificar(pasa, tam)){

				case 0: printf("\nModificacion de datos con exito!"); break;
				case -1: printf("\nError! Datos invalidos"); break;
				case -2: printf("\nNo se encontro el ID!"); break;
				case -3: printf("\nError opciones invalidas!"); break;
				case -4: printf("\nNo se puede guardar esos datos"); break;

				}

			break;

		case 3:

				switch(baja(pasa, tam)){

				case 0: printf("\nEliminado con exito!"); break;
				case -1: printf("\nDato ingresado incorrecto"); break;
				case -2: printf("\nNo Existe tal ID!"); break;

				}
			break;


		case 4:

			switch(informar(pasa, tam)){

			case -1: printf("\nHubo un error!"); break;
			case -2: printf("\nNo se pudo ordenar alfabeticamente!"); break;
			case -3: printf("\nNo se puede imprimir los pasajeros!"); break;
			case -4: printf("\nNo se puede calcular promedio!"); break;
			case -5: printf("\nNadie supera el promedio!"); break;

			}



			break;

		case 5:

			if(altaForzada(pasa,tam)==0){

				informar(pasa,tam);

			}

			 break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}
