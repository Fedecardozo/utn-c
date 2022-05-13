
#include <stdio.h>
#include <stdlib.h>

#include "arrayUsuario.h"

#define TAM 3

int main(void) {

	setbuf(stdout, NULL);

	int rta;
	int opc;

	Usuario arrayUsuario[TAM];
	eUsuario_Inicializar(arrayUsuario, TAM);



		do{

			printf("\n****************************"
					"\n** 1er EXAMEN LAB I - 1H ***"
					"\n****************************");
			rta=utn_getNumero(&opc, "\n\n1)INGRESAR \n2)REGISTRARSE \n0)SALIR"
					"\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente: ", 0, 2, 2);

			if(rta==0)
			{
				switch(opc)
				{
					case 1:

						if(eUsuario_InicioSesion(arrayUsuario,TAM))
						{
							printf("Entro %s",arrayUsuario[0].password);
						}
						else
						{

							printf("No Entro");
							printf("Entro %s",arrayUsuario[0].password);

						}

						break;
					case 2:
						if(eUsuario_CargarDatos(arrayUsuario, TAM)==0)
						{
							printf("Entro\n");
							printf("Entro %s",arrayUsuario[0].correo);
							//eUsuario_MostrarUno(arrayUsuario[0]);
						}
						else
						{
							printf("Entro %s",arrayUsuario[0].password);
						}

						break;
					default: printf("\nGracias. Vuelva prontos!"); break;

				}


			}
			else
			{
				printf("\nOpcion inexistente intentelo mas tarde");
				opc=0;
			}

		}while(opc!=0);


	return EXIT_SUCCESS;
}
