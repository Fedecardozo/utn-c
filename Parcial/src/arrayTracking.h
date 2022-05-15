
#ifndef ARRAYTRACKING_H_
#define ARRAYTRACKING_H_

#include "RelacionProductosUsuarios.h"


#define LIBRE 1
#define OCUPADO 0

typedef struct{

	int idTracking;
	int idProducto;
	short int isEmpty;

	//AGREGAR RELACION
	int Fk_UsuarioComprador;
	int Fk_UsuarioVendedor;

	int cantidad;
	int distanciaKM;
	long int horaLlegada;



}Tracking;

int eTracking_Inicializar(Tracking *list, int len);
int eTracking_ObtenerIndexLibre(Tracking* list, int len);
int eTracking_BuscarPorid(Tracking *list, int len, int id);
int eTracking_PediUnDato(Tracking * list);
void eTracking_Estado(Tracking list);
int eTracking_MostrarTodos(Tracking *list, int len);

void harcodeoTracking(Tracking * listTracking,int lenTracking);

int eTracking_MostrarProductosUsuario(Tracking *list, int len,Usuario* arrayUsuario,int indiceUsuario);

int eTracking_CargarDatos(Tracking * listTracking,int lenTracking,Producto* arrayProducto,
		int indiceProducto,Usuario *listUsuario, int indiceUsuario,int cantidad);
int eTracking_Alta(Tracking* listTracking,int lenTracking,Tracking aDarseAlta);


#endif /* ARRAYTRACKING_H_ */
