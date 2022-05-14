
#include "RelacionProductosUsuarios.h"

void harcodeo(Producto * listP,int lenP,Usuario * listU,int lenU){

	Producto aux;

	Usuario auxUsuario;


	strncpy(auxUsuario.correo,"FEDECARDOZO@GMAIL.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"anuel12",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"pasaje calabria 1590",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1828;
	auxUsuario.tipo = 1;

	eUsuario_Alta(listU, lenU, auxUsuario);

	strncpy(auxUsuario.correo,"FEDE@G.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"1234",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"calle falsa 123",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1152;
	auxUsuario.tipo = 1;

	eUsuario_Alta(listU, lenU, auxUsuario);

	strncpy(auxUsuario.correo,"CARS@G.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"1235",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"carriego 321",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1125;
	auxUsuario.tipo = 2;

	eUsuario_Alta(listU, lenU, auxUsuario);

	//PRODUCTOS

	strncpy(aux.nombreProducto,"Lavarropa",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 1;
	aux.stock = 10;
	aux.Fk_idUsuario = 1000;

	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Notebook",MAX_NOMBRE);
	aux.precio = 2900;
	aux.categoria = 3;
	aux.stock = 5;
	aux.Fk_idUsuario = 1002;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Heladera",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 2;
	aux.stock = 2;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Lavarropa",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 4;
	aux.stock = 10;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);


}

/// @fn int alta_Producto(Producto*, int, Usuario*, int, int)
/// @param arrayProducto
/// @param lenProducto
/// @param arrayUsuario
/// @param lenUsuario
/// @param indice
/// @return -1 datos nullos -2 lista llena 0 bien
int alta_Producto(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario)
{

	int retorno =-1;
	Producto aux;
	int indexProducto;

	if(arrayProducto != NULL  && lenProducto >0 && arrayUsuario != NULL && indiceUsuario >=0 )
	{
		indexProducto = eProducto_ObtenerIndexLibre(arrayProducto, lenProducto);

		if(indexProducto >=0)
		{

			if(eProducto_PediUnDato(&aux)==0)
			{
			//Guardar id usuario en fk producto
				aux.Fk_idUsuario = arrayUsuario[indiceUsuario].idUsuario;
				if(eProducto_Alta(arrayProducto, lenProducto, aux)==0)
				{
					retorno=0;

				}


			}

		}
		else if(indexProducto == -2)
		{
			//Lista llena
			retorno = -2;

		}




	}



	return retorno;

}

/// @fn int print_ProductosdelUsuario(Producto*, int, Usuario*, int)
/// @param arrayProducto
/// @param lenProducto
/// @param arrayUsuario
/// @param indiceUsuario
/// @return -1 datos nullos 0 bien
int print_ProductosdelUsuario(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario){

	int retorno = -1;
	int idUsu;

	if(arrayProducto != NULL  && lenProducto >0 && arrayUsuario != NULL && indiceUsuario >=0 )
	{
		idUsu = arrayUsuario[indiceUsuario].idUsuario;

		retorno =eProducto_MostrarFk(arrayProducto, lenProducto, idUsu);

	}


	return retorno;

}


