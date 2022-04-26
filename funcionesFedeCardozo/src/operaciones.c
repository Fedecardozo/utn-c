
#include "operaciones.h"

int suma_Int(int *resultado,int x, int y){

	int retorno =-1;

	if(resultado != NULL){

		*resultado = x + y;
		retorno =0;
	}
	return retorno;

}
int resta_Int(int *resultado,int x, int y){

	int retorno =-1;

	if(resultado != NULL){

		*resultado = x - y;
		retorno =0;
	}

	return retorno;


}
int division(float *resultado,float x, float y){

	int retorno =-1;

		if(resultado != NULL && y !=0){

			*resultado = x / y;
			retorno =0;
		}


		return retorno;


}
int multipliacion_Int(int *resultado,int x, int y){

	int retorno =-1;

	if(resultado != NULL){

		*resultado = x * y;
		retorno =0;
	}


	return retorno;

}

int suma_Float(float *resultado,float x, float y){

	int retorno =-1;

	if(resultado != NULL){

		*resultado = x + y;
		retorno =0;
	}


	return retorno;


}
int resta_Float(float *resultado,float x, float y){


	int retorno =-1;

	if(resultado != NULL){

		*resultado = x - y;
		retorno =0;
	}


	return retorno;

}
int multipliacion_Float(float *resultado,float x, float y){

	int retorno =-1;

	if(resultado != NULL){

		*resultado = x * y;
		retorno =0;
	}


	return retorno;


}


