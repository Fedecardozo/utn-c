

#include "menu.h"
/*
int menu(int* x){

	int opc;
	int rta;

	printf("\n\n\t ********* MENU *********");
	printf("\n 1. Alta ");
	printf("\n 2. Modificar ");
	printf("\n 3. Baja ");
	printf("\n 4. Informar ");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");

	rta=utn_getNumero(&opc, "\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente:", 1, 6, 2);
	if(rta==0){

		*x=opc;

	}

	return rta;

}

//***FUNCIONES DEL MENU

static int alta(Passenger* p1,int tam){

	Passenger p;
	int retorno=-1;

	int indice=buscarLugarVacio(p1, tam);

	if(indice>=0 && pedirDatos(&p)==0){

		p1[indice]=p;
		retorno=0;
		/*if(addPassenger(p1, tam, p.id, p.name, p.lastName, p.price, p.typePassanger, p.flycode)==0){

			retorno=0;

		}
		else{

			retorno=-2;

		}*/

/*
	}else if(indice==-2){

		retorno =-2;

	}

	return retorno;

}

static int modificar(Passenger* p1,int tam,int id){

	int retorno=-1;
	char cadena[53];


	if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 1200, 0)==0
			&& myGets(cadena, sizeof(cadena))==0)
	{
		if(editPassenger(p1, tam, id,cadena)==0){

			retorno = 0;

		}else{

			retorno=-2;

		}


	}

	return retorno;

}

static int baja(Passenger* p1,int tam){

	int retorno=-1;
	int id;

	if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 1200, 0)==0)
	{
		if(removePassenger(p1, tam, id)==0){

			retorno = 0;

		}else{

			retorno=-2;

		}


	}


	return retorno;

}
/*
void menuIngresado(int opcion,Passenger* pasa,int tam){



	switch(opcion){


		case 1:
			//ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
			//número de Id. El resto de los campos se le pedirá al usuario.
				switch(alta(pasa,tam)){

				case 0: printf("\nCarga de datos con exito!"); break;
				case -1: printf("\nError! Datos invalidos"); break;
				case -2: printf("\nNo hay mas lugar!"); break;

				}
			break;

		case 2:

				modificar();

			break;

		case 3:

				switch(baja(pasa, tam)){

				case 0: printf("\nEliminado con exito!"); break;
				case -1: printf("\nDato ingresado incorrecto"); break;
				case -2: printf("\nNo Existe tal ID!"); break;

				}
			break;


		case 4: printPassengers(pasa, tam) ;break;

		//case 5: cargaForzada() ; break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}*/
