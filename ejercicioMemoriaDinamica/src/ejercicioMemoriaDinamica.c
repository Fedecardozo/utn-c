
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);
	int opc;


	/*Realizar una función que reciba como parámetro un array de enteros,su tamaño y un entero.La
	función se encargará de buscar el valor entero y borrará la primera ocurrencia del mismo.El array
	deberá reestructurarse dinámicamente.*/

	do{

		if(utn_getNumero(&opc, "\nOPCIONES \n1)REMOVE \n2)PUSH \n3)SALIR"
				"\nIngrese opcion: ", "\nError: ", 0, 3, 2)==-1)
		{
			opc = 3;
		}

		switch(opc)
		{
			case 1:

				removeArray();

				break;
			case 2:

				pushArray();

				break;

			default: puts("HASTA LUEGO!!!"); break;

		}



	}while(opc!=3);




	return EXIT_SUCCESS;
}
