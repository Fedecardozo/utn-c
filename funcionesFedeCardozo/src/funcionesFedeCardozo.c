#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "operaciones.h"

int main(void) {

	setbuf(stdout,NULL);

	float num;
	int num2;
	int uno,dos;

	uno = utn_getNumeroFlotante(&num, "\n1- numero: ", "\n1-ErrorNUm:", 0, 200, 2);
	dos = utn_getNumero(&num2, "\n2- numero: ", "\n2-ErrorNUm:", 0,200 , 2);

	printf("\n1)Error: %d - numero: %f ",uno,num);
	printf("\n2)Error: %d - numero: %d ",dos,num2);

	return 0;


}

