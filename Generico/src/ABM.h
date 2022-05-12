

#ifndef ABM_H_
#define ABM_H_

#include "utn.h"
#include "funcionesPropias.h"


#include <stdio.h>
#include <stdlib.h>

#define LIBRE 1
#define OCUPADO 0

typedef struct{

	int id;
	int isEmpty;

}General;


/** INICIO CABECERAS DE FUNCION*/
int eGen_Inicializar(General *list, int len);
int eGen_ObtenerIndexLibre(General *list, int len);
int eGen_BuscarPorid(General *list, int len, int id);
int eGen_PediUnDato(General * list);
void eGen_MostrarUno(General list);
int eGen_MostrarTodos(General *list, int len);
int eGen_MostrarDadosDeBaja(General *list, int len);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eGen_Sort(General *list, int len, int criterio);

//ABM
int eGen_CargarDatos(General * list,int len);
int eGen_ModificarUno(General *list,int len,int id);
int eGen_Alta(General *list, int len);
int eGen_Baja(General *list, int len);
int eGen_Modificacion(General *list, int len);
/** FIN CABECERAS DE FUNCION*/

#endif /* ABM_H_ */
