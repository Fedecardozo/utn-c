
#include "menu.h"

static int subMenuUsuario(int indice);
static void erroresInicioSesion(int inicio);
static void printTodo(Usuario* list , int len);


static void printTodo(Usuario* list , int len){

	if(eUsuario_MostrarTodos(list, len)==-1)
	{
		printf("\nNo hay datos cargados!");
	}


}

static void erroresInicioSesion(int inicio)
{

	switch(inicio)
	{
		case -3: printf("\nHUBO UN ERROR!\n"); break;
		case -2: printf("\nNO HAY DATOS CARGADOS !\n"); break;
		case 0: printf("\nCorreo o contraseña incorrectos! Intentelo mas tarde");break;
		default: subMenuUsuario(inicio); break;
	}




}

static int subMenuUsuario(int indice){

	int opc;
	int retorno=0;

	printf("\n****************************"
			"\n** 1er EXAMEN LAB I - 1H ***"
			"\n********* USUARIO **********"
			"\n****************************");

	retorno=utn_getNumero(&opc, "\n\n1)COMPRAR "
			"\n2)VENDER "
			"\n3)ESTADO DE COMPRAS"
			"\n4)ESTADO DE VENTAS"
			"INGRESE OPCION: "
			, "\nOPCION INCORRECTA\nIngrese nuevamente: "
			, 1, 4, 2);

	if(retorno == 0)
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
	}else
	{
		printf("\nOpcion inexistente. Intentelo mas tarde...");
	}

	return retorno;
}

static void erroresAlta(int registro)
{

	switch(registro)
	{
		case -1: printf("\nHUBO UN ERROR!\n"); break;
		case -2:printf("\nLISTA LLENA \n");break;
		case 0:printf("\nSE REGISTRO CON EXITO\n");break;
		default:printf("\nHUBO UN ERROR!\n"); break;
	}




}

int menu(Usuario* list , int len){

	int retorno =-1;
	int rta;
	int opc;

	if(list != NULL && len >=0)
	{
		retorno =0;
		do{

			printf("\n****************************"
					"\n** 1er EXAMEN LAB I - 1H ***"
					"\n****************************");
			rta=utn_getNumero(&opc, "\n\n1)INGRESAR \n2)REGISTRARSE \n3)MOSTRAR TODO \n0)SALIR"
					"\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente: ", 0, 3, 2);

		if(rta==0)
		{
			switch(opc)
			{
				case 1:
					printf("\n****************************"
							"\n** 1er EXAMEN LAB I - 1H ***"
							"\n********** LOGIN ***********"
							"\n****************************\n");

					erroresInicioSesion(eUsuario_InicioSesion(list,len));

					break;
				case 2:
					printf("\n****************************"
							"\n** 1er EXAMEN LAB I - 1H ***"
							"\n******* REGISTRARSE ********"
							"\n****************************\n");

					erroresAlta(eUsuario_CargarDatos(list, len));

					break;
				case 3:
					printf("\n****************************"
							"\n** 1er EXAMEN LAB I - 1H ***"
							"\n**** USUARIO Y PRODUCTOS ***"
							"\n****************************\n");

					printTodo(list,len);

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


	}

	return retorno;

}





