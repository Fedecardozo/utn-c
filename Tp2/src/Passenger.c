
#include "Passenger.h"

//Prototypo
static int generadorId();
static int pedirDatos(Passanger* p1,int indice);
static void imprimirPasajero(Passanger p1);

//ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
//número de Id. El resto de los campos se le pedirá al usuario.



static int generadorId(){

	static int id=0;
	return id++;

}

static void imprimirPasajero(Passanger p1){

	printf("\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
	printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);

}

int imprimirArrayPasajero(Passanger* p1,int tam){

	int retorno = 1;
	int i;

	if(p1 != NULL && tam >=0){


		for (i = 0; i < tam; i++) {

			imprimirPasajero(p1[i]);

		}

	}


	return retorno;

}

static int pedirDatos(Passanger* p1, int indice){

	int retorno=-1;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassanger;
	int statusFlight;


	if(p1 != NULL && indice >=0){


		p1[indice].id = generadorId();

		utn_getString(name, "\nIngrese nombre:","\nError esta mal escrito" , 51, 2);
		strncpy(p1[indice].name,name,sizeof(name));

		utn_getString(lastName, "\nIngrese apellido:","\nError esta mal escrito" , 51, 2);
		strncpy(p1[indice].lastName,lastName,sizeof(lastName));

		utn_getNumeroFlotante(&price, "\nIngrese precio: ", "\nError ingrese nuevamente: ", 0, 300, 2);
		p1[indice].price = price;

		printf("\nIngrese codigo: ");
		myGets(flycode, 10);
		strncpy(p1[indice].flycode,flycode,sizeof(flycode));

		utn_getNumero(&typePassanger, "\nIngrese tipo:", "\nError ingrese nuevamente:", 0, 3, 2);
		p1[indice].typePassanger = typePassanger;

		utn_getNumero(&statusFlight, "\nIngrese estado: ", "\nError ingrese nuevamente:", 0, 10, 2);
		p1[indice].statusFlight = statusFlight;

		p1[indice].isEmpty=1;


	}


	return retorno;


}


int cargaDatos(Passanger* p1, int tam){

	int retorno=-1;
	int i;

	if(p1 != NULL && tam>0){


		for (i = 0; i <tam ; i++) {

			pedirDatos(p1, i);


		}


	}

	return retorno;


}


