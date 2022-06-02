
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	FILE* fileArchivo;
	int num;

	//fopen() Abrir un archivo y lo guarda en un puntero FILE*
	/* MODOS
	 * "r" : Abre archivo para lectura. Debe existir.
	 * "w" : Abre archivo para escritura, crea uno nuevo si no existe o pisa si ya exista previamente uno
	 * "un": Abre archivo para escritura. Apendea. De no existir archivo lo crea.
	 * "r+": Abre archivo para escritura/lectura. Debe existir.
	 * "w+": Abre archivo lectura/escritura. Si no existe lo crea.
	 * "Wb": Modo binario
	 * "a+": Apendea.
	 */
	fileArchivo = fopen("archivo.txt","W");

	//Escribe en el archivo en modo texto
	fprintf(fileArchivo,"Holanda");

	num=127;
	//fileArchivo = fopen("archivo.txt","Wb");
	//Escribe en modo binario copiamos tal cual esta la variable en memoria al archivo
	fwrite(&num,sizeof(int),1,fileArchivo);

	//leer de un archivo en binario
	//fread();

	return EXIT_SUCCESS;
}
