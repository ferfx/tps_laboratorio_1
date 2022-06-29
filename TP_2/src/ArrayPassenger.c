#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "input.h"

int menu(char opciones[])
{
	int opcion;
	printf("%s",opciones);

	opcion=getInt("Ingrese la opcion:\n");
	return opcion;
}

int initPassengers(Passenger list[], int len){
	int i;
	for (i=0;i<len;i++){
		list[i].isEmpty=1;
	}
	return 1;
}

Passenger getPassenger(){
	Passenger p;
	getString(p.name,"Ingrese el nombre: \n",51);
	getString(p.lastName,"Ingrese el Apellido: \n",51);
	p.price=getFloat("Ingrese el precio: \n");
	getString(p.flyCode,"Ingrese el codigo de Vuelo: \n",10);
	return p;
}

void hardcodeFlights(eFlight vector[]){
	int i;
	char tipo[][51]={"INACTIVO","ACTIVO"};

	for (i=0;i<2;i++){
		vector[i].id=i;
		strcpy(vector[i].dStatusFlight,tipo[i]);
	}
}

void harcodeTypes(eType vector[]){
	int i;
	char tipo[][51]={"SEGUNDA CLASE","PRIMERA CLASE"};

	for (i=0;i<2;i++){
		vector[i].id=i;
		strcpy(vector[i].dTypePassenger,tipo[i]);
	}
}

int buscarEspacioLibre(Passenger vector[],int tam)
{
	int i;
	int indiceLibre;

	indiceLibre=-1;

	for (i=0;i<tam;i++){
		if(vector[i].isEmpty==1){
			indiceLibre=i;
			break;
		}
	}
	return indiceLibre;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]){

	int pos;
	int retorno=-1;
	int opcion;

	pos=buscarEspacioLibre(list,len);
	if(pos!=-1){
		list[pos].id=id;
		strcpy(list[pos].name,name);
		strcpy(list[pos].lastName,lastName);
		list[pos].price=price;
		list[pos].typePassenger=typePassenger;
		strcpy(list[pos].flyCode,flycode);
		list[pos].isEmpty=0;
		retorno=1;

		printf("Especifique el estado de vuelo: \n");
		opcion=getInt("Presione:\n 1 para 'ACTIVO' //  0 para 'INACTIVO' \n");
		while (opcion!=1 && opcion!=0){
			opcion=getInt("Error, Presione:\n 1 para 'ACTIVO' //  0 para 'INACTIVO' \n");
		}

		list[pos].idStatusFlight=opcion;


		printf("Especifique tipo de pasajero: \n");
		opcion=getInt("Presione:\n 1 para 'PRIMERA CLASE' //  0 para 'SEGUNDA CLASE' \n");
		while (opcion!=1 && opcion!=0){
			opcion=getInt("Error, Presione:\n 1 para 'PRIMERA CLASE' //  0 para 'SEGUNDA CLASE' \n");
		}

		list[pos].typePassenger=opcion;

	}


	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno=-1;
	int i;

	for(i=0;i<len;i++){
		if((id==list[i].id)&&list!=NULL&&list[i].isEmpty==0){
			retorno=i;
			break;
		}
	}

	return retorno;
}

void modificar(Passenger* list, int index){
	int opcion;
	int opcionDos;

	opcion=menu("\n MENU MODIFICACION:\n1. NOMBRE\n2. APELLIDO\n3. PRECIO\n4. TIPO DE PASAJERO\n5. CODIGO DE VUELVO\n6. SALIR\n");
	switch(opcion){

	case 1:
		getString(list[index].name,"Ingrese el nuevo nombre: \n",51);
		break;

	case 2:
		getString(list[index].lastName,"Ingrese el nuevo apellido: \n",51);
		break;

	case 3:
		list[index].price=getFloat("Ingrese el nuevo precio: \n");
		break;

	case 4:
		printf("Especifique tipo de pasajero: \n");
		opcionDos=getInt("Presione:\n 1 para 'PRIMERA CLASE' //  0 para 'SEGUNDA CLASE' \n");
		while (opcionDos!=1 && opcionDos!=0){
			opcionDos=getInt("Error, Presione:\n 1 para 'PRIMERA CLASE' //  0 para 'SEGUNDA CLASE' \n");
		}
		list[index].typePassenger=opcionDos;
		break;

	case 5:
		getString(list[index].flyCode,"Ingrese el nuevo codigo de Vuelo: \n",10);
		break;
	case 6:
		printf("Saliendo del menu modificacion...\n");
		break;

	default:
		printf("Opcion incorrecta, vuelva a elegir:\n");
		break;

	}
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int index;

	index=findPassengerById(list,len,id);
	if(index!=-1){
		list[index].isEmpty=1;
		retorno=0;
	}

	return retorno;
}

int validarOpcionCuatro()
{
	int opcion;

	opcion=menu("\n1. INGRESE 1 PARA INFORMAR DE MANERA ASCENDENTE "
			  "	\n2. INGRESE 0 PARA INFORMAR DE MANERA DESCENDENTE\n");
	while(opcion!=1&&opcion!=0){
		opcion=menu("\n1. INGRESE 1 PARA INFORMAR DE MANERA ASCENDENTE "
					"\n2. INGRESE 0 PARA INFORMAR DE MANERA DESCENDENTE\n");
	}
	return opcion;
}

int sortPassengersByName(Passenger* list, int len, int order)
{
	int i;
	int j;
	int retorno=-1;
	Passenger aux;

	if(order==1 && list!=NULL){ // ASCENDENTE



		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if((stricmp(list[i].lastName,list[j].lastName)<0) && list[i].isEmpty==0 && list[j].isEmpty==0 && list!=NULL)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else{
					if((stricmp(list[i].lastName,list[j].lastName)==0)&&list!=NULL){
						if((list[i].typePassenger<list[j].typePassenger)&&list!=NULL){
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}

				}
			}
		}

		retorno=0;

	}

	else{
		if(list!=NULL){ // DESCENDENTE
			for(i=0;i<len-1;i++)
					{
						for(j=i+1;j<len;j++)
						{
							if((stricmp(list[i].lastName,list[j].lastName)>0) && list[i].isEmpty==0 && list[j].isEmpty==0 && list!=NULL)
							{
								aux=list[i];
								list[i]=list[j];
								list[j]=aux;
							}
							else{
								if((stricmp(list[i].lastName,list[j].lastName)==0)&&list!=NULL){
									if((list[i].typePassenger>list[j].typePassenger)&&list!=NULL){
										aux=list[i];
										list[i]=list[j];
										list[j]=aux;
									}
								}

							}
						}
					}

			retorno=0;
		}



	}
	return retorno;
}


int printPassenger(Passenger* list, int length)
{
	int retorno=0;
	int i;
	eFlight VF[2];
	eType VT[2];

	hardcodeFlights(VF); //Estructura donde relaciono id con los estados de vuelo.
	harcodeTypes(VT);    //Estructura donde relaciono id con los tipos de pasajeros.




	if(list!=NULL){
		printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s\n", -3, "ID", -16, "NAME", -16, "LASTNAME", -10, "PRICE", -12, "FLYCODE", -12, "STATUSFLIGHT", -12, "TYPEPASSENGER");
		printf("%*c | %*c | %*c | %*c | %*c | %*c | %*c\n", -3, '-', -16, '-', -16, '-', -10, '-', -12, '-', -12, '-', -12, '-');
		for(i=0;i<length;i++){
			if(list[i].isEmpty==0){
				printf("%*d | %*s | %*s | %*.2f | %*s | %*s | %*s\n", -3, list[i].id, -16, list[i].name, -16, list[i].lastName, -10, list[i].price, -12, list[i].flyCode, -12, VF[list[i].idStatusFlight].dStatusFlight,-12, VT[list[i].typePassenger].dTypePassenger);
			}
		}
	}
	else{
		retorno=-1;
	}

	return retorno;
}

void informeDos(Passenger* list, int len){
	int i,cantPasajeros,cont;
	float tot,prom;
	tot=0; cantPasajeros=0; cont=0;

	if(list!=NULL){
		for(i=0;i<len;i++){
			if(list[i].isEmpty==0){
				tot+=list[i].price;
				cont++;
			}
		}
	}


	printf("-------------------------------------------------------------\n");
	printf("El total del precio de los pasajes es $%.2f\n",tot);
	if(cont>0){
		prom=tot/cont;
		printf("El promedio de precio de los pasajes es $%.2f\n",prom);
	}
	else{
		printf("El promedio de precio de los pasajes es $0");
	}

	for(i=0;i<len;i++){
		if(list[i].isEmpty==0){
			if(list[i].price>prom){
				cantPasajeros++;
			}
		}
	}

	printf("La cantidad de pasajeros que superan el precio promedio es %d\n",cantPasajeros);
	printf("-------------------------------------------------------------\n");

}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	int retorno=-1;
	Passenger aux;

	if(order==1 && list!=NULL){ // ASCENDENTE



		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if((stricmp(list[i].flyCode,list[j].flyCode)<0) && list[i].isEmpty==0 && list[j].isEmpty==0 && list!=NULL)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else{
					if((stricmp(list[i].flyCode,list[j].flyCode)==0)&&list!=NULL){
						if((list[i].idStatusFlight<list[j].idStatusFlight)&&list!=NULL){
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}

				}
			}
		}

		retorno=0;

	}

	else{
		if(list!=NULL){ // DESCENDENTE
			for(i=0;i<len-1;i++)
					{
						for(j=i+1;j<len;j++)
						{
							if((stricmp(list[i].flyCode,list[j].flyCode)>0) && list[i].isEmpty==0 && list[j].isEmpty==0 && list!=NULL)
							{
								aux=list[i];
								list[i]=list[j];
								list[j]=aux;
							}
							else{
								if((stricmp(list[i].flyCode,list[j].flyCode)==0)&&list!=NULL){
									if((list[i].idStatusFlight>list[j].idStatusFlight)&&list!=NULL){
										aux=list[i];
										list[i]=list[j];
										list[j]=aux;
									}
								}

							}
						}
					}

			retorno=0;
		}



	}
	return retorno;
}


void cargaForzada(Passenger* list, int len, int* id){
	int indice;

	indice=buscarEspacioLibre(list,len);
	if (indice!=-1 && list[indice].isEmpty==1){
		strcpy(list[indice].flyCode,"JAS213");
		strcpy(list[indice].lastName,"Adan");
		strcpy(list[indice].name,"Damian");
		list[indice].id=(*id);
		(*id)++;
		list[indice].idStatusFlight=1;
		list[indice].isEmpty=0;
		list[indice].price=250;
		list[indice].typePassenger=0;

	}

	indice=buscarEspacioLibre(list,len);
	if (indice!=-1 && list[indice].isEmpty==1){
		strcpy(list[indice].flyCode,"XMK555");
		strcpy(list[indice].lastName,"Blasi");
		strcpy(list[indice].name,"Belen");
		list[indice].id=(*id);
		(*id)++;
		list[indice].idStatusFlight=1;
		list[indice].isEmpty=0;
		list[indice].price=55.60;
		list[indice].typePassenger=0;

	}

	indice=buscarEspacioLibre(list,len);
	if (indice!=-1 && list[indice].isEmpty==1){
		strcpy(list[indice].flyCode,"LTQ782");
		strcpy(list[indice].lastName,"Ovelar");
		strcpy(list[indice].name,"Dario");
		list[indice].id=(*id);
		(*id)++;
		list[indice].idStatusFlight=0;
		list[indice].isEmpty=0;
		list[indice].price=560.80;
		list[indice].typePassenger=1;

	}
}


