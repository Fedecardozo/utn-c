
#include "arrayUsuario.h"

static int generadorId();
static int eUsuario_Vacio(Usuario * list, int len);
static int eUsuario_remove(Usuario* list, int len, int id);
static int opcionesParaModifcar(int opc, Usuario* list);
static int queModifcar(int indice,Usuario *gen );
static int eUsuario_VerificacionSesion(Usuario * list,int len,Usuario aux);


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
int eUsuario_Inicializar(Usuario *list, int len){

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
/// @param list recibe un array tipo Usuario
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eUsuario_ObtenerIndexLibre(Usuario* list, int len){

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

/// \brief Usuario BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Usuario *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eUsuario_BuscarPorid(Usuario *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].idUsuario== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Usuario y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Usuario
/// @return (-1)[list null, longitud menor a 0]
/// (-2)NO hay datos cargados
/// (0)NO hay correo o contraseña
/// (1)Hay correo y contraseña
int eUsuario_InicioSesion(Usuario * list, int len){

	Usuario aux;
	int retorno=-1;

	if(list!=NULL){

		retorno =eUsuario_Vacio(list, len);

		if(retorno)
		{
			if(utn_getStringCorreo(aux.correo, "\nexample@gmail.com\nIngrese correo: ", "\nError correo invalido", MAX_CORREO, 2)==0
					&& utn_getStringLetrasYnumerosLimite(aux.password,"\nIngrese password: ",
							"\nError password invalido",MIN_PASSWORD, MAX_PASSWORD , 2)==0)
			{

				retorno=eUsuario_VerificacionSesion(list, len, aux);

			}
		}
		else if(retorno == 0)
		{
			retorno = -2;
		}

	}

	return retorno;

}

/// @fn Verifica si el correo y password hay en el array
/// @param list lista de Usuario
/// @param len longitud de Usuario
/// @param aux Usuario a comparar
/// @return (-1)[list null, longitud menor a 0]
/// (-2)NO hay datos cargados
/// (-3)NO hay correo o contraseña
/// (indice>=0)Hay correo y contraseña
static int eUsuario_VerificacionSesion(Usuario * list,int len,Usuario aux){

	int i;
	int retorno=-1;

	if(list != NULL && len>=0 )
	{
		if(eUsuario_Vacio(list, len))
		{
			retorno =-3;
			for (i = 0; i < len; i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{

					if(strcmp(list[i].correo,aux.correo)==0 && strcmp(list[i].password,aux.password)==0)
					{
						retorno = i;
						break;

					}


				}

			}

		}else
		{
			retorno = -2;
		}

	}

	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Usuario y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Usuario
/// @return un 0 si esta todo bien o -1 si esta mal
int eUsuario_Registrarse(Usuario * list){

	Usuario aux;
	int retorno=-1;

	if(list!=NULL){

		if(utn_getStringCorreo(aux.correo, "\nexample@gmail.com\nIngrese correo: ", "\nError correo invalido", MAX_CORREO, 2)==0
				&& utn_getStringLetrasYnumerosLimite(aux.password,"\nIngrese password: ",
						"\nError password invalido",MIN_PASSWORD, MAX_PASSWORD, 2)==0
				&& utn_getString(aux.direccion,"\nIngrese domicilio: ", "\nError direccion invalida", MAX_DIRECCION, 2)==0
				&& utn_getNumero(&aux.codigoPostal, "\nIngrese codigo postal: ",
						"\nError codigo postal invalido", 1000, 9999, 2)==0
				&& utn_getNumero(&aux.tipo, "\n**TIPOS** \n 1)Usuario \n 2) Administrador"
						" \nIngrese tipo: ",
						"\nError tipo invalido", 1, 2, 2)==0)
		{

			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn int imprime Usuario
/// @param imprimi un Usuario solo
void eUsuario_MostrarUno(Usuario list){

	printf("|%-7d|%-10d|%-10d|%-30s|%-15s|%-7d|%-30s|\n"
			,list.idUsuario,list.isEmpty,list.codigoPostal,list.correo,list.password,list.tipo,list.direccion);

}

/// @fn imprime un array de Usuario que esten cargados
/// @param recibi un puntero tipo Usuario
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eUsuario_MostrarTodos(Usuario *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+-----------------------------------------------------------"
				"--------------------------------------------------------+\n");
		printf("|%-7s|%-10s|%-10s|%-30s|%-15s|%-7s|%-30s|\n",
				"Id"," ISEMPTY"," CP"," CORREO","PASSWORD"," TIPO"," DOMICILIO");
		  printf("+-------------------------------------------------------------------"
				  "------------------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO){

				eUsuario_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
							"--------------------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Usuario que esten dados de baja
/// @param recibi un puntero tipo Usuario
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eUsuario_MostrarDadosDeBaja(Usuario *list, int len){

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

				eUsuario_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Usuario * Puntero del array de Usuario
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eUsuario_Vacio(Usuario * list, int len){

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

/// @fn Usuario Cargar los Datos de una list de Usuario
/// @param list puntero de Usuario
/// @param len longitud de Usuario
/// @return 1 punteros nullos len <0 [0]bien -2 lista llena
int eUsuario_CargarDatos(Usuario * list,int len){

	int retorno=-1;
	int indice;
	Usuario aux;

	if(list != NULL && len >0)
	{

		indice = eUsuario_ObtenerIndexLibre(list, len);

		if(indice>=0 && eUsuario_Registrarse(&aux)==0)
		{

			if(eUsuario_Alta(list, len, aux)==0)
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
/// @fn modifica Usuario
/// @brief modica un dato de Usuario
/// @param recibe un tipo Usuario list
/// @param len recibe el tamanio del array
/// @param recibe el id que va a buscar
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int eUsuario_ModificarUno(Usuario *list,int len,int id){

	int retorno=-1;
	int indice;

	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */

		if(list!=NULL && len>0 && id>0)
		{

			retorno=0;
			indice=eUsuario_BuscarPorid(list, len, id);

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
static int opcionesParaModifcar(int opc, Usuario* list){

	int retorno=-1;
	Usuario aux=*list;

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
static int queModifcar(int indice,Usuario *gen ){

	int retorno=-1;
	Usuario aux;
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
/// \brief Eliminar un Usuario por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Usuario *
///\parametro len int
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede encontrar un Usuario] -
///  (0) si está bien (-2) No estaba seguro
static int eUsuario_remove(Usuario* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			indice=eUsuario_BuscarPorid(list, len, id);

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


/// @fn Da de alta un Usuario
/// @param lista de Usuario
/// @param len longitud del array Gen
/// @return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int eUsuario_Alta(Usuario *list, int len,Usuario usuarioDarAlta){

		int retorno=-1;
		int indice;


		if(list != NULL && len >=0)
		{
			indice=eUsuario_ObtenerIndexLibre(list, len);

			if(indice>=0)
			{

				list[indice]=usuarioDarAlta;
				list[indice].idUsuario = generadorId();
				list[indice].isEmpty=OCUPADO;
				retorno=0;

			}


		}
		return retorno;

}


/// @fn Baja para Usuario
/// @param list arreglo Usuario
/// @param len longitud del arreglo
/// @return 0 bien -1 error parametros -2 no existe id -3 No hay datos cargados
/// -4 no estaba seguro
int eUsuario_Baja(Usuario *list, int len){

	int retorno=-1;
	int id;
	int rta;

	if(list != NULL && len >0)
	{
		if(eUsuario_Vacio(list, len))
		{
			if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 3000, 2)==0)
			{
				rta=eUsuario_remove(list, len, id);
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


/// @fn Modificacion para Usuario
/// @param gen arreglo Usuario
/// @param len longitud del arreglo
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
/// (-7)EL ARREGLO ESTA VACIO
int eUsuario_Modificacion(Usuario * list,int len){

	int retorno =-1;
	int id;

	if(list != NULL)
	{
		if(eUsuario_Vacio(list, len))
		{

			//HASTA EL RETORNO ES -1
			if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 0, 1200, 2)==0){

				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=eUsuario_ModificarUno(list,len,id);

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

