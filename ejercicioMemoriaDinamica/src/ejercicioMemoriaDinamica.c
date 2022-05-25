
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utn.h"

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

int modificarTamanio(int** arrayEnteros,int* len){

	int retorno=-1;

	if(*arrayEnteros != NULL && len != NULL)
	{
		//Realloca el tamanio nuevo
		int* aux = (int*) realloc(*arrayEnteros,sizeof(int)*(*len-1));

		//printf("\nDIreccion aux: %p\n",aux);
		//printNum(aux, *len);
		//printf("\nDIreccion *p: %p",*arrayEnteros);
		//printf("\nDIreccion solo: %p",arrayEnteros);

		if(aux != NULL)
		{
			*len=*len-1;
			//*arrayEnteros = aux;
			retorno =0;

		}
	}

	//printf("\nDIreccion *p: %p\n",*arrayEnteros);

	return retorno;
}

int main(void) {

	setbuf(stdout,NULL);


	/*Realizar una función que reciba como parámetro un array de enteros,su tamaño y un entero.La
	función se encargará de buscar el valor entero y borrará la primera ocurrencia del mismo.El array
	deberá reestructurarse dinámicamente.*/
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

		modificarTamanio(&pVector, &TAM);
		printNum(pVector, TAM);
		printf("\nTAM: %d",TAM);

	}
	else
	{
		puts("ALGO FALLO");
	}



	return EXIT_SUCCESS;
}
