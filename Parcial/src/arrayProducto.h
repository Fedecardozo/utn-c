
#ifndef ARRAYPRODUCTO_H_
#define ARRAYPRODUCTO_H_

#include "utn.h"
#include "funcionesPropias.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 20

#define LIBRE 1
#define OCUPADO 0

typedef struct{

	int id;
	int isEmpty;

	//RELACION
	int Fk_idUsuario;

	char nombreProducto[MAX_NOMBRE];
	float precio;
	int categoria; //Ej moda,tecnologia....
	int stock; // cantidad de productos a vender


}Producto;

/** INICIO CABECERAS DE FUNCION*/
int eProducto_Inicializar(Producto *list, int len);
int eProducto_ObtenerIndexLibre(Producto *list, int len);
int eProducto_BuscarPorid(Producto *list, int len, int id);
int eProducto_PediUnDato(Producto * list);
void eProducto_MostrarUno(Producto list);
int eProducto_MostrarTodos(Producto *list, int len);
int eProducto_MostrarDadosDeBaja(Producto *list, int len);

//SORT
int eProducto_Sort(Producto *list, int len, int criterio);

//ABM
int eProducto_CargarDatos(Producto * list,int len);
int eProducto_ModificarUno(Producto *list,int len,int id);
int eProducto_Alta(Producto *list, int len,Producto productoDarAlta);
int eProducto_Baja(Producto *list, int len);
int eProducto_Modificacion(Producto *list, int len);


#endif /* ARRAYPRODUCTO_H_ */
