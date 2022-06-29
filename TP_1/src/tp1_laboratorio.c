/*
 ============================================================================
 Name        : tp1_laboratorio.c
 Author      : Ovelar, Dario Fernando, Division 1k
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "muestreo.h"
#include "input.h"




int main(void) {
	setbuf(stdout,NULL);

	float kilometros;
	float precioLatam;
	float precioAerolineas;
	float precioAerolineasDebito;
	float precioLatamDebito;
	float precioAerolineasCredito;
	float precioLatamCredito;
	float precioAerolineasBtc;
	float precioLatamBtc;
	float precioAerolineasUnitario;
	float precioLatamUnitario;
	float diferenciaDePrecio;


	int opcion;
	int banderaDeCarga;
	int banderaKm;
	int banderaResultados;

	banderaResultados=0;
	banderaDeCarga=0;
	banderaKm=0;



	 // Esta funcion toma y valida una opcion del 1 al 6.



    do{
    	printf("\nKilometros Actuales: %2.f\n",kilometros);
    	printf("Precio Latam Actual: %2.f\n",precioLatam);
    	printf("Precio Aerolineas Actual: %2.f",precioAerolineas);
    	opcion=tomarOpcion();

		switch(opcion){

			case 1:

				kilometros=pedirValorPositivo("Ingrese la cantidad de kilometros:"); // Con esta funcion pido y valido numeros flotantes usados para los km o precios.
				banderaKm=1; // esta bandera me asegura que hayan kms cargados, asi no tocan la opcion 2 al pricipio, cargando precios sin kms previos.

			break;

			case 2:
				if(banderaKm==1){

					precioAerolineas=pedirValorPositivo("Ingrese el precio con Aerolineas Argentinas: ");

					precioLatam=pedirValorPositivo("Ingrese el precio con Latam: ");
					banderaDeCarga=1; // Me aseguro de tener precios cargados, asi no voy a la opcion 4 sin datos

				}
				else{
					printf("NO HAY KILOMETROS CARGADOS\n");
					system("pause");
				}

			break;

			case 3:
				if (banderaDeCarga==1 && banderaKm==1){
					precioAerolineasDebito=descuentoDebito(precioAerolineas);
					precioLatamDebito=descuentoDebito(precioLatam);
					precioAerolineasCredito=interesCredito(precioAerolineas);
					precioLatamCredito=interesCredito(precioLatam);
					precioAerolineasBtc=precioBitcoin(precioAerolineas);
					precioLatamBtc=precioBitcoin(precioLatam);
					precioAerolineasUnitario=precioUnitario(precioAerolineas,kilometros);
					precioLatamUnitario=precioUnitario(precioLatam,kilometros);
					diferenciaDePrecio=diferencia(precioAerolineas,precioLatam);
					banderaResultados=1;
					printf("RESULTADOS CARGADOS.\n");
					system("pause");



				}

				else{
					printf("NO HAY DATOS CARGADOS\n");
					system("pause");

				}
			break;

			case 4:
				if(banderaResultados==1){
					printf("KMs ingresados: %.2f kms\n\n",kilometros);
					printf("Precio Aerolineas: %.2f\n",precioAerolineas);
					mostrar(precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBtc,precioAerolineasUnitario);
					printf("Precio latam: %.2f\n",precioLatam);
					mostrar(precioLatamDebito,precioLatamCredito,precioLatamBtc,precioLatamUnitario);
					printf("La diferencia de precio es: $ %.2f \n\n",diferenciaDePrecio);
					system("pause");
				}
				else{
					printf("NO HAY RESULTADOS CARGADOS. \n");
					system("pause");
				}


			break;

			case 5:
				kilometros=7090;
			    precioAerolineas=162965;
			    precioLatam=159339;
			    banderaDeCarga=1;
			    banderaKm=1;
			    printf("\nCARGA DE DATOS FORAZADA COMPLETA.\n");
			    system("pause");
			break;



			case 6:
				printf("Saliendo del programa.\n");
			break;

			default:
				printf("Opcion incorrecta, vuelva a elegir:\n");
			break;



		}
	}while(opcion!=6);


	printf("\nEl programa finalizo.\n");





	return EXIT_SUCCESS;
}

