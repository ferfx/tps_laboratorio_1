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
	int continuar;
	int banderaKm;
	int decision;
	int banderaResultados;

	banderaResultados=0;
	banderaDeCarga=0;
	banderaKm=0;
	continuar=1;


	opcion=tomarOpcion(); // Esta funcion toma y valida una opcion del 1 al 6.



    while(continuar==1){
		switch(opcion){

			case 1:
				printf("Ingrese la cantidad de kilometros: ");
				kilometros=pedirValorPositivo(); // Con esta funcion pido y valido numeros flotantes usados para los km o precios.
				banderaKm=1; // esta bandera me asegura que hayan kms cargados, asi no tocan la opcion 2 al pricipio, cargando precios sin kms previos.
				opcion=2; // luego de la carga de kilometros, fuerzo a ir a la opcion 2 para no pisar los kilometros con otros nuevos.
			break;

			case 2:
				if(banderaKm==1){
					printf("Ingrese el precio con Aerolineas Argentinas: ");
					precioAerolineas=pedirValorPositivo();
					printf("Ingrese el precio con Latam: ");
					precioLatam=pedirValorPositivo();
					banderaDeCarga=1; // Me aseguro de tener precios cargados, asi no voy a la opcion 4 sin datos
					opcion=3; // Fuerzo ir a la opcion de 3 de calculos sabiendo que ya tengo datos cargados
				}
				else{
					printf("No hay Kilometros cargados, reiniciando el programa...\n");
					opcion=6; // Al no haber kms cargados, doy la opcion de reiniciar el programa o finalizarlo.
				}

			break;

			case 3:
				if (banderaDeCarga==1){
					printf("Cargandose todos los resultados...\n\n");
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
					opcion=4; // al estar seguro de la carga, voy a la opcion 4 para informar los resultados


				}

				else{
					printf("No hay datos cargados, reiniciando el programa...\n");
					opcion=6; // Al no haber datos, voy a la opcion 6 que doy la chance de reiniciar o finalizar.
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
					opcion=6; // Una vez informado los resultados, doy la opcion de volver a cargar nuevos vuelos o finalizar el programa.
				}
				else{
					printf("No hay datos cargados, reiniciando el programa...\n");
					opcion=6; // Al no haber carga de datos, doy la opcion de reiniciar el programa o finalizarlo.
				}
			break;

			case 5:
				kilometros=7090;
			    precioAerolineas=162965;
			    precioLatam=159339;
			    banderaDeCarga=1;
			    opcion=3; // Al ser datos forzados, voy a la opcion 3 que me permite calcular
			break;



			case 6:
				printf("Quiere volver a cargar datos de vuelo, ingrese '1' para continuar o '0' para finalizar\n");
				scanf("%d",&decision);
				while (decision!=1 && decision!=0){ // validacion de la decision
					printf("Opcion incorrecta, vuelva a ingresar '1' o '0'\n");
					scanf("%d",&decision);
				}
				if(decision==1){ // Si el usuario decide continuar, le consulto si quiere cargar un nuevo viaje u otro con datos forzados.
					banderaKm=0;
					banderaDeCarga=0;
					printf("Para un Nuevo Viaje ingrese: 1, para Datos Forzados ingrese: 5\n");
					scanf("%d",&opcion);
					while(opcion!=1 && opcion!=5){ // validacion de la opcion
						printf("Vuelva a ingresar una opcion 1 o 5\n");
						scanf("%d",&opcion); // Desde aca voy a la opcion 1 o la 5 directamente con el numero tomado desde teclado.
					}

				}
				else{
					continuar=0;  // Si el usuario quiere simplemente finalizar el programa, con esto corto el bucle del while.
				}
			break;



		}
	}
	printf("El programa finalizo");





	return EXIT_SUCCESS;
}
