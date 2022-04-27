
#include "producto.h"

static int imprimirProducto(Producto pr);
static int pedirDatos();

int imprimirArrayProducto(int tam, Producto* pr){

	int retorno = 1;
	int i;

	if(pr != NULL && tam>0){


		for (i = 0; i <tam ; i++) {

			if(pr[i].isEmpty==0){

				imprimirProducto(pr[i]);

			}

		}


	}

	return retorno;

}

int inicializar(Producto* pr,int tam){

	int i;
	int retorno=-1;

	if(pr!=NULL && tam >0){

		for (i = 0; i <tam ; i++) {

			pr[i].isEmpty=1;
			retorno=0;

		}

	}

 	 return retorno;

}

static int imprimirProducto(Producto pr){


	printf("\nId:%d \nNombre:%s \nDescripcion: %s  \nPrecio:%f",pr.id,pr.nombre,pr.descripcion,pr.precio);

	return 1;
}

//3) Realizar una funcion que reciba el array, un indice, y le permita al usuario
//cargar los datos en el item de la posicion especificada por el indice.
static float num;
static char des[200];
static char nombre[20];
static int id=1000;
static int pedirDatos(){

	printf("\nIngrese el nombre: ");
	myGets(nombre, sizeof(nombre));

	printf("\nIngrese la descripcion: ");
	myGets(des, sizeof(des));
	utn_getNumeroFlotante(&num,"\nIngrese el precio: " , "\nError: ", 0, 12000, 2);
	id++;
	return 0;

}

int cargarDatos(Producto* pr,int indice){

	int retorno =-1;

	if(pr != NULL){

		pedirDatos();
		pr[indice].id=id;
		strcpy( pr[indice].nombre, nombre);
		strcpy( pr[indice].descripcion, des);
		pr[indice].precio=num;
		pr[indice].isEmpty=0;

		retorno =0;

	}


	return retorno;

}
//4) Realizar una funcion que reciba el array y un indice e
//imprima los datos del item de la posicion especificada por el indice.
int imprimirIndice(Producto* pr,int indice){

	int retorno = -1;

	if(pr != NULL && indice>=0 && pr[indice].isEmpty==0){

		imprimirProducto(pr[indice]);
		retorno =0;
	}

	return retorno;

}

//5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar)
int indiceVacio(Producto* pr, int tam,int* indice){

	int retorno =-1;
	int i;

	if(pr != NULL && tam >0){


		for (i = 0; i < tam; i++) {

			if(pr[i].isEmpty == 1){

				*indice = i;
				retorno = 0;
				break;

			}

		}


	}


	return retorno;

}

/*4) Agregar al tipo de dato el campo ID que represente un identificador unico.
	Modificar el codigo anterior para que el ID se genere automaticamente.
	Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.
*/


