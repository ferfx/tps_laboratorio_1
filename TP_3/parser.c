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
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
    Passenger* pasajero;;
    int retorno=-1;
    int r;
    char auxId[50];
    char auxApellido[50];
    char auxNombre[50];
    char auxPrecio[50];
    char auxTipo[50];
    char auxFc[50];
    char auxEv[50];

    //pasajero = Passenger_new();

    if(pFile!=NULL && pArrayListPassenger!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);

        do
        {
        	r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);
            if(r==7)
            {
                pasajero=Passenger_newParametros(auxId,auxNombre,auxApellido,auxPrecio,auxFc,auxTipo,auxEv);

                if(pasajero!=NULL)
                {
                    ll_add(pArrayListPassenger,pasajero);
                    retorno=0;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));

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
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
