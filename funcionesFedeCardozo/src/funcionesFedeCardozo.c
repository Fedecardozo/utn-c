#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	//int num;
	float num2,num3;


	/*utn_getNumero(&num, "\nIngrese un numero: ", "\nError: ", 0, 220, 5);

	printf("\nNumero: %d",num);*/

	utn_getNumeroFlotante(&num2, "\nNumero: ", "\nError: ", 1, 300, 2);
	utn_getNumeroFlotante(&num3, "\nNumero: ", "\nError: ", 1, 300, 2);


	printf("\num 1:%f num2:%f Suma: %f",num2,num3,num2+num3);

	return 0;


}

