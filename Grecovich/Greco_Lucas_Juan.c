#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <stdbool.h>
#include <math.h>
#include <windows.h>

#define TOTTEMP 30 
#define TEV1 5 
#define MINTEM -25
#define MAXTEM 50

COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
	
int calefactor(int, bool);
int enfriador(int, bool);
int promedio(int, bool);
int sensa_temp();
	
	
int main(){
	srand(time(0));
	clock_t tiempo_inicio, tiempo_final, inicio_evento1, fin_evento1 ;
	double segundos_v=0, tiempo_tot =0; 
		
	tiempo_inicio = clock();
	inicio_evento1 = clock(); 
	int contadorCalor=0, contadorEnfriador=0, contadorSuperCalentar=0, contadorSuperEnfriar=0;
	bool controlCalor=false, controlEnfriar=false;
	
	while (tiempo_tot< TOTTEMP){ 
		fin_evento1 = clock();
		tiempo_final = clock();
		segundos_v = (double)(fin_evento1-inicio_evento1)/ CLOCKS_PER_SEC;
		tiempo_tot= (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;
		
		if (segundos_v >=TEV1){
			inicio_evento1 = fin_evento1;
			int temp=0;
			temp=sensa_temp();
			printf("Temperatura: %d °C \n", temp);
			if(temp<0){
				int nuevaTemperatura=0;
				printf("Calentando...\n");
				contadorCalor++;
				if(contadorCalor==2){
					contadorCalor=0;
					controlCalor=true;
					nuevaTemperatura=calefactor(temp, controlCalor);
					contadorSuperCalentar++;
					//printf("La nueva temperatura es: %d°C\n",nuevaTemperatura);
					//break;
				}
				nuevaTemperatura=calefactor(temp, controlCalor);
				contadorEnfriador=0;
				printf("La nueva temperatura es: %d°C\n",nuevaTemperatura);
			}else{
				if(temp>40){
					int nuevaTemperatura=0;
					printf("Enfriando...\n");
					contadorEnfriador++;					
					if(contadorEnfriador==2){
						contadorEnfriador=0;
						controlEnfriar=true;
						nuevaTemperatura=enfriador(temp,controlEnfriar);
						contadorSuperEnfriar++;
						//printf("La nueva temperatura es: %d°C\n",nuevaTemperatura);
						//break;
					}
					nuevaTemperatura=enfriador(temp,controlEnfriar);
					contadorCalor=0;
					printf("La nueva temperatura es: %d°C\n",nuevaTemperatura);
				}
			}
		printf("Tiempo entre eventos %8.2lf segundos \n", segundos_v);
		printf("\n");
		}
	} 
	printf("\n\nTiempo transcurrido Total de ejecución %lf \n", tiempo_tot);
	printf("Se debió acelerar el enfriamento: %d \n", contadorSuperEnfriar);
	printf("Se debió acelerar el calentamiento: %d \n", contadorSuperCalentar);
	return(0);
}		
int sensa_temp(){			
	return (rand()%(MAXTEM+1)+MINTEM);
}
int calefactor(int temperatura, bool controlcalef){				
	if(controlcalef==false){
		temperatura++;
	}else{
		if(controlcalef==true){
			temperatura=temperatura+5;
				}
			}
	return temperatura;
}				
int enfriador(int temperatura, bool controlenfri){
	if(controlenfri==false){
		temperatura--;
	}else{
		if(controlenfri==true){
			temperatura=temperatura-5;
				}
			}
	return temperatura;
}
