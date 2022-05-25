
#include "funciones.h"

int buscarEntero(int* arrayEnteros,int len, int num){

	int retorno = -1;
	int i;

	if(arrayEnteros != NULL && len >= 0)
	{

		for (i = 0; i < len; ++i)
		{

			if(*(arrayEnteros+i) == num)
			{

				*(arrayEnteros+i)=*(arrayEnteros+len-1);
				retorno = i;


			}

		}


	}




	return retorno;

}

void printNum(int* arrayEnteros,int len)
{

	int i;

	if(arrayEnteros != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{

			printf("%d-",*(arrayEnteros+i));

		}

		printf("\n");

	}

}

void numAleatorio(int* arrayEnteros,int len){

	int i;
	int num;

	srand(time(NULL));

	for (i = 0; i < len; i++)
	{

		num = rand()%100;

		*(arrayEnteros+i)=num;

	}

}

int modificarTamanio(int** arrayEnteros,int* len, int sizeNew){

	int retorno=-1;

	if(*arrayEnteros != NULL && len != NULL)
	{
		//Realloca el tamanio nuevo
		int* aux = (int*) realloc(*arrayEnteros,sizeNew);

		//printf("\nDIreccion aux: %p\n",aux);
		//printNum(aux, *len);
		//printf("\nDIreccion *p: %p",*arrayEnteros);
		//printf("\nDIreccion solo: %p",arrayEnteros);

		if(aux != NULL)
		{
			*len=sizeNew/sizeof(int);
			//*arrayEnteros = aux;
			retorno =0;

		}
	}

	//printf("\nDIreccion *p: %p\n",*arrayEnteros);

	return retorno;
}

void removeArray(){

		int TAM= 5;
		int* pVector = (int*)calloc(TAM,sizeof(int));
		int num;
		int indice;

		printf("\nDIreccion 1: %p\n", pVector);

		numAleatorio(pVector,TAM);

		printNum(pVector, TAM);

		if(utn_getNumero(&num, "\nIngrese num: ", "\nError: ", 0, 100, 2)==0)
		{

			indice = buscarEntero(pVector, TAM, num);

		}
		else
		{
			indice=-1;
			puts("MALA SUERTE");
		}


		if(indice>=0)
		{
			//printf("\nNuevo tamanio %d\n",sizeof(int)*(TAM-1));
			modificarTamanio(&pVector, &TAM,sizeof(int)*(TAM-1));
			printNum(pVector, TAM);
			printf("\nTAM: %d",TAM);

		}
		else
		{
			puts("ALGO FALLO");
		}



}


int agregarEntero(int* arrayEnteros,int len, int indice,int num){

	int retorno = -1;
	int i;

	if(arrayEnteros != NULL && len >=0 && indice >=0)
	{

		for (i = len-1; i > indice; i--)
		{
			//1er '*' direccion de memoria del puntero
			//2do sin '*' lo que contiene la direccion de memoria
			//3ero '**' es la direccion de memoria que contiene al puntero que contiene otra direccion de memoria
			arrayEnteros[i] = arrayEnteros[i-1];

		}

		//ES igual a *(arrayEnteros + indice) = num;
		//arrayEnteros[indice] = num;
		*(arrayEnteros + indice) = num;
		retorno=0;

	}




	return retorno;

}

void pushArray(){

	int TAM= 5;
	int* pVector = (int*)calloc(TAM,sizeof(int));
	int num;
	int indice;

	/*Realizar una función que reciba como parámetro un array de enteros,su tamaño,un valor entero y
	un índice.La función se encargará de insertar el valor entero en el índice especificado. El array
	deberá reestructurarse dinámicamente.*/

	printf("\nDIreccion 1: %p\n", pVector);

	numAleatorio(pVector,TAM);

	printNum(pVector, TAM);

	if(utn_getNumero(&num, "\nIngrese numero a insertar: ", "\nError: ", -9999, 9999, 2)==0)
	{

		//AGRANDAR TAMANIO
		if(modificarTamanio(&pVector, &TAM,sizeof(int)*(TAM+1))==0)
		{
			utn_getNumero(&indice, "\nIngrese indice a agregar: ", "\nError: ", 0, TAM-1, 2);
		}

		if(indice>=0 && indice< TAM)
		{
			//AGREGAR NUMERO
			agregarEntero(pVector, TAM, indice, num);
			printNum(pVector, TAM);
			printf("\nTAM: %d",TAM);

		}
		else
		{
			puts("INDICE INCORRECTO");
		}

	}
	else
	{
		indice=-1;
		puts("MALA SUERTE");
	}


}
