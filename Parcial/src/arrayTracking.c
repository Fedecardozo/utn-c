
#include "arrayTracking.h"


long int time_Current(void){
	return time(NULL);
}

long int time_Add(double secondsAdd){
	return time_Current() + secondsAdd;
}
long int time_Llegada(double secondsAdd){
	return secondsAdd-time_Current();
}

//t1add-time_Current()

static int generadorId();
static int eTracking_VacioUsuarioVentas(Tracking * list,int fkUsuario, int len ,int estado);
static int eTracking_VacioUsuarioCompras(Tracking * list,int fkUsuario, int len);

void harcodeoTracking(Tracking * listTracking,int lenTracking){

	Tracking aux;

	//Usuario 1000
	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto= 1001;
	aux.Fk_UsuarioVendedor = 1002;
	aux.cantidad = 2;
	aux.distanciaKM = 20;
	aux.horaLlegada = time_Add(20);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto = 1002;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 1;
	aux.distanciaKM = 40;
	aux.horaLlegada = time_Add(40);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 5;
	aux.distanciaKM = 30;
	aux.horaLlegada = time_Add(30);

	eTracking_Alta(listTracking, lenTracking, aux);

	//Usuario 1001

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1000;
	aux.Fk_UsuarioVendedor = 1000;
	aux.cantidad = 5;
	aux.distanciaKM = 50;
	aux.horaLlegada = time_Add(50);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1001;
	aux.Fk_UsuarioVendedor = 1002;
	aux.cantidad = 2;
	aux.distanciaKM = 80;
	aux.horaLlegada = time_Add(80);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 2;
	aux.distanciaKM = 150;
	aux.horaLlegada = time_Add(150);

	eTracking_Alta(listTracking, lenTracking, aux);


	//Usuario 1002

	aux.Fk_UsuarioComprador = 1002;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 2;
	aux.distanciaKM = 80;
	aux.horaLlegada = time_Add(80);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1002;
	aux.idProducto = 1000;
	aux.Fk_UsuarioVendedor = 1000;
	aux.cantidad = 2;
	aux.distanciaKM = 30;
	aux.horaLlegada = time_Add(30);

	eTracking_Alta(listTracking, lenTracking, aux);

}

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
int eTracking_Inicializar(Tracking *list, int len){

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=VACIO;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param list recibe un array tipo Tracking
/// @param len es el lena�o del del array
/// \return int Devuelve (-1) si Error [Longitud no v�lida o puntero NULL]
/// o -2 sin espacio libre - (0) si est� bien
int eTracking_ObtenerIndexLibre(Tracking* list, int len){

	int retorno=-1;
	int i;


		if (list != NULL && len > 0)
		{

		for (i = 0; i < len; i++)
		{

			if (list[i].isEmpty == VACIO)
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

/// \brief Tracking BuscarPorid by Id en devuelve la posici�n del �ndice en el arreglo.
/// \param list Tracking *
/// \param len int
/// \param id int
///\return Posici�n del �ndice de pasajero de retorno o (-1) si [Longitud o
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

	//char* horaLlegada = ctime(&list.horaLlegada);
	char estado [4][20]={{"LIBRE"},{"EN VIAJE"},{"ENTREGADO"},{"CANCELADO"}};

	long int horallegada =list.horaLlegada-time_Current();

	if(horallegada <= 0)
	{
		horallegada =0;

	}

	printf("|%-15d|%-15d|%-15d|%-3ld%-12s|%-14s|",list.idProducto,list.cantidad,
			list.distanciaKM,horallegada,"Segundos",estado[list.isEmpty]);

}


/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
/// @param estado EN_VIAJE 1 ENTREGADO 2 CANCELADO 3
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int eTracking_MostrarTodos(Tracking *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+----------------------------------------"
						"--------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-14s\n",
				" ID PRODUCTO"," CANTIDAD"," DISTANCIA"," HORA LLEGADA","   ESTADO");
		printf("+--------------------------------------------"
						"----------------------------------+\n");
		for (i = 0; i < len ; i++)
		{

			if(list[i].isEmpty >= EN_VIAJE)
			{

				eTracking_Estado(list[i]);
				printf("\n+-------------------------------------------"
							"-----------------------------------+\n");


			}

		}

	}


	return retorno;

}


/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
/// @param estado EN_VIAJE 1 ENTREGADO 2 CANCELADO 3
///return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) esta vacio
/// 1 ok
int eTracking_MostrarProductosUsuarioEstado(Tracking *list, int len,Usuario* arrayUsuario,int indiceUsuario,int estado){

	int retorno = -1;
	int i;
	char sEstado [4][20]={{"LIBRE"},{"EN VIAJE"},{"ENTREGADO"},{"CANCELADO"}};

	if(list != NULL && len >=0 && indiceUsuario >= 0 && estado>=1 && estado<=3)
	{
		if(eTracking_VacioUsuarioVentas(list, arrayUsuario[indiceUsuario].idUsuario, len, estado))
		{

			retorno=1;

			printf("+----------------------------------------"
											"--------------------------------------+\n");
			printf("|          %-67s %s|\n",
							"         ESTADOS DE PRODUCTOS ",sEstado[estado]);
			printf("+--------------------------------------------"
									"----------------------------------+\n");

			printf("+----------------------------------------"
									"--------------------------------------+\n");
			printf("|%-15s|%-15s|%-15s|%-15s|%-14s|\n",
							" ID PRODUCTO"," CANTIDAD"," DISTANCIA"," HORA LLEGADA","ESTADO");
			printf("+--------------------------------------------"
									"----------------------------------+\n");
			for (i = 0; i < len ; i++)
			{

				if(list[i].isEmpty==estado && list[i].Fk_UsuarioVendedor== arrayUsuario[indiceUsuario].idUsuario)
				{

					eTracking_Estado(list[i]);
					printf("\n+-------------------------------------------"
										"-----------------------------------+\n");

				}

			}

	   }
	   else
	   {

		   retorno = 0;

	   }

	}


	return retorno;

}


/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) vacio
/// 1 cargado
int eTracking_MostrarProductosUsuario(Tracking *list, int len,Usuario* arrayUsuario,int indiceUsuario){

	int retorno = -1;
	int i;
	long int horallegada;

	if(list != NULL && len >=0 && indiceUsuario >= 0)
	{
		retorno=0;

		if(eTracking_VacioUsuarioCompras(list, arrayUsuario[indiceUsuario].idUsuario, len))
		{
			retorno = 1;
			printf("+----------------------------------------"
									"--------------------------------------+\n");
			printf("|%-15s|%-15s|%-15s|%-15s|%-14s|\n",
							" ID PRODUCTO"," CANTIDAD"," DISTANCIA"," HORA LLEGADA","ESTADO");
			printf("+--------------------------------------------"
									"----------------------------------+\n");
			for (i = 0; i < len ; i++)
			{
				horallegada=list[i].horaLlegada-time_Current();
				if(list[i].isEmpty==EN_VIAJE && list[i].Fk_UsuarioComprador== arrayUsuario[indiceUsuario].idUsuario
					&&	horallegada <= 0 && eTracking_ModificarEstado(list, i, ENTREGADO)==0)
				{
					retorno = 1;
				}

				if(list[i].isEmpty>=EN_VIAJE && list[i].Fk_UsuarioComprador== arrayUsuario[indiceUsuario].idUsuario)
				{

						eTracking_Estado(list[i]);
						printf("\n+-------------------------------------------"
											"-----------------------------------+\n");


				}

			}
	    }
	}


	return retorno;

}



static int eTracking_calculoDistancia(int codigoPostal){

	int retorno=-1;;
	int distancia;

	if(codigoPostal > 0)
	{
		retorno=0;

		if(codigoPostal>=1 && codigoPostal <=1000)
		{
			distancia = 20;
		}
		if (codigoPostal >= 1001 && codigoPostal <= 3000)
		{
			distancia = 30;
		}
		if (codigoPostal >= 3001 && codigoPostal <= 5000)
		{
			distancia = 50;
		}
		if (codigoPostal >= 5001 && codigoPostal <= 8000)
		{
			distancia = 80;
		}
		if (codigoPostal >= 8001 && codigoPostal <= 9999)
		{
			distancia = 150;
		}
		retorno= distancia;

	}

	return retorno;

}


/// \brief Pregunta si las posiciones en el array est�n vac�as,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_VacioUsuarioVentas(Tracking * list,int fkUsuario, int len ,int estado){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].Fk_UsuarioVendedor==fkUsuario && list[i].isEmpty==estado)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}


/// \brief Pregunta si las posiciones en el array est�n vac�as,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_VacioUsuarioCompras(Tracking * list,int fkUsuario, int len){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].Fk_UsuarioComprador==fkUsuario)
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
	int distancia;
	Tracking aux;

	if(arrayProducto != NULL  && listTracking != NULL && listUsuario != NULL
			&& lenTracking >0 && indiceProducto>=0 && indiceUsuario >=0)
	{

		distancia = eTracking_calculoDistancia(listUsuario[indiceUsuario].codigoPostal);

		aux.idProducto = arrayProducto[indiceProducto].id;
		aux.Fk_UsuarioComprador = listUsuario[indiceUsuario].idUsuario;
		aux.Fk_UsuarioVendedor = arrayProducto[indiceProducto].Fk_idUsuario;
		aux.cantidad = cantidad;
		aux.distanciaKM = distancia;
		aux.horaLlegada = time_Add(distancia);

		retorno=eTracking_Alta(listTracking, lenTracking, aux);

	}



	return retorno;

}


/// @fn int eTracking_ConsultaEstado(Tracking*, int, Usuario*, int)
/// @param listTracking
/// @param lenTracking
/// @param listUsuario
/// @param indiceUsuario
/// @return -1 nullos -2 id incorrecto
/// -3 no existe tal producto -4 contesto S-N negativamente
int eTracking_ConsultaEstado(Tracking* listTracking,int lenTracking, Usuario * listUsuario, int indiceUsuario){

	int retorno = -1;
	int i;
	int idProducto;
	int indexTracking;

		if(listTracking != NULL && lenTracking >= 0)
		{
			//tener el id del producto
			if(utn_getNumero(&idProducto, "\nIngrese id a modificar: ",
					"Error!\nIngrese nuevamente: ", 1000, 9999, 2)==0)
			{
				for (i = 0; i < lenTracking; ++i)
				{
					if(listTracking[i].Fk_UsuarioComprador == listUsuario[indiceUsuario].idUsuario
							&& listTracking[i].idProducto == idProducto && listTracking[i].isEmpty == EN_VIAJE)
					{
						indexTracking=i;
						//preguntar si quiere cancelar el producto
						if(preguntarSoN("Estas seguro de cancelar el envio? Si - No: ", 2, "\nRespuesta incorrecta"))
						{

							retorno = eTracking_ModificarEstado(listTracking, indexTracking, CANCELADO);

						}
						else
						{

							//NO se decidio
							retorno = -4;

						}

					}
					else
					{
						//NO existe tal producto
						retorno = -3;

					}

				}
			}
			else
			{
				// id incorrecto
				retorno = -2;
			}



		}


	return retorno;

}


/// @fn int eTracking_Alta(Tracking*, int, Tracking)
/// @param listTracking
/// @param lenTracking
/// @param aDarseAlta
/// @return -1 nullos -2 lista llena 0 ok
int eTracking_Alta(Tracking* listTracking,int lenTracking,Tracking aDarseAlta){

	int retorno=-1;
	int index;

	if(listTracking != NULL && lenTracking> 0)
	{

		index = eTracking_ObtenerIndexLibre(listTracking, lenTracking);

		if(index >= 0)
		{
			retorno=0;
			listTracking[index] = aDarseAlta;
			listTracking[index].idTracking = generadorId();
			listTracking[index].isEmpty = EN_VIAJE;

		}
		else
		{
			retorno = index;

		}



	}



	return retorno;

}


/// @fn int eTracking_ModificarEstado(Tracking*, int, int)
/// @param listTracking
/// @param indice
/// @param estado
/// @return -1 nullo 0 ok
int eTracking_ModificarEstado(Tracking* listTracking,int indice,int estado){

	int retorno = -1;

	if(listTracking != NULL && indice >= 0)
	{

		listTracking[indice].isEmpty = estado;
		retorno=0;

	}

	return retorno;
}


