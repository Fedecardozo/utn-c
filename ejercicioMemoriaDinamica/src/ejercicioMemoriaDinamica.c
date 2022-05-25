
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
#include "utn.h"

int buscarEntero(int* arrayEnteros,int len, int num){

	int retorno = 0;
	int i;

	if(arrayEnteros != NULL && len > 0)
	{

		for (i = 0; i < len; ++i)
		{

			if(*(arrayEnteros+i) == num)
			{

				*(arrayEnteros+i)=0;

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

int main(void) {

	setbuf(stdout,NULL);


	/*Realizar una función que reciba como parámetro un array de enteros,su tamaño y un entero.La
	función se encargará de buscar el valor entero y borrará la primera ocurrencia del mismo.El array
	deberá reestructurarse dinámicamente.*/

	int* pVector = (int*)calloc(TAM,sizeof(int));
	int num;

	numAleatorio(pVector,TAM);

	printNum(pVector, TAM);

	utn_getNumero(&num, "\nIngrese num: ", "\nError: ", 0, 100, 2);

	buscarEntero(pVector, TAM, num);

	printNum(pVector, TAM);

	return EXIT_SUCCESS;
}
