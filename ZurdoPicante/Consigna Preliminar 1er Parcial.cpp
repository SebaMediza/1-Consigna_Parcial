#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define VELMAX 150
#define VELMIN 100
#define TIEMPO_VEL 3
#define TIEMPO_BAND 8
int sensa_velocidad(){
	int vel;
	vel= rand() % 250 + 1;
	return vel;	
}
int banderillera(){
	int bandera;
	bandera=rand() % 4 + 1;
	return bandera;
}	
int memoria_de_la_velocidad_maxima(int velocidad_maxima){
	int maxima1,maxima2;
	maxima1=velocidad_maxima;
	if (maxima2>maxima1) {
		maxima2=maxima1;
	}
return maxima2;
}
int velocidad_promedio(){
	int vel_prima;
	vel_prima=sensa_velocidad();
	if (vel_prima<20) {
		printf("La Velocidad Sensada es: %d",vel_prima);
		printf("\n");
		printf("Velocidad Insuficiente");
		exit(0);
	} else {
		printf("La Velocidad Sensada es: %d",vel_prima);
		printf("\n");
	}
return vel_prima;
}
int calclulo_de_la_velocidad_promedio(int vel_promedio){
	if (vel_promedio>=VELMAX) {
		printf("Reducir Velocidad\n");
		printf("\n");
	} else {
		if (vel_promedio<=VELMIN) {
			printf("Muy Poca Velocidad, Aumentar\n");
			printf("\n");
		} else {
			printf("Velociada Normal, Mantener\n");
			printf("\n");
			}
		}
return 0;
}
int main(void){
	int velocidad,vel_prima,vel_promedio,bandera,contador1,velocidad_maxima;
	velocidad=0;
	contador1=0;
	clock_t tiempo_inicio, tiempo_final,tiempo_inicio_bandera,tiempo_final_bandera; 
	double segundos_v,segundos_b;
	srand(time(NULL)); 
	srand(time(NULL));
	tiempo_inicio = clock();
	tiempo_inicio_bandera=clock();
		do {
			tiempo_final = clock();
			segundos_v = (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;
			if (segundos_v >= TIEMPO_VEL) {
				velocidad=velocidad+(vel_prima=velocidad_promedio());
				velocidad_maxima=vel_prima;
				memoria_de_la_velocidad_maxima(velocidad_maxima);
				contador1++;
					if (contador1==3) {
						contador1=0;
						vel_promedio=(velocidad/3);
						printf("La Velocidad Promedio es: ");
						printf("%dk/h\n",vel_promedio);
						printf("\n");
						calclulo_de_la_velocidad_promedio(vel_promedio);
						} 
tiempo_inicio = tiempo_final;
			}
			tiempo_final_bandera=clock();
			segundos_b=(double)(tiempo_final_bandera-tiempo_inicio_bandera)/CLOCKS_PER_SEC;
				if (segundos_b>=TIEMPO_BAND) {
					bandera=banderillera();
						switch (bandera) {
							case 1:
								bandera==1;
								printf("Atencion,Posible Zona de Derrape");
								printf("\n");
								break;
							case 2:
								bandera==2;
								printf("Atencion,Posible Zona de Choque");
								printf("\n");
								break;
							case 3:
								bandera==3;
								printf("Bandera Roja, Carrera Detenida");
								printf("\n");
								printf("La Velocidad Maxima Registrada fue:");
								printf("%dk/h\n",velocidad_maxima);
								exit(0);
								break;
							case 4:
								bandera==4;
								printf("Se Reinicia la Competencia");
								printf("\n");
							default:
								1;
							}			
tiempo_inicio_bandera=tiempo_final_bandera;	
		}
	}while(vel_prima>20);
return 0;
}
