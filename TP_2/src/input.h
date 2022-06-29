/*
 * input.h
 *
 *  Created on: 14 may. 2022
 *      Author: fx
 */

#ifndef INPUT_H_
#define INPUT_H_


/**
 * Funciones para validar que sea solo un numero entero y que no rompa al ingresar caracteres
 * @param Mensaje para ingresar una opcion
 * @return Retorna el numero entero
 */
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
int esNumerica(char auxiliar[]);
int esFlotante(char auxiliar[]);
void getString(char palabra[],char mensaje[],int tamanio);







#endif /* INPUT_H_ */
