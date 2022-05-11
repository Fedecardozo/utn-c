
#include "ABM.h"

static int GeneradorId();
static int Gen_Vacio(Gen * list, int len);
static int removeGen(Gen* list, int len, int id);
static int opcionesParaModifcar(int opc, Gen* list);
static int queModifcar(int indice,Gen *gen );
static int sort_x(Gen *list, int len, int criterio);

/// @fn int GeneradorId()
/// @brief Genera un id automatico
/// @return Devuelve un id entero
static int GeneradorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Gen* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int Gen_Inicializar(Gen *list, int len){

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
/// @param list recibe un array tipo Gen
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int ObtenerIndexLibre(Gen* list, int len){

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

/// \brief Gen BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Gen *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int Gen_BuscarPorid(Gen *list, int len, int id){

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
/// @pre pide datos para llenar un Gen y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Gen
/// @return un 0 si esta todo bien o -1 si esta mal
int Gen_PediUnDato(Gen * list){

	Gen gen;
	int retorno=-1;

	if(list!=NULL){

		if(1)//utn_getStringMayusculayMinuscula(list.name, "\nIngrese nombre:","\nError esta mal escrito" , MAX_CARACTER, 2)==0)
		{

			gen.id = GeneradorId();
			gen.isEmpty=OCUPADO;
			retorno=0;
			*list=gen;

		}

	}

	return retorno;

}

/// @fn int imprime Gen
/// @param imprimi un Gen solo
void Gen_MostrarUno(Gen list){

	printf("|%-15d||%-15d|\n",list.id,list.id);

}

/// @fn imprime un array de Gen que esten cargados
/// @param recibi un puntero tipo Gen
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int Gen_MostrarTodos(Gen *list, int len){

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

				Gen_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Gen que esten dados de baja
/// @param recibi un puntero tipo Gen
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int Gen_MostrarDadosDeBaja(Gen *list, int len){

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

				Gen_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Gen * Puntero del array de Gen
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int Gen_Vacio(Gen * list, int len){

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

//SORT

/// @fn sort_x
/// @param list puntero de Gen
/// @param len longitud del array de  Gen
/// @param criterio orden 1 arriba - 0 abajo
/// @return 0 bien 1 se ordeno -1[parametros nullos o menor a 0]
static int sort_x(Gen *list, int len, int criterio){

	int i;
	Gen aux;
	Gen copia[len];
	int flagSwap;
	int newLimete=len-1;
	int retorno=-1;

	if(list != NULL && len>0 && criterio>=1 && criterio<=0)
	{
		retorno=0;
		*copia=*list;
		do{

			flagSwap=0;

			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					//Segun lo que quiera ordenar
					if(ordenEnteros(copia[i].id, copia[i+1].id, criterio)>0)
					{
						aux= copia[i];
						copia[i]=copia[i+1];
						copia[i+1]=aux;
						retorno=1;

					}

				}


			}
			newLimete--;

		}while(flagSwap);

		*list=*copia;

	}

	return retorno;

}


/// \brief Ordenar los elementos en el arreglo de Gen
/// Indicar orden ARRIBA o ABAJO
///\param lista Gen *
///\param len int
///\param criterio int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// (-2)Esta vacio (-3)Error al ordenar
int Gen_Sort(Gen *list, int len, int criterio){

	int retorno = -1;

		if(list != NULL && len >= 0 &&  criterio>=0 && criterio<=1 )
		{
			if(Gen_Vacio(list, len))
			{

				if(sort_x(list,len,criterio)>=0)//sort>=0)
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

//ABM


/// @fn Gen Cargar los Datos de una list de Gen
/// @param list puntero de Gen
/// @param len longitud de Gen
/// @return Gen cargado
int Gen_CargarDatos(Gen * list,int len){

	int i;
	int retorno=-1;
	Gen gen;

	if(list != NULL && len >0)
	{

		for (i = 0; i < len; i++)
		{

			if(Gen_PediUnDato(&gen)==-1)
			{
				list[i]=gen;
			}

		}


	}



	return retorno;

}

///FUNCION PARA LA MODIFICACION
/// @fn modifica Gen
/// @brief modica un dato de Gen
/// @param recibe un tipo Gen list
/// @param len recibe el tamanio del array
/// @param recibe el id que va a buscar
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int Gen_ModificarUno(Gen *list,int len,int id){

	int retorno=-1;
	int indice;

	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */

		if(list!=NULL && len>0 && id>0)
		{

			retorno=0;
			indice=Gen_BuscarPorid(list, len, id);

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
static int opcionesParaModifcar(int opc, Gen* list){

	int retorno=-1;
	Gen aux=*list;

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
static int queModifcar(int indice,Gen *gen ){

	int retorno=-1;
	Gen aux;
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
/// \brief Eliminar un Gen por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Gen *
///\parametro len int
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede encontrar un Gen] -
///  (0) si está bien (-2) No estaba seguro
static int removeGen(Gen* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			indice=Gen_BuscarPorid(list, len, id);

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
/// @fn Da de alta un Gen
/// @param lista de Gen
/// @param len longitud del array Gen
/// @return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int Gen_Alta(Gen *list, int len){

		Gen gen;
		int retorno=-1;
		int indice;


		if(list != NULL && len >=0)
		{

		//Busco primero lugar vacio para que el usuario, para avisarle que no hay lugar
		//antes de que complete los datos
		indice = ObtenerIndexLibre(list, len);

			if(indice>=0 && Gen_PediUnDato(&gen)==0)
			{

				list[indice]=gen;
				retorno=0;


			}else if(indice==-2){

				//Esta lleno
				retorno =-2;

			}


		}
		return retorno;

}


/// @fn Baja para Gen
/// @param list arreglo Gen
/// @param len longitud del arreglo
/// @return 0 bien -1 error parametros -2 no existe id -3 No hay datos cargados
/// -4 no estaba seguro
int Gen_Baja(Gen *list, int len){

	int retorno=-1;
	int id;
	int rta;

	if(list != NULL && len >0)
	{
		if(Gen_Vacio(list, len))
		{
			if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 3000, 2)==0)
			{
				rta=removeGen(list, len, id);
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


/// @fn Modificacion para Gen
/// @param gen arreglo Gen
/// @param len longitud del arreglo
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
/// (-7)EL ARREGLO ESTA VACIO
int Gen_Modificacion(Gen * gen,int len){

	int retorno =-1;
	int id;

	if(gen != NULL)
	{
		if(Gen_Vacio(gen, len))
		{

			//HASTA EL RETORNO ES -1
			if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 0, 1200, 2)==0){

				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=Gen_ModificarUno(gen,len,id);

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

