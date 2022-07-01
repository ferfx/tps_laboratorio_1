#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int option;
	int idG=1;
	int contadorCarga=0;


	LinkedList *listaPasajeros = ll_newLinkedList();

	do {

		option =getInt("\n MENU:\n"
						"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
						"3. Alta de pasajero\n"
						"4. Modificar datos de pasajero\n"
						"5. Baja de pasajero\n"
						"6. Listar pasajeros\n"
						"7. Ordenar pasajeros\n"
						"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
						"10. Salir\n");
		switch (option) {
		case 1:
			controller_loadFromText("data.csv",listaPasajeros,&idG);
			break;
		case 2:
			controller_loadFromBinary("data.bin",listaPasajeros,&idG);
			break;
		case 3:
			if(!controller_addPassenger(listaPasajeros,&idG)){
				contadorCarga++;
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			if(contadorCarga){
				controller_ListPassenger(listaPasajeros);
			}else
				printf("\nNO HAY DATOS CARGADOS\n");
			system("pause");

			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			printf("El programa finalizo.\n");
			break;
		default:
			break;

		}
	} while (option != 10);

	return 0;
}
