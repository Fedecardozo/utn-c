
#include "generica.h"
static int getStringInt(int* pResultado, char*sEntero);
static int getStringFloat(float* pResultado,char* flotante);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena,int limite);

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getStringInt(int* pResultado, char*sEntero)
{
    int retorno=-1;
    char bufferString[20];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString);
		strncpy(sEntero,bufferString,sizeof(bufferString));

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
int input_getStringInt(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	char cadenaInt[20];

	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo < maximo && reintentos >=0){
		printf("%s",mensaje);
		do{


			if(	getStringInt(&bufferInt,cadenaInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				strncpy(pResultado, cadenaInt,sizeof(cadenaInt));
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
static int getStringFloat(float* pResultado,char* flotante)
{
    int retorno=-1;
    char bufferString[20];

	if(	pResultado != NULL && flotante != NULL &&
		myGets(bufferString,sizeof(bufferString)) == 0)

	{
		if(esFlotante(bufferString,sizeof(bufferString))){

			retorno=0;
			strncpy(flotante,bufferString,sizeof(bufferString));
			*pResultado = atof(bufferString);

		}

	}


    return retorno;
}

int input_getStringFloat(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	char cadenaFloat[20];

	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo < maximo && reintentos >=0){
		printf("%s",mensaje);
		do{


			if(	getStringFloat(&bufferFloat,cadenaFloat) == 0 &&
					bufferFloat > minimo && bufferFloat < maximo){


					retorno = 0;
					strncpy(pResultado, cadenaFloat,sizeof(cadenaFloat));

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
				printf("a");
				continue;
			}
			//si entra una vez esta bien. Si entra mas de una vez esta mal
			if((i!=0 && cadena[i]=='.') ||(bandera >= 1 && cadena[i]<'0') ){

				printf("b");
				bandera++;

			}
			//Si es mayor a 9 esta mal o si es menor a 0 y si la bandera es igual a cero
			//lo que significa que lo ingreso no es un punto y si ingreso mas de un '.' esta mal
			if(cadena[i] > '9' || (cadena[i] < '0' && bandera !=1))
			{
				printf("c");
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
		return retorno;
}
