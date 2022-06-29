#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"


Passenger* Passenger_new()
{
    Passenger* pasajero;
    pasajero =(Passenger*)malloc(sizeof(Passenger));
    {
        pasajero->id=0;
        strcpy(pasajero->nombre,"");
        strcpy(pasajero->apellido,"");
        pasajero->precio=0;

    }
    return pasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastnameStr, char* precioStr, char* flyCodeStr, char* tipoStr, char* estadoVueloStr){

	Passenger* pasajero;
	pasajero=Passenger_new();

	if(pasajero!=NULL){
		Passenger_setId(pasajero,atoi(idStr));
		Passenger_setNombre(pasajero,nameStr);
		Passenger_setApellido(pasajero,lastnameStr);
		Passenger_setCodigoVuelo(pasajero,flyCodeStr);
		Passenger_setTipoPasajero(pasajero,tipoStr);
		Passenger_setEstadoVuelvo(pasajero,estadoVueloStr);
		Passenger_setPrecio(pasajero,atof(precioStr));

	}

	return pasajero;

}

int Passenger_setId(Passenger* this,int id){
	int retorno=-1;
	if (this!=NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char *name){
	int retorno=-1;
	if(this!=NULL){
		strcpy(this->nombre,name);
		retorno=0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char *lastName){
	int retorno=-1;
	if(this!=NULL){
		strcpy(this->apellido,lastName);
		retorno=0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* flyCode){
	int retorno=-1;
	if(this!=NULL){
		strcpy(this->codigoVuelo,flyCode);
		retorno=0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipo){
	int retorno=-1;
	if (this!=NULL){
		strcpy(this->tipoPasajero,tipo);
		retorno=0;
	}
	return retorno;
}

int Passenger_setEstadoVuelvo(Passenger* this,char* estadoVuelo){
	int retorno=-1;
	if(this!=NULL){
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno=-1;
	if(this!=NULL){
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}


void imprimePasajero(Passenger* this){
	int auxId;
	char auxApellido[50];
	char auxNombre[50];
	float auxPrecio;
	char auxTipo[50];
	char auxFc[50];
	char auxEv[50];

	if (this!=NULL){
		if((Passenger_getId(this,&auxId)==0 && Passenger_getNombre(this,auxNombre)==0
			&& Passenger_getApellido(this,auxApellido)==0 && Passenger_getPrecio(this,&auxPrecio)==0
			&& Passenger_getCodigoVuelo(this,auxFc)==0 && Passenger_getTipoPasajero(this,auxTipo)==0
			&& Passenger_getEstadoVuelo(this,auxEv)==0)){

			printf("%d,%s,%s,%f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);


		}
	}

}

int Passenger_getId(Passenger* this,int* id){
	int retorno=-1;
	if(this!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL){
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this!=NULL){
		strcpy(apellido,this->apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this!=NULL){
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno=-1;
	if(this!=NULL){
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno=-1;
	if(this!=NULL){
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estado){
	int retorno=-1;
	if(this!=NULL){
		strcpy(estado,this->estadoVuelo);
		retorno=0;
	}
	return retorno;
}


int Passenger_altaPasajero(LinkedList* this){
	int retorno=-1;
	Passenger* pasajero;
	char auxId[50];
	float auxPrecio[50];

	int id;
	int precio;
	char nombre[50];
	char apellido[50];
	char estadoVuelo[50];
	char flyCode[50];
	char tipo[50];

	if(this!=NULL){
		id=getInt("Ingrese un id:");
		precio=getFloat("Ingrese precio:");
		getString(nombre,"Ingrese un nombre:",50);
		getString(apellido,"Ingrese un apellido:",50);
		getString(estadoVuelo,"Ingrese estado de vuelo:",50);
		getString(flyCode,"Ingrese codigo de vuelo:",50);
		getString(tipo,"Ingrese el tipo de pasajero:",50);

		sprintf(auxId,"%d",id);
		sprintf(auxPrecio,"f",precio);






	}










	return retorno;
}














