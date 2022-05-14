
#include "menu.h"

static int subMenuUsuario(Producto* listProducto,int lenProducto,int indice,Usuario *listUsuario);
static void erroresInicioSesion(int inicio, Producto* listProducto,int lenProducto,Usuario *listUsuario);
static void printTodo(Usuario* listUsuario , int lenUsuario,Producto* listProducto,int lenProducto);


static void printTodo(Usuario* listUsuario , int lenUsuario,Producto* listProducto,int lenProducto){

	if(eUsuario_MostrarTodos(listUsuario, lenUsuario)==-1)
	{
		printf("\nNo hay datos cargados!");
	}
	if(eProducto_MostrarTodos(listProducto,lenProducto)==-1)
	{

		printf("No hay datos cargados de productos");

	}


}

static void erroresInicioSesion(int inicio, Producto* listProducto,int lenProducto,Usuario *listUsuario)
{

	switch(inicio)
	{
		case -3: printf("\nIntentelo mas tarde\n"); break;
		case -2: printf("\nNO HAY DATOS CARGADOS !\n"); break;
		case -1: printf("\nHUBO UN ERROR !\n"); break;
		default: subMenuUsuario(listProducto,lenProducto,inicio,listUsuario); break;
	}




}

static int subMenuUsuario(Producto* listProducto,int lenProducto,int indice,Usuario *listUsuario){

	int opc;
	int retorno=0;

	do{

		printf("\n****************************"
				"\n** 1er EXAMEN LAB I - 1H ***"
				"\n********* USUARIO **********"
				"\n****************************");

		retorno=utn_getNumero(&opc, "\n\n1)COMPRAR "
				"\n2)VENDER "
				"\n3)ESTADO DE COMPRAS"
				"\n4)ESTADO DE VENTAS"
				"\n0)SALIR"
				"\nINGRESE OPCION: "
				, "\nOPCION INCORRECTA\nIngrese nuevamente: "
				, 0, 4, 2);

		if(retorno == 0)
		{
			switch(opc)
			{
				case 1: //funcion comprar

					if(eProducto_print_listProductosOrdenados(listProducto, lenProducto)==-2)
					{
						printf("\nNO HAY PRODUCTOS PARA MOSTRAR!\n");

					}

					break;
				case 2:

					if(alta_Producto(listProducto, lenProducto,listUsuario, indice)==0)
					{

						printf("\nCarga exitosa\n");

						if(print_ProductosdelUsuario(listProducto, lenProducto, listUsuario, indice)==-1)
						{
							printf("\nNo tiene productos para vender! ");
						}

					}
					else
					{

						printf("\nNo se puede cagar producto!");

					}
					break;
				case 3:

					break;
				case 4: //funcion estados de ventas



					break;

			}
		}else
		{
			printf("\nOpcion inexistente. Intentelo mas tarde...");
		}

	}while(opc != 0);

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

int menu(Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto){

	int retorno =-1;
	int rta;
	int opc;

	if(listUsuario != NULL && lenUsuario >=0)
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

					erroresInicioSesion(eUsuario_InicioSesion(listUsuario,lenUsuario),listProducto,lenProducto,listUsuario);

					break;
				case 2:
					printf("\n****************************"
							"\n** 1er EXAMEN LAB I - 1H ***"
							"\n******* REGISTRARSE ********"
							"\n****************************\n");

					erroresAlta(eUsuario_CargarDatos(listUsuario, lenUsuario));

					break;
				case 3:
					printf("\n****************************"
							"\n** 1er EXAMEN LAB I - 1H ***"
							"\n**** USUARIO Y PRODUCTOS ***"
							"\n****************************\n");

					printTodo(listUsuario,lenUsuario,listProducto,lenProducto);

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





