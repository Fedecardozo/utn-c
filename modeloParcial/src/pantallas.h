
#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#include <stdio.h>
#include <stdlib.h>

#define LED 1
#define LCD 2

typedef struct{

	int id;
	int tipoPantalla;
	char nombre[];
	char direccion[];
	float precio;
	int isEmpty;


}Pantalla;


#endif /* PANTALLAS_H_ */
