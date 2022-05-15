
#include "menu.h"

static int subMenuUsuario(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking);
static void erroresInicioSesion(int inicio,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking);
static void printTodo(Usuario* listUsuario , int lenUsuario,Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking);
static void estadosVentas(Tracking* listTracking,int lenTracking,Producto* listProducto,int lenProducto,Usuario* listUsuario,int indiceUsuario);
static void errorEstadosCompras(int error);

static void  estadoCompras(Tracking* listTracking,int lenTracking,Usuario* listUsuario,int indiceUsuario)
{
	int opc;

	if(eTracking_MostrarProductosUsuario(listTracking, lenTracking, listUsuario, indiceUsuario))
	{

		if(utn_getNumero(&opc, "\n1)Cambiar estado \n2)Actualizar estado \n0)Salir \nIngrese opcion: ",
				"\nOpcion incorrecta.\nIngrese nuevamente: ", 0, 2, 2)==0)
		{

			if(opc == 1)
			{
				//Despues llamar funcion para contener errores
				errorEstadosCompras(eTracking_ConsultaEstado(listTracking, lenTracking, listUsuario, indiceUsuario));

			}
			if(opc == 2)
			{
				eTracking_MostrarProductosUsuario(listTracking, lenTracking, listUsuario, indiceUsuario);
			}

		}
		else
		{
			puts("Opcion incorrecta!");
		}

	}
	else
	{
		puts("\nNO TIENE PRODUCTOS COMPRADOS");
	}

}


static void errorEstadosCompras(int error){

	switch(error)
	{

		case -1: puts("\nHUBO UN ERROR!"); break;
		case -2: puts("\nID INEXISTENTE!"); break;
		case -3: puts("\nNO EXISTE TAL PRODUCTO!"); break;
		case -4: puts("\nNO HUBO UN MODIFICACION DE ESTADO!"); break;



	}

}


static void estadosVentas(Tracking* listTracking,int lenTracking,Producto* listProducto,int lenProducto,Usuario* listUsuario,int indiceUsuario){

	// HACER QUE INGRESE UNA OPCION 1)LISTADO DE VENTAS FINALIZADO| 2)VER PRODUCTOS EN STOCK
	int opc;

	printf("\n****************************"
			"\n** 1er EXAMEN LAB I - 1H ***"
			"\n***** ESTADO DE VENTAS *****"
			"\n****************************");

	if(utn_getNumero(&opc, "\n1)LISTADO DE VENTAS FINALIZADO \n2)VER PRODUCTOS EN STOCK"
			"\n0)SALIR\nIngrese opcion: ", "\nError! Ingrese nuevamente: ", 0, 2, 2)==0
			&& opc >=1)
	{


		switch(opc)
		{
			case 1:

				if(eTracking_MostrarProductosUsuarioEstado(listTracking, lenTracking, listUsuario, indiceUsuario,2)==0)
					{
						puts("\nNo hay productos ventas entregados");

					}
				if(eTracking_MostrarProductosUsuarioEstado(listTracking, lenTracking, listUsuario, indiceUsuario,3)==0)
					{
						puts("\nNo hay productos ventas cancelados");
					}
				break;

			case 2:

				if(print_ProductosdelUsuario(listProducto, lenProducto, listUsuario, indiceUsuario)<0)
					{
						puts("\nNo hay productos con stock");
					}

				break;


		}

	}
	else
	{

		puts("\nOPCION INVALIDA INTENTELO MAS TARDE");

	}






}

static void printTodo(Usuario* listUsuario , int lenUsuario,Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking){

	if(eUsuario_MostrarTodos(listUsuario, lenUsuario)==-1)
	{
		printf("\nNo hay datos cargados!");
	}
	if(eProducto_MostrarTodos(listProducto,lenProducto)==-1)
	{

		printf("No hay datos cargados de productos");

	}
	if(eTracking_MostrarTodos(listTracking,lenTracking)==-1)
	{

		printf("No hay datos cargados de Tracking");

	}


}

static void erroresInicioSesion(int inicio,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking)
{

	switch(inicio)
	{
		case -3: printf("\nIntentelo mas tarde\n"); break;
		case -2: printf("\nNO HAY DATOS CARGADOS !\n"); break;
		case -1: printf("\nHUBO UN ERROR !\n"); break;
		default: subMenuUsuario(inicio,listUsuario,lenUsuario,listProducto,lenProducto,listTracking,lenTracking); break;
	}




}

static int subMenuUsuario(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking){

	int opc;
	int retorno=0;
	int indiceProducto;
	int cantidad;

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
				case 1: //COMPRAR

					indiceProducto = eProducto_compra(listProducto, lenProducto,&cantidad);
					if(indiceProducto<0)
					{
						printf("\nNO SE COMPRARON PRODUCTOS!\n");

					}
					else
					{

						if(eTracking_CargarDatos(listTracking, lenTracking, listProducto, indiceProducto, listUsuario, indice, cantidad)<0)
						{
							printf("\nError");
						}

					}

					break;
				case 2://VENDER

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
				case 3://ESTADO COMPRAS

					estadoCompras(listTracking, lenTracking, listUsuario, indice);

					break;
				case 4: //ESTADO VENTAS

					// HACER QUE INGRESE UNA OPCION 1)LISTADO DE VENTAS FINALIZADO| 2)VER PRODUCTOS EN STOCK
					estadosVentas(listTracking, lenTracking, listProducto, lenProducto, listUsuario, indice);

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

int menu(Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking){

	int retorno =-1;
	int rta;
	int opc;
	int indice;

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
					indice=eUsuario_InicioSesion(listUsuario,lenUsuario);
					erroresInicioSesion(indice, listUsuario, lenUsuario, listProducto, lenProducto, listTracking, lenTracking);

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

					printTodo(listUsuario,lenUsuario,listProducto,lenProducto,listTracking,lenTracking);

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





