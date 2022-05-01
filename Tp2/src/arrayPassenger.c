
#include "arrayPassenger.h"

//Prototypo
static int generadorId();
static int validarDatos(int* p,int tam);
//static void copiarDatos(Passanger p1,Passanger* p2, int indice);

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=0;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Passenger* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int initPassengers(Passenger *list, int len) {

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=TRUE;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn int imprimirPasajero(Passanger)
/// @param imprimi un pasajero solo
/// @return un 0 si esta bien y un -1 si esta mal
int imprimirPasajero(Passenger p1){

	int retorno =-1;

	if(p1.isEmpty==1){

		printf("\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
		printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);
		retorno=0;
	}

	return retorno;
}

/// @fn int validarDatos(int*, int)
/// @param recibi un tipo passenger
/// @param un la longitud para recorrer el array
/// @return un 0 si esta todo bien o -1 si esta mal
static int validarDatos(int* p,int tam){

	int retorno=0;
	int i;

	for (i = 0; i < tam; i++){

		if(p[i]==-1){

			retorno =-1;
			break;

		}

	}


	return retorno;

}

/// @fn int pedirDatos(Passanger*)
/// @brief
///
/// @pre pide datos para llenar un pasajero y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo passenger
/// @return un 0 si esta todo bien o -1 si esta mal
int pedirDatos(Passenger* p){

	Passenger p1;
	int retorno=-1;
	int error[6];

	if(p!=NULL){

		error[0]=utn_getString(p1.name, "\nIngrese nombre:","\nError esta mal escrito" , 51, 2);

		error[1]=utn_getString(p1.lastName, "\nIngrese apellido:","\nError esta mal escrito" , 51, 2);

		error[2]=utn_getNumeroFlotante(&p1.price, "\nIngrese precio: ", "\nError ingrese nuevamente: ", 0, 300, 2);

		printf("\nIngrese codigo: ");
		error[3]=myGets(p1.flycode, 10);

		error[4]=utn_getNumero(&p1.typePassanger, "\nIngrese tipo:", "\nError ingrese nuevamente:", 0, 3, 2);

		error[5]=utn_getNumero(&p1.statusFlight, "\nIngrese estado: ", "\nError ingrese nuevamente:", 0, 10, 2);

		if(validarDatos(error,sizeof(error)/4) == 0){

			p1.id = generadorId();
			p1.isEmpty=1;
			retorno=0;
			*p=p1;

		}



	}


	return retorno;


}
/*static void copiarDatos(Passanger p1,Passanger* p2, int indice){

	strncpy(p2[indice].name,p1.name,sizeof(p2[indice].name));
	strncpy(p2[indice].lastName,p1.lastName,sizeof(p2[indice].lastName));
	p2[indice].price = p1.price;
	strncpy(p2[indice].flycode,p1.flycode,sizeof(p2[indice].flycode));
	p2[indice].typePassanger = p1.typePassanger;
	p2[indice].statusFlight = p1.statusFlight;
	p2[indice].id = p1.id;
	p2[indice].isEmpty=p1.isEmpty;


}*/

/// @fn int imprimirArrayPasajero(Passanger*, int)
///  imprimi un array de pasajero
/// @param recibi un tipo passenger
/// @param un la longitud para recorrer el array
/// @return un 0 si esta todo bien o -1 si esta mal
int imprimirArrayPasajero(Passenger* p1,int tam){

	int retorno = -1;
	int i;

	if(p1 != NULL && tam >=0){

		retorno=0;

		for (i = 0; i < tam; i++) {

			imprimirPasajero(p1[i]);

		}

	}


	return retorno;

}

/// @fn int cargaDatos(Passenger*, int)
/// @pre valida que las variables de los parametros no esten vacio y tam sea <0
/// @post carga los datos de un array passenger que le pasa el usuario
/// @param recibi un tipo passenger
/// @param un la longitud para recorrer el array
/// @return un 0 si esta todo bien o -1 si esta mal
int cargaDatos(Passenger* p1, int tam){

	int retorno=0;
	int i;
	Passenger pasa;

	if(p1 != NULL && tam>0){


		for (i = 0; i <tam ; i++) {


			if(pedirDatos(&pasa)==-1){

				retorno =-1;
				break;

			}
			p1[i]=pasa;
			//copiarDatos(pasa,p1,i);

		}

	}

	return retorno;


}
