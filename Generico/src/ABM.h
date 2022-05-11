

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

}Gen;


/** INICIO CABECERAS DE FUNCION*/
int Gen_Inicializar(Gen *list, int len);
int Gen_ObtenerIndexLibre(Gen *list, int len);
int Gen_BuscarPorid(Gen *list, int len, int id);
int Gen_PediUnDato(Gen * list);
void Gen_MostrarUno(Gen list);
int Gen_MostrarTodos(Gen *list, int len);
int Gen_MostrarDadosDeBaja(Gen *list, int len);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Gen_Sort(Gen *list, int len, int criterio);

//ABM
int Gen_CargarDatos(Gen * list,int len);
int Gen_ModificarUno(Gen *list,int len,int id);
int Gen_Alta(Gen *list, int len);
int Gen_Baja(Gen *list, int len);
int Gen_Modificacion(Gen *list, int len);
/** FIN CABECERAS DE FUNCION*/

#endif /* ABM_H_ */
