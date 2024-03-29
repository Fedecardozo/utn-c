/*
 * utn.h
 *
 *  Created on: Apr 6, 2020
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int myGets(char* cadena, int longitud);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos);
int utn_getStringLetras(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos);
int utn_getStringLetrasYnumeros(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos);
int utn_getStringMayusculayMinuscula(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos);
int utn_getStringLetrasYnumerosLimite(char* pResultado, char* mensaje, char* mensajeError,int limite, int intentos);

#endif /* UTN_H_ */
