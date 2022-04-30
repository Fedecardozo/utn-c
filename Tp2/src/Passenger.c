
#include "Passenger.h"

//Prototypo
static int generadorId();
static int validarDatos(int* p,int tam);


static int generadorId(){

	static int id=0;
	return id++;

}

int imprimirPasajero(Passanger p1){

	int retorno =-1;

	if(p1.isEmpty==1){

		printf("\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
		printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);
		retorno=0;
	}

	return retorno;
}

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

int pedirDatos(Passanger* p){

	Passanger p1;
	int retorno=-1;
	int error[6];

	if(p!=NULL){

		error[0]=utn_getString(p1.name, "\nIngrese nombre:","\nError esta mal escrito" , 51, 2);
		//strncpy(p1.name,name,sizeof(name));

		error[1]=utn_getString(p1.lastName, "\nIngrese apellido:","\nError esta mal escrito" , 51, 2);
		//strncpy(p1.lastName,lastName,sizeof(lastName));

		error[2]=utn_getNumeroFlotante(&p1.price, "\nIngrese precio: ", "\nError ingrese nuevamente: ", 0, 300, 2);
		//p1.price = price;

		printf("\nIngrese codigo: ");
		error[3]=myGets(p1.flycode, 10);
		//strncpy(p1.flycode,flycode,sizeof(flycode));

		error[4]=utn_getNumero(&p1.typePassanger, "\nIngrese tipo:", "\nError ingrese nuevamente:", 0, 3, 2);
		//p1.typePassanger = typePassanger;

		error[5]=utn_getNumero(&p1.statusFlight, "\nIngrese estado: ", "\nError ingrese nuevamente:", 0, 10, 2);
		//p1.statusFlight = statusFlight;

		if(validarDatos(error,sizeof(error)/4) == 0){

			p1.id = generadorId();
			p1.isEmpty=1;
			retorno=0;
			*p=p1;

		}


	}


	return retorno;


}





