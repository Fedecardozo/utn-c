
#include"utn.h"

//Prototypos
static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena,int limite);
static int getFloat(float* pResultado);
static int sonLetras(char*pLetras,int longitud);
static int getStringLetras(char* pResultado,int longitud);
static int getStringLetrasYnumeros(char* pResultado,int longitud);
static int sonLetrasYnumeros(char*pLetras,int longitud);
static int getString(char* pResultado,int longitud);
static int mayusculaMinuscula(char*bufferString, int len);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama�o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);//Limpiamos el buffer por las dudas
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo < maximo && reintentos >=0){
		printf("%s",mensaje);
		do{


			if(	getInt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}


			else if(reintentos >0)
			{

				printf("%s",mensajeError);

			}

			reintentos--;

		}while(reintentos>=0);


	}


	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[70];

	if(	pResultado != NULL &&
		myGets(bufferString,sizeof(bufferString)) == 0 &&
		esFlotante(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atof(bufferString) ;

	}
	    return retorno;


    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena,int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	int bandera=0;

		for(i=0;i<limite && cadena[i] != '\0';i++)
		{

			//printf("%c-",cadena[i]);
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			//si entra una vez esta bien. Si entra mas de una vez esta mal
			if((i!=0 && cadena[i]=='.') ||(bandera >= 1 && cadena[i]<'0') ){

				bandera++;

			}
			//Si es mayor a 9 esta mal o si es menor a 0 y si la bandera es igual a cero
			//lo que significa que lo ingreso no es un punto y si ingreso mas de un '.' esta mal
			if(cadena[i] > '9' || (cadena[i] < '0' && bandera !=1))
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
		return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >=0){

		do{

			printf(mensaje);

			if(	getFloat(&bufferFloat) == 0 &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else if(reintentos >0)
			{

				printf("%s",mensajeError);

			}
			reintentos--;
		}while(reintentos>=0);



	}


		return retorno;
}


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo < maximo && reintentos >=0){

		printf("%s",mensaje);
		scanf("%c",&bufferChar);

		do{


			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}

			printf("%s",mensajeError);
			scanf("%c",&bufferChar);
			reintentos--;

		}while(reintentos>=0);



	}


		return retorno;


}


/// @fn int utn_getString(char*, char*, char*, int, int)
/// @brief Solicita un numero cadena al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param longitud Es el tama�o del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int utn_getString(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos){

	int retorno=-1;

	//printf("%d",longitud);
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud >0 && intentos>=0){

		//Creo la variable aca para primero validar de longitud sea mayor a 0
		char bufferString[longitud];

		do{

			printf("%s",mensaje);

			//Si esta todo bien lo copia en el puntero y sale de la iteracion retornado cero
			if(getString(bufferString,longitud)==0){

				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;

			}else if(intentos>0){

				printf("%s",mensajeError);

			}

			intentos--;


		}while(intentos>=0);


	}


	return retorno;

}

/// \brief Obtien una cadena
///\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
///\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
static int getString(char* pResultado,int longitud){

	int retorno =-1;
	char bufferString[200];//Esto despues se va a cambiar


	if(pResultado != NULL &&
		myGets(bufferString,sizeof(bufferString))==0){

		strncpy(pResultado,bufferString,longitud);
		retorno=0;

	}

	return retorno;

}

/// @fn int utn_getString(char*, char*, char*, int, int)
/// @brief Solicita un numero cadena al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param longitud Es el tama�o del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int utn_getStringLetras(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos){

	int retorno=-1;

	//printf("%d",longitud);
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud >0 && intentos>=0){

		//Creo la variable aca para primero validar de longitud sea mayor a 0
		char bufferString[longitud];

		do{

			printf("%s",mensaje);

			//Si esta todo bien lo copia en el puntero y sale de la iteracion retornado cero
			if(getStringLetras(bufferString,longitud)==0){

				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;

			}else if(intentos>0){

				printf("%s",mensajeError);

			}

			intentos--;


		}while(intentos>=0);


	}


	return retorno;

}

/// \brief Obtien una cadena
///\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
///\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
static int getStringLetras(char* pResultado,int longitud){

	int retorno =-1;
	char bufferString[200];//Esto despues se va a cambiar


	if(pResultado != NULL &&
		myGets(bufferString,sizeof(bufferString))==0
			&& sonLetras(bufferString,sizeof(bufferString))){

		strncpy(pResultado,bufferString,longitud);
		retorno=0;

	}

	return retorno;

}

///\brief Verifica si la cadena ingresada son letras
///\param pLetras Cadena de caracteres a ser analizada
///\return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
static int sonLetras(char*pLetras,int longitud)
{
	int retorno= 1;
	int i;

	// No valido los datos por que ya lo hace myGets

	for (i = 0; i<longitud && pLetras[i]!='\0'; i++){

		if(pLetras[i] >= 'A' && pLetras[i] <= 'Z'){

			continue;

		}

		if(pLetras[i] < 'a' || pLetras[i] > 'z'){

			retorno=0;
			break;

		}

	}


	return retorno;
}

/// @fn int utn_getStringLetrasYnumerosLimite(char*, char*, char*, int, int)
/// @brief Solicita unacadena al usuario, luego de verificarlo devuelve el resultado
/// con limites de caracteres ni mas ni menos lo mismo
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param limite Es el tama�o del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int utn_getStringLetrasYnumerosLimite(char* pResultado, char* mensaje, char* mensajeError,int limite, int intentos){

	int retorno=-1;

		//printf("%d",longitud);
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && limite >0 && intentos>=0){

			//Creo la variable aca para primero validar de longitud sea mayor a 0
			char bufferString[limite];

			do{

				printf("%s",mensaje);

				//Si esta tod bien lo copia en el puntero y sale de la iteracion retornado cero
				if(getStringLetrasYnumeros(bufferString,limite+1)==0)
				{

					if(strlen(bufferString)==limite)
					{

						strncpy(pResultado,bufferString,limite);
						retorno=0;
						break;

					}else if(intentos>0){

						printf("%s",mensajeError);

					}

				intentos--;

			   }

			}while(intentos>=0);


		}


		return retorno;


}

/// @fn int utn_getStringLetrasYnumeros(char*, char*, char*, int, int)
/// @brief Solicita una cadena al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param limite Es el tama�o del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int utn_getStringLetrasYnumeros(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos){

	int retorno=-1;

		//printf("%d",longitud);
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud >0 && intentos>=0){

			//Creo la variable aca para primero validar de longitud sea mayor a 0
			char bufferString[longitud];

			do{

				printf("%s",mensaje);

				//Si esta todo bien lo copia en el puntero y sale de la iteracion retornado cero
				if(getStringLetrasYnumeros(bufferString,longitud)==0){

					strncpy(pResultado,bufferString,longitud);
					retorno=0;
					break;

				}else if(intentos>0){

					printf("%s",mensajeError);

				}

				intentos--;


			}while(intentos>=0);


		}


		return retorno;


}


/// \brief Obtien una cadena de letras y numeros
///\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
///\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
static int getStringLetrasYnumeros(char* pResultado,int longitud){

	int retorno =-1;
	char bufferString[200];//Esto despues se va a cambiar


	if(pResultado != NULL &&
		myGets(bufferString,sizeof(bufferString))==0
		&& sonLetrasYnumeros(bufferString,sizeof(bufferString))){

		strncpy(pResultado,bufferString,longitud);
		retorno=0;

	}

	return retorno;

}


///\brief Verifica si la cadena ingresada son letras y numeros
///\param pLetras Cadena de caracteres a ser analizada
///\return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
static int sonLetrasYnumeros(char*pLetras,int longitud)
{
	int retorno= 1;
	int i;

	// No valido los datos por que ya lo hace myGets

	for (i = 0; i<longitud && pLetras[i]!='\0'; i++){


		if(pLetras[i] >= 'A' && pLetras[i] <= 'Z'){

			//printf("\nb");
			continue;

		}

		if(pLetras[i] >= 'a' && pLetras[i] <= 'z'){

			//printf("\nb");
			continue;

		}
		if(pLetras[i] >= '0' && pLetras[i] <= '9'){

			//printf("\nc");
			continue;

		}
		if((pLetras[i] < '0' ) || ( pLetras[i] > '9' && pLetras[i] <'A')
				|| (pLetras[i]>'Z' && pLetras[i] <'a') ||( pLetras[i] >'z')){

			//printf("\nd");
			retorno= 0;
			break;

		}

	}


	return retorno;
}

/// @fn int utn_getString(char*, char*, char*, int, int)
/// @brief Solicita una cadena al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param longitud Es el tama�o del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int utn_getStringMayusculayMinuscula(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos){

	int retorno=-1;

	//printf("%d",longitud);
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud >0 && intentos>=0){

		//Creo la variable aca para primero validar de longitud sea mayor a 0
		char bufferString[longitud];

		do{

			printf("%s",mensaje);

			//Si esta todo bien lo copia en el puntero y sale de la iteracion retornado cero
			if(getStringLetras(bufferString,longitud)==0
					&& mayusculaMinuscula(bufferString,longitud)==0){

				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;

			}else if(intentos>0){

				printf("%s",mensajeError);

			}

			intentos--;


		}while(intentos>=0);


	}


	return retorno;

}

///\brief char*bufferString guarda cadena ingresada en mayuscula la primera letra
/// y minusculas las siguientes
///\param cadena Cadena de caracteres a ser analizada
///\return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
static int mayusculaMinuscula(char*bufferString, int len)
{
	int retorno= -1;
	char buffer[len];

	if(bufferString != NULL && len>0){

		strcpy(buffer,strlwr(bufferString));
		buffer[0]=bufferString[0]-32;
		strcpy(bufferString,buffer);


		retorno=0;

		}

	return retorno;

}



