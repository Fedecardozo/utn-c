
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);
	int opc;


	/*Realizar una funci�n que reciba como par�metro un array de enteros,su tama�o y un entero.La
	funci�n se encargar� de buscar el valor entero y borrar� la primera ocurrencia del mismo.El array
	deber� reestructurarse din�micamente.*/

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
