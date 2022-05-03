
#include "arrayPassenger.h"

/*int addPassenger(Passenger* list, int len, char* name,char*
lastName,float price,int typePassenger, char* flycode)*/

//Prototypo
static int generadorId();
static int validarDatos(int* p,int tam);
//static void copiarDatos(Passenger p1,Passenger* p2, int indice);

int harcodeo(Passenger* p1){

	int retorno =-1;
	int len =5;

		if(p1!=NULL){


			addPassenger(p1, len, generadorId(), "Juan", "Mecanico",220.5, 1, "abs1");
			addPassenger(p1, len, generadorId(), "Fede", "Corsa", 22.01, 2, "ascc2");
			addPassenger(p1, len, generadorId(), "Clari", "Nete", 100, 3, "asd23");
			addPassenger(p1, len, generadorId(), "Chano", "Pai", 150, 4, "hhhas2");
			addPassenger(p1, len, generadorId(), "Super", "Chajam", 189, 5, "eljabali2");

			retorno=0;

		}


	return retorno;


}

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
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

			list[i].isEmpty=LIBRE;

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

	if(p1.isEmpty==OCUPADO){

		printf("\n\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
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
			p1.isEmpty=OCUPADO;
			retorno=0;
			*p=p1;

		}



	}


	return retorno;


}
/*static void copiarDatos(Passenger p1,Passenger* p2, int indice){

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
int printPassengers(Passenger* p1,int tam){

	int retorno = -1;
	int i;

	if(p1 != NULL && tam >=0){

		retorno=0;

		for (i = 0; i < tam ; i++) {


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

/// @fn int buscarLugarVacio(Passenger*, int)
/// @brief
///
/// @pre
/// @post
/// @param p1 recibe un array tipo Paseenger
/// @param tam el tamanio del del array
/// @return el indice si esta todo bien 0 o -1 si esta mal o -2 si esta todo lleno
int buscarLugarVacio(Passenger* p1, int tam){

	int retorno=-1;
	int i;


		if(p1 != NULL && tam>0){


			for (i = 0; i <tam ; i++) {


				if(p1[i].isEmpty==LIBRE){

					retorno =i;
					break;

				}else{

					//Si esta todo lleno
					retorno =-2;

				}

			}

		}

		return retorno;


}

///\brief agrega en una lista existente de pasajeros los valores recibidos como parámetros
/// en la primera posición vacía
///\param lista de pasajeros*
///\param len int
///\param id int
///\param nombre[] carácter
///\param apellido[] carácter
///\param precio flotante
///\param tipoPasajero int
///\param flycode[] carácter
///\return int Devuelve (-1) si Error [Longitud no válida o puntero NULL o sin
///espacio libre] - (0) si está bien
int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[])
{

	int retorno =-1;
	int i;

	if(list != NULL && len>0){

		i=buscarLugarVacio(list, len);

		if(i>=0){

			//id = generadorId();

			list[i].id = id;

			strncpy(list[i].name,name,sizeof(list[i].name));
			strncpy(list[i].lastName,lastName,sizeof(list[i].lastName));
			list[i].price = price;
			strncpy(list[i].flycode,flycode,sizeof(list[i].flycode));
			list[i].typePassanger = typePassenger;
			//Averiguar que hace esto
			list[i].statusFlight = 1;
			list[i].isEmpty=OCUPADO;

		}




	}


	return retorno;
}

/// \brief find a Passenger by Id en devuelve la posición del índice en el arreglo.
/// \param list Pasajero*
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int findPassengerById(Passenger *list, int len, int id) {

	int retorno=-1;
	int i;

		if(list!= NULL && len >0){

			for (i = 0; i < len; i++) {

				if(list[i].id== id){

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// \brief Eliminar un Pasajero por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Pasajero*
///\parametro len int
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si está bien
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			retorno=0;
			indice=findPassengerById(list, len, id);

			if(indice<0){

				retorno=-1;

			}else if(indice>=0){

				list[indice].isEmpty=LIBRE;

			}


		}

	return retorno;
}

static int queModifcar(int opc,int indice,Passenger* list,char*c){

	int retorno=0;

	switch (opc) {

		case 1:

			strncpy(list[indice].name,c,sizeof(list[indice].name));
			break;
		case 2:

			strncpy(list[indice].lastName,c,sizeof(list[indice].lastName));
			break;
		case 3:

			list[indice].price = atof(c);
			break;
		case 4:

			list[indice].typePassanger = atoi(c);

			break;
		case 5:

			strncpy(list[indice].flycode,c,sizeof(list[indice].flycode));

			break;

		default: retorno=-1; break;

	}

	return retorno;
}

int editPassenger(Passenger* list, int len, int id, int or,char*c){

	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0 && or>0 && c !=NULL){

			retorno=0;
			indice=findPassengerById(list, len, id);

			if(indice<0){

				retorno=-1;

			}else if(indice>=0 && list[indice].isEmpty==OCUPADO){

				queModifcar(or, indice, list, c);

			}


		}

		return retorno;

}
