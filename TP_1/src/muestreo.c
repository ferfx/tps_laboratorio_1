
#include <stdio.h>
#include <stdlib.h>


int tomarOpcion(){
	int numero;

	printf("Elija una opcion del 1 al 6\n\n");
	printf("Opcion 1:Ingrese los kilometros del viaje\n");
	printf("Opcion 2:Ingrese el precio segun que tipo de aerolinea\n");
	printf("Opcion 3:Ingrese para calcular todos los costos\n");
	printf("Opcion 4:Ingrese para mostrar los resultados\n");
	printf("Opcion 5:Ingrese para la carga forzada de datos\n");
	printf("Opcion 6:Ingrese aqui para salir del programa\n");

	scanf("%d",&numero);
	while(numero<1 || numero>6){
			printf("Opcion incorrecta, vuelva a elegir una del 1 a 6 posibles\n");
			scanf("%d",&numero);

	}
	return numero;
}


void mostrar(float a, float b, float c, float d){
	printf("A) Precio con tarjeta de debito: $ %.2f\n",a);
	printf("B) Precio con tarjeta de credito: $ %.2f\n",b);
	printf("C) precio pagando con bitcoin: %.2f BTC\n",c);
	printf("D) Mostrar precio unitario: $ %.2f\n\n",d);
}
