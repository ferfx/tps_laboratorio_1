/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "input.h"
#define MAX 2000

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int id;
	int idSolicitud;
	int flagCarga;
	int r;
	int index;
	int orden;
	int opcionInforme;
	Passenger vectorP[MAX];
	Passenger p;




	flagCarga=0;
	id=1;
	initPassengers(vectorP,MAX);


	do{

		opcion=menu("\n MENU PRINCIPAL\n1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n5. CARGA FORZADA\n6. SALIR\n");

		switch(opcion){

		case 1:
			p=getPassenger();
			r=addPassenger(vectorP,MAX,id,p.name,p.lastName,p.price,p.typePassenger,p.flyCode);
			if(r==1){
				flagCarga=1;
				id++;
				printf("La carga se realizo correctamente. \n");

			}
			else{
				printf("No se pudo realizar la carga. \n");
			}
			break;

		case 2:
			if(flagCarga==1){
				idSolicitud=getInt("Ingrese el id del pasajero a modificar: \n");
				index=findPassengerById(vectorP,MAX,idSolicitud);
				if(index!=-1){
					modificar(vectorP,index);
				}
				else{
					printf("No se encontro el ID solicitado\n");
				}

			}
			else{
				printf("No hay datos disponibles para modificacion; \n");
			}

			break;

		case 3:
			if(flagCarga==1){
				printPassenger(vectorP,MAX);
				idSolicitud=getInt("\nIngrese el id del pasajero a eliminar: \n");
				r=removePassenger(vectorP,MAX,idSolicitud);
				if(r==0){
					printf("Pasajero elimiado correcamente.\n");
				}
				else{
					printf("No se puede eliminar al pasajero mediante este ID solicitado.\n");
				}
			}
			else{
				printf("No hay datos para borrar...\n");
			}
			break;

		case 4:
			if(flagCarga==1){

				do{
				opcionInforme=menu("\n1. LISTAR PASAJEROS POR CRITERIOS DE APELLIDO Y TIPO DE PASAJERO"
						"			\n2. TOTALES Y PROMEDIOS"
						"			\n3. LISTAR PASAJEROS POR CODIGO DE VUELVO Y ESTADO DE VUELO"
						"			\n4. SALIR DEL SUB-MENU\n");
				switch(opcionInforme){
				case 1:
					orden=validarOpcionCuatro();
					r=sortPassengersByName(vectorP,MAX,orden);
					if(r==0){
						r=printPassenger(vectorP,MAX);
						if(r==-1){
							printf("ERROR!");
						}
					}
					break;
				case 2:
					informeDos(vectorP,MAX);
					break;
				case 3:
					orden=validarOpcionCuatro();
					r=sortPassengersByCode(vectorP,MAX,orden);
					if(r==0){
						r=printPassenger(vectorP,MAX);
						if(r==-1){
							printf("ERROR!");
						}
					}
					break;
				case 4:
					printf("Volviendo al menu principal...\n");
					break;
				default:
					printf("Opcion incorrecta, vuelva a elegir:\n");
					break;
				}
				}while (opcionInforme!=4);

			}
			else{
				printf("No hay datos cargados para ordenar...\n");
			}




			break; // BREAK DEL CASE 4 DEL MENU PRINCIPAL.

		case 5:
			cargaForzada(vectorP,MAX,&id);
			flagCarga=1;
			printf("\n--> CARGA FORZADA COMPLETA <--\n");
			break;
		case 6:
			printf("El programa finalizo.\n");
			break;

		default:
			printf("Opcion incorrecta, vuelva a elegir\n");
		break;


		}





	}while(opcion!=6);







	return 0;
}
