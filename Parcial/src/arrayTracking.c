
#include "arrayTracking.h"

static int generadorId();
static int eTracking_Vacio(Tracking * list, int len);


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
int eTracking_Inicializar(Tracking *list, int len){

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
/// @param list recibe un array tipo Tracking
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eTracking_ObtenerIndexLibre(Tracking* list, int len){

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

/// \brief Tracking BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Tracking *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eTracking_BuscarPorid(Tracking *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].idTracking== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Tracking y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Tracking
/// @return un 0 si esta todo bien o -1 si esta mal
int eTracking_PediUnDato(Tracking * list){

	Tracking aux;
	int retorno=-1;

	if(list!=NULL){

		if(1)
		{

			aux.idTracking = generadorId();
			aux.isEmpty=OCUPADO;
			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn int imprime Tracking
/// @param imprimi un Tracking solo
void eTracking_Estado(Tracking list){

	printf("\n|%-15d|%-15d|%-15d|%-15d|%-15d|",list.idTracking,list.idProducto,
			list.Fk_UsuarioComprador,list.Fk_UsuarioVendedor,list.cantidad);

}

/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eTracking_MostrarTodos(Tracking *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+----------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-15s|\n",
				" ID TRACKING"," ID PRODUCTO"," FK COMPRADOR"," FK VENDEDOR","CANTIDAD");
		printf("+----------------------------------------------"
						"----------------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO){

				eTracking_Estado(list[i]);
				printf("+----------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eTracking_MostrarProductosUsuario(Tracking *list, int len,Usuario* arrayUsuario,int indiceUsuario){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0 && indiceUsuario >= 0){

		retorno=0;
		printf("+----------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-15s|\n",
				" ID TRACKING"," ID PRODUCTO"," FK COMPRADOR"," FK VENDEDOR","CANTIDAD");
		printf("+----------------------------------------------"
						"----------------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO && list[i].Fk_UsuarioComprador== arrayUsuario[indiceUsuario].idUsuario){

				eTracking_Estado(list[i]);
				printf("+----------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_Vacio(Tracking * list, int len){

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

/// @fn Tracking Cargar los Datos de una list de Tracking
/// @param list puntero de Tracking
/// @param len longitud de Tracking
/// @return -1 punteros nullos len <0 [0]bien
int eTracking_CargarDatos(Tracking * listTracking,int lenTracking,Producto* arrayProducto, int indiceProducto,Usuario *listUsuario, int indiceUsuario,int cantidad){

	int retorno = -1;
	Tracking aux;

	if(arrayProducto != NULL  && listTracking != NULL && listUsuario != NULL
			&& lenTracking >0 && indiceProducto>=0 && indiceUsuario >=0)
	{

		aux.idProducto = arrayProducto[indiceProducto].id;
		aux.Fk_UsuarioComprador = listUsuario[indiceUsuario].idUsuario;
		aux.Fk_UsuarioVendedor = arrayProducto[indiceProducto].Fk_idUsuario;
		aux.cantidad = cantidad;

		retorno=eTracking_Alta(listTracking, lenTracking, aux);

	}



	return retorno;

}

int eTracking_Alta(Tracking* listTracking,int lenTracking,Tracking aDarseAlta){

	int retorno=-1;
	int index;

	if(listTracking != NULL && lenTracking> 0)
	{

		index = eTracking_ObtenerIndexLibre(listTracking, lenTracking);

		if(index == 0)
		{
			retorno=0;
			listTracking[index] = aDarseAlta;
			listTracking[index].isEmpty = OCUPADO;
			listTracking[index].idTracking = generadorId();

		}
		else
		{
			retorno = index;

		}



	}



	return retorno;

}

//PRODUCTOS Y USUARIOS

