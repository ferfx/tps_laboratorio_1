
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

float pedirValorPositivo(char mensaje[]){
	float valor;

	valor=getFloat(mensaje);
	while(valor<1){
		printf("Valor incorrecto, vuelva a ingresar: ");
		valor=getFloat(mensaje);
	}

	return valor;
}

float descuentoDebito(float precio){
	float valor;
	valor=(precio-(precio*0.1));
	return valor;
}

float interesCredito(float precio){
	float valor;
	valor=(precio+(precio*0.25));
	return valor;
}

float precioBitcoin(float precio){
	float valor;
	float valorBtc;
	valorBtc=4606954.55;
	valor=(precio/valorBtc);
	return valor;

}

float precioUnitario(float precio, float kms){
	float valor;
	valor=(precio/kms);
	return valor;
}

float diferencia(float precioA, float precioB){
	float valor;
	if(precioA>=precioB){
		valor=(precioA-precioB);
	}
	else{
		valor=(precioB-precioA);
	}
	return valor;
}
