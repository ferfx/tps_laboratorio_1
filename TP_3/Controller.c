#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "input.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int* idG)
{
    int retorno=-1;
    FILE* archivo;

    if(path!=NULL && pArrayListPassenger!=NULL){
    	archivo=fopen(path,"r");
    	if (archivo!=NULL){
    		if(parser_PassengerFromText(archivo,pArrayListPassenger,&idG)==0){
    			printf("\n---> CARGA EXITOSA <---\n");
    			retorno=0;
    		}
    	}
    	else{
    		printf("ERROR!\n");
    	}
    }
    else{
    	printf("ERROR!\n");
    }

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger,int* idG)
{
    int retorno=-1;
    int r;
    FILE* archivoBin;
    archivoBin=fopen(path,"rb");

    if(archivoBin==NULL && pArrayListPassenger==NULL)
    {
        printf("NO EXISTE EL ARCHIVO\n");
    }
    else
    {
        r=parser_PassengerFromBinary(archivoBin,pArrayListPassenger,&idG);
        if(r==0)
        {
            retorno=0;
            printf("CARGA EXITOSA.\n");
        }
        else
        {
            printf("ERROR!\n");
        }

    }
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* idG)
{
    int retorno=-1;

    if(pArrayListPassenger!=NULL)
    {
        if(Passenger_altaPasajero(pArrayListPassenger,&idG)==0)
        {
            retorno=0;
            printf("CARGA EXITOSA!\n");
            system("pause");
        }
        else
        {
            printf("ERROR AL CARGAR!\n");
            system("pause");
        }
    }
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pasajero;
	int i,len;
	if (pArrayListPassenger!=NULL){
		len=ll_len(pArrayListPassenger);
		printf("ID - NAME  - LASTNAME - PRICE - FLYCODE - TYPEPASSENGER - STATUSFLIGHT\n");
		for (i=0;i<len;i++){
			pasajero=ll_get(pArrayListPassenger,i);
			if(pasajero!=NULL){
				imprimePasajero(pasajero);
				retorno=0;
			}

		}

	}


	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

