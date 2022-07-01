#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int* idG)
{
    Passenger* pasajero;;
    int retorno=-1;
    int r;
    int auxId;
    char idStr[50];
    char auxApellido[50];
    char auxNombre[50];
    char auxPrecio[50];
    char auxTipo[50];
    char auxFc[50];
    char auxEv[50];
    int contId=0;

    //pasajero = Passenger_new();

    if(pFile!=NULL && pArrayListPassenger!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);

        do
        {
        	r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);
            if(r==7)
            {
            	auxId=atoi(auxId);
            	auxId+=idG;
            	sprintf(idStr,"%d",auxId);


                pasajero=Passenger_newParametros(idStr,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);

                if(pasajero!=NULL)
                {
                    ll_add(pArrayListPassenger,pasajero);
                    contId++;
                    retorno=0;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));
        idG=idG+contId;
    }
    return retorno;
}
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int* idG)
{
    Passenger* pasajero;
    int retorno=-1;
    int cant;
    int contId=0;

    if(pFile!=NULL && pArrayListPassenger!=NULL)
    {
        do
        {
            pasajero=Passenger_new();
            Passenger_setId(pasajero,idG);

            cant=fread(pasajero,sizeof(Passenger),1,pFile);
            if(pasajero!=NULL && cant==1)
            {
                ll_add(pArrayListPassenger,pasajero);
                retorno=0;
                contId++;
            }
        }
        while(!feof(pFile));
        idG+=contId;
    }
    return retorno;
}
