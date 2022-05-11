
#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"

#define TAM 2

int main(void) {

	setbuf(stdout,NULL);

	Gen uno[TAM];

	Gen_Inicializar(uno, TAM);

	Gen_CargarDatos(uno, TAM);

	Gen_MostrarTodos(uno, TAM);


	return EXIT_SUCCESS;
}
