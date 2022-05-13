
#include "arrayProducto.h"

static int generadorId();
static int eProducto_Vacio(Producto * list, int len);
static int eProducto_remove(Producto* list, int len, int id);
static int opcionesParaModifcar(int opc, Producto* list);
static int queModifcar(int indice,Producto *gen );

/// @fn int generadorId()
/// @brief genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array est�n vac�as,
/// esta funci�n pone la bandera (isEmpty) en VERDADERO en todos
/// posici�nes del array
/// \param list Gen* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
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
/// @param len es el lena�o del del array
/// \return int Devuelve (-1) si Error [Longitud no v�lida o puntero NULL]
/// o -2 sin espacio libre - (0) si est� bien
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

/// \brief Producto BuscarPorid by Id en devuelve la posici�n del �ndice en el arreglo.
/// \param list Producto *
/// \param len int
/// \param id int
///\return Posici�n del �ndice de pasajero de retorno o (-1) si [Longitud o
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

		if(1)//utn_getStringMayusculayMinuscula(list.name, "\nIngrese nombre:","\nError esta mal escrito" , MAX_CARACTER, 2)==0)
		{

			aux.id = generadorId();
			aux.isEmpty=OCUPADO;
			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn int imprime Producto
/// @param imprimi un Producto solo
void eProducto_MostrarUno(Producto list){

	printf("|%-15d||%-15d|\n",list.id,list.id);

}

/// @fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int eProducto_MostrarTodos(Producto *list, int len){

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

			if(list[i].isEmpty==OCUPADO){

				eProducto_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Producto que esten dados de baja
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
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

/// \brief Pregunta si las posiciones en el array est�n vac�as,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0)vacio
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


//ABM


/// @fn Producto Cargar los Datos de una list de Producto
/// @param list puntero de Producto
/// @param len longitud de Producto
/// @return 1 punteros nullos len <0 [0]bien
int eProducto_CargarDatos(Producto * list,int len){

	int i;
	int retorno=-1;
	Producto aux;

	if(list != NULL && len >0)
	{

		for (i = 0; i < len; i++)
		{

			if(eProducto_PediUnDato(&aux)==-1)
			{
				list[i]=aux;
				retorno=0;
			}

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
				//retorno = //segun lo que se quiera modificar

				break;

			case 2:

				//retorno = //segun lo que se quiera modificar
				break;

			case 3:
				//retorno = //segun lo que se quiera modificar
				break;

			case 4:

				//retorno = //segun lo que se quiera modificar

				break;

			case 5:
				//retorno = //segun lo que se quiera modificar

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
///\lista de par�metros Producto *
///\parametro len int
///\id de par�metro int
///\return int Retorna (-1) si Error [longitud inv�lida o NULL
/// puntero o si no puede encontrar un Producto] -
///  (0) si est� bien (-2) No estaba seguro
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


//ANALIZAR
/// @fn Da de alta un Producto
/// @param lista de Producto
/// @param len longitud del array Gen
/// @return Posici�n del �ndice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int eProducto_Alta(Producto *list, int len){

		Producto aux;
		int retorno=-1;
		int indice;


		if(list != NULL && len >=0)
		{

		//Busco primero lugar vacio para que el usuario, para avisarle que no hay lugar
		//antes de que complete los datos
		indice = eProducto_ObtenerIndexLibre(list, len);

			if(indice>=0 && eProducto_PediUnDato(&aux)==0)
			{

				list[indice]=aux;
				retorno=0;


			}else if(indice==-2){

				//Esta lleno
				retorno =-2;

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
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
/// (-7)EL ARREGLO ESTA VACIO
int eProducto_Modificacion(Producto * list,int len){

	int retorno =-1;
	int id;

	if(list != NULL)
	{
		if(eProducto_Vacio(list, len))
		{

			//HASTA EL RETORNO ES -1
			if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 0, 1200, 2)==0){

				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=eProducto_ModificarUno(list,len,id);

			}

		}
		else
		{
			//EL ARREGLO ESTA VACIO
			retorno =-7;
		}

	}




	return retorno;

}

