
#include "arrayProducto.h"

static char categorias[4][20]={{"1)Deportes"},{"2)Moda"},{"3)Otro"},{"4)Tecnologia"}};

static int generadorId();
static int eProducto_Vacio(Producto * list, int len);
static int eProducto_remove(Producto* list, int len, int id);
static int opcionesParaModifcar(int opc, Producto* list);
static int queModifcar(int indice,Producto *gen );
static int sort_Categoria(Producto *list, int len, int criterio);
static int eProducto_PrintCompra(Producto* arrayProducto,int len,int indice,int cantidad);
static int eProducto_VacioFk(Producto * list, int len,int fkUsuario);



/// @fn int generadorId()
/// @brief genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Gen* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eProducto_Inicializar(Producto *list, int len){

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=LIBRE;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param list recibe un array tipo Producto
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eProducto_ObtenerIndexLibre(Producto* list, int len){

	int retorno=-1;
	int i;


		if (list != NULL && len > 0)
		{

		for (i = 0; i < len; i++)
		{

			if (list[i].isEmpty == LIBRE)
			{

				retorno = i;
				break;

			} else
			{

				//Si esta todo lleno
				retorno = -2;

			}

		}

	}

		return retorno;


}

/// \brief Producto BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Producto *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eProducto_BuscarPorid(Producto *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].id== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Producto y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Producto
/// @return un 0 si esta todo bien o -1 si esta mal
int eProducto_PediUnDato(Producto * list){

	Producto aux;
	int retorno=-1;

	if(list!=NULL){

		if(utn_getStringLetras(aux.nombreProducto, "\nIngrese nombre producto: ",
				"\nNOMBRE INVALIDO!", MAX_NOMBRE, 2)==0
			&& utn_getNumeroFlotante(&aux.precio,"\nIngrese precio producto: ",
					"\nError precio invalido", 0, 99999999, 2)==0
			&& utn_getNumero(&aux.categoria, "\n** Categorias **"
					"\n1)Deportes"
					"\n2)Moda"
					"\n3)Otro"
					"\n4)Tecnologia"
					"\nIngrese categoria:", "\nOpcion incorrecta\nIngrese nuevamente: ",
					1, 4, 2)==0
			&& utn_getNumero(&aux.stock, "\nIngrese cantidad a vender: ",
					"\nError cantidad invalida\nIngrese nuevamente:", 1, 9999, 2)==0)
		{

			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn int imprime Producto
/// @param imprimi un Producto solo
void eProducto_MostrarUno(Producto list){

	printf("|%-10d|%-25s|%-15f|%-25s|%-10d|\n",
			list.id,list.nombreProducto,
			list.precio,categorias[list.categoria-1],list.stock);

}

/// @fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eProducto_MostrarTodos(Producto *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+----------------------------------------------"
				"-------------------------------------------+\n");
		printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
				" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
		printf("+----------------------------------------------"
						"-------------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO){

				eProducto_MostrarUno(list[i]);
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si hay productos
/// 1 se ordeno
int eProducto_MostrarFk(Producto *list, int len,int fk){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		if(eProducto_VacioFk(list, len, fk))
		{
			retorno=0;
			if(eProducto_Sort(list, len, 1)==0)
			{
				retorno=1;
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");
				printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
						" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");
				for (i = 0; i < len ; i++)
				{

					if(list[i].isEmpty==OCUPADO && list[i].Fk_idUsuario==fk){

						eProducto_MostrarUno(list[i]);
						printf("+----------------------------------------------"
									"-------------------------------------------+\n");;

					}

				}

			}

		}



	}


	return retorno;

}

/// @fn imprime un array de Producto que esten dados de baja
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eProducto_MostrarDadosDeBaja(Producto *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+-----------------------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
				" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");
		  printf("+-------------------------------------------------------------------"
				  "--------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==LIBRE){

				eProducto_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn int eProducto_print_listProductosOrdenados(Producto*, int)
/// @param arrayProducto
/// @param lenProducto
/// @return -2 lista vacia -3 error al ordenar 0 ok
int eProducto_print_listProductosOrdenados(Producto* arrayProducto, int lenProducto){

	int retorno = -1;

	if(arrayProducto != NULL  && lenProducto >0)
	{
		if(eProducto_Vacio(arrayProducto, lenProducto))
		{
			retorno =eProducto_Sort(arrayProducto, lenProducto, 1);

			if(retorno == 0 )
			{

				retorno = eProducto_MostrarTodos(arrayProducto, lenProducto);

			}
		}
		else
		{

			retorno = -2;

		}


	}

	return retorno;


}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eProducto_Vacio(Producto * list, int len){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eProducto_VacioFk(Producto * list, int len,int fkUsuario){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO && list[i].Fk_idUsuario==fkUsuario)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}


static int eProducto_PrintCompra(Producto* arrayProducto,int len,int indice,int cantidad)
{
	int retorno = -1;
	float total;

	if(arrayProducto != NULL && len >=0 && indice >= 0 && cantidad >=1)
	{
		retorno=0;
		total = arrayProducto[indice].precio * cantidad;

		printf("\n+---------------------------------------------------------------+\n");
		printf("|%-20s|%-10s|%-15s|%-15s|","PRODUCTO","CANTIDAD","PRECIO","TOTAL");
		printf("\n+---------------------------------------------------------------+\n");
		printf("|%-20s|%-10d|%-15f|%-15f|",arrayProducto[indice].nombreProducto,cantidad,
				arrayProducto[indice].precio,total);
		printf("\n+---------------------------------------------------------------+\n");

	}


	return retorno;

}

//SORT

///\brief Ordenar los elementos en el arreglo de Producto
/// Indicar orden ARRIBA o ABAJO
///\param lista Producto *
///\param len int
///\param criterio int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// (-2)Esta vacio (-3)Error al ordenar
int eProducto_Sort(Producto *list, int len, int criterio){

	int retorno = -1;

		if(list != NULL && len >= 0 &&  criterio>=0 && criterio<=1 )
		{
			if(eProducto_Vacio(list, len))
			{

				if(sort_Categoria(list,len,criterio)>=0)//sort>=0)
				{

					retorno=0;


				}
				else
				{
					//Error al ordenar
					retorno=-3;

				}

			}
			else
			{
				//ARREGLO VACIO
				retorno=-2;
			}

		}

		//Retorno =-1 error en los parametros
	return retorno;
}

/// @fn sort_x
/// @param list puntero de Producto
/// @param len longitud del array de  Producto
/// @param criterio orden 1 arriba - 0 abajo
/// @return 0 bien 1 se ordeno -1[parametros nullos o menor a 0]
static int sort_Categoria(Producto *list, int len, int criterio){

	int i;
	Producto aux;
	//Producto copia[len];
	int flagSwap=0;
	int newLimite=len-1;
	int retorno=-1;

	if(list != NULL && len>0 && criterio>=0 && criterio<=1)
	{
		retorno=0;
		//*copia=*list;
		do{

			flagSwap=0;

			for (i = 0; i < newLimite; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					//Segun lo que quiera ordenar
					if(ordenEnteros(list[i].categoria , list[i+1].categoria, criterio)>0)
					{
						aux= list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
						retorno=1;
						flagSwap=1;

					}

				 }


			 }
			newLimite--;

		}while(flagSwap);

		//*list=*copia;

	}

	return retorno;

}


//ABM

/// @fn int eProducto_compra(Producto*, int)
/// @param arrayProducto
/// @param lenProducto
/// @return -1 datos nullos -2 lista vacia
/// -3 error al ordenar -4 id inexistente
/// -5 cantidad invalida -6 Si o no incorrecto 0 ok
int eProducto_compra(Producto* arrayProducto, int lenProducto,int* cantidad){

	int retorno = -1;
	int idProducto;
	int indice;
	int cantidadAux;

	if(arrayProducto != NULL  && lenProducto >0)
	{

		retorno = eProducto_print_listProductosOrdenados(arrayProducto, lenProducto);
		if(retorno == 0)
		{
			if(utn_getNumero(&idProducto, "\nIngrese ID a comprar: ", "\nError ID incorrecto.\nIngrese nuevamente: "
					, 1000, 9999, 2)==0)
			{
				indice = eProducto_BuscarPorid(arrayProducto, lenProducto, idProducto);
				if(indice >= 0)
				{
					if(utn_getNumero(&cantidadAux, "\nIngrese cantidad a comprar:",
							"\nError cantidad invalida.\nIngrese nuevamente: ",
							1, arrayProducto[indice].stock, 2)==0)
					{

						if(eProducto_PrintCompra(arrayProducto, lenProducto, indice, cantidadAux)==0
								&& preguntarSoN("\n¿Estas seguro?Si o No: ", 2, "\nRespuesta incorrecta"))
						{
							*cantidad = cantidadAux;
							eProducto_ModificacionStock(arrayProducto,lenProducto, idProducto, cantidadAux,0);
							retorno =indice;


						}

						else
						{
							//Si o no incorrecto
							retorno = -6;

						}
					}
					else
					{
						//Cantidad invalida
						retorno =-5;
					}
				}
				else
				{
					//ID inexistente
					retorno = -4;

				}

			}
			else
			{
				//printf("ID invalido")
				retorno = -4;

			}

		}


	}

	return retorno;


}


/// @fn Producto Cargar los Datos de una list de Producto
/// @param list puntero de Producto
/// @param len longitud de Producto
/// @return -1 punteros nullos len <0 [0]bien
int eProducto_CargarDatos(Producto * list,int len){

	int retorno=-1;
	int indice;
	Producto aux;

		if(list != NULL && len >0)
		{

			indice = eProducto_ObtenerIndexLibre(list, len);

			if(indice>=0 && eProducto_PediUnDato(&aux)==0)
			{

				if(eProducto_Alta(list, len, aux)==0)
				{
					//ok
					retorno=0;

				}

			}
			else
			{
				//lista llena
				retorno = -2;
			}


		}



		return retorno;

}

///FUNCION PARA LA MODIFICACION
/// @fn modifica Producto
/// @brief modica un dato de Producto
/// @param recibe un tipo Producto list
/// @param len recibe el tamanio del array
/// @param recibe el id que va a buscar
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int eProducto_ModificarUno(Producto *list,int len,int id){

	int retorno=-1;
	int indice;

	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */

		if(list!=NULL && len>0 && id>0)
		{

			retorno=0;
			indice=eProducto_BuscarPorid(list, len, id);

			if(indice<0){

				//ERROR NO ENCONTRO EL ID
				retorno=-2;

			}else if(indice>=0 && list[indice].isEmpty==OCUPADO){

				//-1 mal los datos -3 mal las opciones
				//-4 mal datos a modificar
				//-5 mal respuesta de si esta seguro
				//-6 mal respuesta si desea continuar
				retorno= queModifcar(indice,list);

			}


		}

		//return retorno;

	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */

	return retorno;
}

///FUNCION PARA LA MODIFICACION
/// @fn opcionesParaModifcar
/// 1-estado 2-nombre 3-precio 4-categoria 5-stock
/// @brief Modifica los datos segun la opcion
/// @return -1 mal 0 bien
static int opcionesParaModifcar(int opc, Producto* list){

	int retorno=-1;
	Producto aux=*list;

	if(list != NULL)
	{

		switch (opc)
		{

			case 1:
				//1-estado

				break;

			case 2:

				//2-nombre
				break;

			case 3:
				//3-precio
				break;

			case 4:

				//4-categoria

				break;

			case 5:
				//5-stock

				break;

			default:
				retorno = -1;
			break;

		}

		if(retorno==0)
		{
			*list=aux;
		}

	}

	return retorno;


}

///FUNCION PARA LA MODIFICACION
/// @fn queModifcar
/// @pre Segun la opcion ingresada por el usuario
/// @post va a mostrar un msj y guardarlo en auxiliar
/// De tipo Passenger
/// @param opc la opcion para el switch
/// @param indice para saber cual hay que modificar
/// @param p el puntero passenger para sobreecribir con
/// el auxiliar
/// @return 0 bien o -1 mal -3 mal las opciones
/// -4 mal datos a modificar -5 mal respuesta si esta seguro
/// -6 Mal la respuesta de si desea continuar
static int queModifcar(int indice,Producto *gen ){

	int retorno=-1;
	Producto aux;
	aux=gen[indice];
	int respuesta;
	int opc;

	if(gen != NULL && opc>0 && indice >=0 ){

		do{
			retorno= utn_getNumero(&opc, "\nOpciones de lo que desea modificar"
					"\n1-**"
					"\n2-***"
					"\n3-****"
					"\n4-*****"
					"\n5-******"
					"\nIngrese opcion: ",
					"\nError Ingrese nuevamente: ", 1, 5, 2);

			if(retorno==0)
			{
				retorno= opcionesParaModifcar(opc, &aux);

				if(retorno==0)
				{
					respuesta=preguntarSoN("\nEstas seguro? Si-No: ", 2, "\nIngrese [si] o [no]: ");

					if(respuesta)
					{
						gen[indice]=aux;
						printf("\nSE MODIFICO CON EXITO !");
					}
					if(respuesta==0)
					{
						printf("\nNO SE MODIFICARION LOS DATOS !");
					}
					else if(respuesta<0)
					{
						//Mal la respuesta de si esta seguro
						retorno=-5;
						break;
					}


				}
				else
				{
					//Mal los datos a modificar
					retorno=-4;
					break;
				}


				respuesta = preguntarSoN("\nDesea continuar modificando? Si-No: ", 2, "\nIngrese [si] o [no]: ");
				if(respuesta<0)
				{
					//Mal la respuesta de si desea continuar
					retorno=-6;
					break;
				}
			}
			else
			{
				//mal las opciones
				retorno =-3;
				break;
			}

		}while(respuesta);

	}

	return retorno;
}


///FUNCION PARA LA BAJA
/// \brief Eliminar un Producto por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Producto *
///\parametro len int
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede encontrar un Producto] -
///  (0) si está bien (-2) No estaba seguro
static int eProducto_remove(Producto* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			indice=eProducto_BuscarPorid(list, len, id);

			if(indice<0){

				retorno=-1;

			}else if(indice>=0){

				//Preguntar si esta seguro
				if(preguntarSoN("\nEsta seguro? Si o No: ", 2, "\nRespuesta invalida"))
				{
					list[indice].isEmpty=LIBRE;
					retorno=0;

				}
				else
				{

					retorno=-2;
				}

			}


		}

	return retorno;
}


/// @fn Da de alta un Producto
/// @param lista de Producto
/// @param len longitud del array Gen
/// @return 0 alta Producto (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int eProducto_Alta(Producto *list, int len,Producto productoDarAlta){

	int retorno=-1;
	int indice;


		if(list != NULL && len >=0)
		{
			indice=eProducto_ObtenerIndexLibre(list, len);

			if(indice>=0)
			{

				list[indice]=productoDarAlta;
				list[indice].id = generadorId();
				list[indice].isEmpty=OCUPADO;
				retorno=0;

			}
			else
			{
				retorno = indice;
			}


		}
		return retorno;

}


/// @fn Baja para Producto
/// @param list arreglo Producto
/// @param len longitud del arreglo
/// @return 0 bien -1 error parametros -2 no existe id -3 No hay datos cargados
/// -4 no estaba seguro
int eProducto_Baja(Producto *list, int len){

	int retorno=-1;
	int id;
	int rta;

	if(list != NULL && len >0)
	{
		if(eProducto_Vacio(list, len))
		{
			if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 3000, 2)==0)
			{
				rta=eProducto_remove(list, len, id);
				if(rta==0)
				{

					//ESTA OK
					retorno = 0;

				}
				else if(rta==-1)
				{

					//NO EXISTE ID
					retorno=-2;

				}
				else if(rta==-2)
				{
					//No se borro
					retorno=-4;
				}


			}

		}
		else
		{
			//Array vacio
			retorno = -3;
		}

	}


	return retorno;

}


/// @fn Modificacion para Producto
/// @param gen arreglo Producto
/// @param len longitud del arreglo
/// @param 1 suma 0 resta
/// @return 0 ok(-1)Datos nullos
int eProducto_ModificacionStock(Producto * list,int len,int id,int stock,int sumaOresta){

	int retorno =-1;
	int indice;

	if(list != NULL && id>=0 && stock >=0 && len>=0 && sumaOresta>=0 && sumaOresta<=1)
	{
		indice =eProducto_BuscarPorid(list, len, id);

		if(indice>=0)
		{
			if(sumaOresta==0)
			{
				list[indice].stock = list[indice].stock -stock;
				retorno=0;

			}
			if(sumaOresta==1)
			{
				list[indice].stock = list[indice].stock +stock;

			}


		}

	}


	return retorno;

}

