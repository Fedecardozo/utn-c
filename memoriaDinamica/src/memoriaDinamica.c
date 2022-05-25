
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

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

int main(void) {

	setbuf(stdout,NULL);

	/*int arrayNum[TAM] = {5, 4, 3, 2, 1};

	printNum(arrayNum, TAM);

	buscarEntero(arrayNum, TAM, 3);

	printNum(arrayNum, TAM);*/

	// ************************** MALLOC() **********************
	//Devuelve un Puntero a void(Void*). Que significa que de vuelve una direccion de memoria
	//Que se puede convertir a cualquier dato que yo quiera a traves del casting
	//malloc(int cantidadBytes)recibe la cantidad de bytes a solicitar. Si encuentra devuelve la direccion encontrada
	//Sino devuelve NULL


	//Esto igual a un array
	int* pVector = (int*)malloc(sizeof(int)*TAM);

	//Asigno valor con aritmetica de puntero
	//Posicion 0
	*pVector = 5;
	//Posicion 1
	*(pVector+1) = 4;
	//Posicion 2
	*(pVector+2) = 3;
	//Posicion 3
	*(pVector+3) = 2;
	//Posicion 4
	*(pVector+4) = 1;




	//Imprimo array con aritmetica de puntero
	printNum(pVector, TAM);


	// ********************* CALLOC() **************************
	//Es como malloc(). Nomas que este inicializa cualquier tipo de dato a 0
	//CALLOC(int cantidadBytes,sizeof(xx))recibe la cantidad de bytes a solicitar. Si encuentra devuelve la direccion encontrada
	//Sino devuelve NULL
	//CALLOC(10,sizeof(int)) = MALLOC(sizeof(int)*10)


	//Creo un array con calloc() y se inicializo todos en cero
	int* pVector2 = (int*)calloc(TAM,sizeof(int));

	//Imprimo array con aritmetica de puntero
	printNum(pVector2, TAM);


	// ****************************** REALLOC() ***********************
	//Reasigna memoria a una variable ya existente. Ej un array reserva 30 bytes y yo quiero que ahora
	//tenga 40. Realloc se va encargar de encontrar un lugar libre para 40 bytes
	//Si encuentra devuelve la direccion de memoria(Void*) y sino devuelve NULL
	//Por eso se tiene que guardar en un auxiliar por las dudas que no encuentre
	//Asi no perdemos la referencia
	//int* pVector3 = (int*)realloc(*puntero,40); Realloc(puntero a reallocar y new tamanio)

	int* auxiliar = (int*)realloc(pVector2,TAM+10);

	if(auxiliar != NULL)
	{
		printNum(pVector2, TAM+10);
	}
	else
	{
		puts("No hay memory");
	}

	return EXIT_SUCCESS;
}
