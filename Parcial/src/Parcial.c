
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

						switch(eUsuario_InicioSesion(arrayUsuario,TAM))
						{
							case 0:

								printf("\nCorreo o contraseña incorrectos! Intentelo mas tarde");

								break;
							case 1:
								printf("\n****************************"
										"\n** 1er EXAMEN LAB I - 1H ***"
										"\n********* USUARIO **********"
										"\n****************************");

									rta=utn_getNumero(&opc, "\n\n1)COMPRAR "
											"\n2)VENDER "
											"\n3)ESTADO DE COMPRAS"
											"\n4)ESTADO DE VENTAS"
											"INGRESE OPCION: "
											, "\nOPCION INCORRECTA\nIngrese nuevamente: "
											, 1, 4, 2);

									if(rta == 0)
									{
										switch(opc)
										{
											case 1: //funcion comprar
												break;
											case 2: //funcion vender
												break;
											case 3: //funcion estados de compras
												break;
											case 4: //funcion estados de ventas
												break;
										}
									}

								break;
							case -2: printf("\nNO HAY DATOS CARGADOS !\n"); break;
							case -1:printf("\nHUBO UN ERROR!\n"); break;
						}


						break;
					case 2:

						eUsuario_CargarDatos(arrayUsuario, TAM);

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
