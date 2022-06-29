/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: fx
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char dStatusFlight[51];
}eFlight;

typedef struct{
	int id;
	char dTypePassenger[51];
}eType;

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int idStatusFlight;
	int typePassenger;
	int isEmpty;
}Passenger;


int menu( char opciones[]);

void hardcodeFlights(eFlight vector[]);
void harcodeTypes(eType vector[]);

int initPassengers(Passenger list[], int len);

Passenger getPassenger();

int buscarEspacioLibre(Passenger vector[],int tam);

//void loadFlights(eFlight* Vector, int len,char flycode[], int id);

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

int findPassengerById(Passenger* list, int len,int id);

void modificar(Passenger* list, int index);

int removePassenger(Passenger* list, int len, int id);

int sortPassengersByName(Passenger* list, int len, int order);

int validarOpcionCuatro();

int printPassenger(Passenger* list, int length);

void informeDos(Passenger* list, int len);

int sortPassengersByCode(Passenger* list, int len, int order);

void cargaForzada(Passenger* list, int len, int* id);







#endif /* ARRAYPASSENGER_H_ */
