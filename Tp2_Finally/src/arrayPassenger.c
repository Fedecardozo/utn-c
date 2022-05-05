
#include "arrayPassenger.h"

//Prototypo
static int generadorId();
static int queModifcar(int opc,int indice,Passenger*p );
static int opcionesParaModifcar(int* x);

int harcodeo(Passenger* p1,int len){

	int retorno =-1;

		if(p1!=NULL){


			addPassenger(p1, len, generadorId(), "Dario", "Diaz",1500, 1, "aaa111222");
			addPassenger(p1, len, generadorId(), "Esteban", "Estevanez", 5700, 2, "bbbb11112");
			addPassenger(p1, len, generadorId(), "Abel", "Alvarez", 30000, 3, "ccccc22223");
			addPassenger(p1, len, generadorId(), "Bart", "Briasco", 2550.90, 4, "asasd2222");
			addPassenger(p1, len, generadorId(), "Carlos", "Cardozo", 1890, 5, "eljabali2");

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

/// \brief Para indicar que todas las posiciones en el array est�n vac�as,
/// esta funci�n pone la bandera (isEmpty) en VERDADERO en todos
/// posici�nes del array
/// \param list Passenger* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
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
int imprimirUnPassenger(Passenger p1){

	int retorno =-1;

	printf("\n\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
	printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);

	retorno=0;




	return retorno;
}

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

			if(p1[i].isEmpty==OCUPADO){

				imprimirUnPassenger(p1[i]);

			}



		}

	}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un pasajero y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo passenger
/// @return un 0 si esta todo bien o -1 si esta mal
int pedirDatoUnSoloPassenger(Passenger* p){

	Passenger p1;
	int retorno=-1;

	if(p!=NULL){

		if(utn_getStringMayusculayMinuscula(p1.name, "\nIngrese nombre:","\nError esta mal escrito" , MAX_CARACTER, 2)==0
		   && utn_getStringMayusculayMinuscula(p1.lastName, "\nIngrese apellido:","\nError esta mal escrito" , MAX_CARACTER, 2)==0
		   && utn_getNumeroFlotante(&p1.price, "\nIngrese precio: ", "\nError ingrese nuevamente: ", PRICE_MIN, PRICE_MAX, 2)==0
		   && utn_getStringLetrasYnumeros(p1.flycode, "\nIngrese codigo: ", "\nError solo numeros y letras", MAX_CHARFLYCODE, 2)==0
		   && utn_getNumero(&p1.typePassanger, "\nIngrese tipo:", "\nError ingrese nuevamente:", 0, 3, 2)==0
		   && utn_getNumero(&p1.statusFlight, "\nIngrese estado: ", "\nError ingrese nuevamente:", 0, 10, 2)==0)
		{

			p1.id = generadorId();
			p1.isEmpty=OCUPADO;
			retorno=0;
			*p=p1;

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


			if(pedirDatoUnSoloPassenger(&pasa)==-1){

				retorno =-1;
				break;

			}
			p1[i]=pasa;

		}

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param p1 recibe un array tipo Paseenger
/// @param tam es el tamanio del del array
/// @return el indice si esta todo bien 0 o -1 si esta mal o -2 si esta todo lleno
int ObtenerIndexLibre(Passenger* p1, int tam){

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

///\brief agrega en una lista existente de pasajeros los valores recibidos como par�metros
/// en la primera posici�n vac�a
///\param lista de pasajeros*
///\param len int
///\param id int
///\param nombre[] car�cter
///\param apellido[] car�cter
///\param precio flotante
///\param tipoPasajero int
///\param flycode[] car�cter
///\return int Devuelve (-1) si Error [Longitud no v�lida o puntero NULL o sin
///espacio libre] - (0) si est� bien
int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[])
{

	int retorno =-1;
	int i;

	if(list != NULL && len>0 && id>0 && name != NULL
			&& lastName != NULL && price > PRICE_MIN
			&& typePassenger > 0 && flycode != NULL)
	{

		i=ObtenerIndexLibre(list, len);

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

			retorno=0;

		}




	}


	return retorno;
}

/// \brief find a Passenger by Id en devuelve la posici�n del �ndice en el arreglo.
/// \param list Pasajero*
/// \param len int
/// \param id int
///\return Posici�n del �ndice de pasajero de retorno o (-1) si [Longitud o
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
///\lista de par�metros Pasajero*
///\parametro len int
///\id de par�metro int
///\return int Retorna (-1) si Error [longitud inv�lida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si est� bien
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){


			indice=findPassengerById(list, len, id);

			if(indice<0){

				retorno=-1;

			}else if(indice>=0){

				//Preguntar si esta seguro
				list[indice].isEmpty=LIBRE;
				retorno=0;

			}


		}

	return retorno;
}

/// @fn editPassenger
/// @brief modica un dato de pasajero
/// @param recibe un tipo passenger list
/// @param recibe el tamanio del arraylen
/// @param recibe el id que va a buscar
/// @return (-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
int editPassenger(Passenger* list, int len, int id){

	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			retorno=0;
			indice=findPassengerById(list, len, id);

			if(indice<0){

				//ERROR NO ENCONTRO EL ID
				retorno=-2;

			}else if(indice>=0 && list[indice].isEmpty==OCUPADO){

				int opcion;

				if (opcionesParaModifcar(&opcion) == 0)
				{

					if (queModifcar(opcion,indice,list) == 0)
					{
						//SALIO TODOO BIEN
						retorno =0;
					}
					else
					{

						//ERROR INGRESO MAL LOS DATOS
						retorno = -4;

					}

				}
				else
				{
					//ERROR INGRESO MAL LAS OPCIONES
					retorno = -3;
				}

			}


		}

		return retorno;

}

/// @fn opcionesParaModifcar
/// @brief muetras opciones por pantalla
/// @param puntero x para guardar la opcion recibida
/// @return 0 Salio bien o -1 que lo recibe de getnumero
/// sea el caso
static int opcionesParaModifcar(int* x){

	int retorno=0;

	if(x != NULL){

		printf("\nOpciones de lo que desea modificar");
		printf("\n1-Nombre");
		printf("\n2-Apellido");
		printf("\n3-Precio");
		printf("\n4-Tipo de pasajero");
		printf("\n5-Codigo de vuelo");

		retorno =utn_getNumero(x, "\nIngrese opcion: ", "\nError Ingrese nuevamente: ", 1, 5, 2);

	}


	return retorno;


}

/// @fn queModifcar
/// @pre Segun la opcion ingresada por el usuario
/// @post va a mostrar un msj y guardarlo en auxiliar
/// De tipo Passenger
/// @param opc la opcion para el switch
/// @param indice para saber cual hay que modificar
/// @param p el puntero passenger para sobreecribir con
/// el auxiliar
/// @return 0 bien o -1 mal
static int queModifcar(int opc,int indice,Passenger*p ){

	int retorno=-1;
	Passenger aux;
	aux=p[indice];

	if(opc>0){


		switch (opc) {

		case 1:
			//char c[MAX_CARACTER];
			retorno = utn_getStringMayusculayMinuscula(aux.name, "\nIngrese nombre: ","\nError! de nuevo", MAX_CARACTER, 2);

			break;

		case 2:

			retorno = utn_getStringMayusculayMinuscula(aux.lastName, "\nIngrese apellido: ","\nError! de nuevo", MAX_CARACTER, 2);

			break;

		case 3:
			//float x;
			retorno = utn_getNumeroFlotante(&aux.price, "\nIngrese precio: ","\nError! de nuevo",PRICE_MIN, PRICE_MAX, 2);

			break;

		case 4:
			//int r;
			retorno = utn_getNumero(&aux.typePassanger, "\nIngrese tipo de pasajero: ",	"\nError! de nuevo", 0, 20, 2);

			break;

		case 5:
			//char codigo[MAX_CHARFLYCODE];
			retorno = utn_getStringLetrasYnumeros(aux.flycode, "\nIngrese codigo: ", "\nError",MAX_CHARFLYCODE, 2);

			break;

		default:
			retorno = -1;
			break;

		}

		if(retorno==0){

			p[indice]=aux;

		}


	}

	return retorno;
}

/// \brief Ordenar los elementos en el arreglo de pasajeros, el orden de los argumentos
///indicar orden ARRIBA o ABAJO
///\param listaPasajero*
///\param len int
///\param order int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int sortPassengers(Passenger* list, int len, int order){

	int retorno = -1;
	int flagSwap;
	int i;
	Passenger aux;

		if(list != NULL && len >= 0 &&  order >=0){

			switch(order){

			case 0:

				do{
					//DESCENDETE APELLIDOS
					flagSwap=0;
					for (i = 0; i < len-1; i++) {

						//Pregunto list[i] es mayor a list[i+1]
						if(strcmp(list[i].lastName,list[i+1].lastName)==1){

							flagSwap=1;
							aux=list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
							retorno=0;
						}

					}

				//Se ejecuta mientra sea mayor a cero
				}while(flagSwap);

				break;

			case 1:

				do {
				//ASCENDETE APELLIDOS
					flagSwap = 0;
					for (i = 0; i < len - 1; i++) {

						//Pregunto list[i] es mayor a list[i+1]
						if (strcmp(list[i].lastName, list[i + 1].lastName) == -1) {

							flagSwap = 1;
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							retorno=0;

						}

					}

				//Se ejecuta mientra sea mayor a cero
			 }while (flagSwap);

			 break;

			default:retorno=-2; break;

			}


		}

	return retorno;
}
