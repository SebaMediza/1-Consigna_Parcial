#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <stdbool.h>
#include <math.h>
#include <windows.h>

#define TOTTEMP 20 
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
	
	while (tiempo_tot< TOTTEMP){ 
		fin_evento1 = clock();
		tiempo_final = clock();
		segundos_v = (double)(fin_evento1-inicio_evento1)/ CLOCKS_PER_SEC;
		tiempo_tot= (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;
		
		if (segundos_v >=TEV1){
			inicio_evento1 = fin_evento1;
			int cont1=0, cont2=0, contac=0, contae=0;
			bool control1, control2;
			int temp=0;
			temp=sensa_temp();
			printf("Temperatura: %d °C \n", temp);
			if(temp<0){
				printf("Calentar\n");
				if(cont1<1){
					cont1++;
					control1=false;
					calefactor(temp, control1);
				}else{
					if(cont1>=1){
						cont1++;
						control1=true;
						calefactor(temp, control1);
						contac++;
					}
				}
			}else{
				if(temp>40){
					printf("Enfriar\n");
					if(cont2<1){
						cont2++;
						control2=false;
						enfriador(temp,control2);
					}else{
						if(cont1>=1){
							cont2++;
							control2=true;
							enfriador(temp,control2);
							contae++;
						}
					}
				}
			}
		
		printf("Tiempo entre eventos %8.2lf segundos \n", segundos_v);
		}
	} 
	printf("Tiempo transcurrido Total de ejecución %lf \n", tiempo_tot);
		//printf("Se debió acelerar el enfriamento: %d \n", contae);
		//printf("Se debió acelerar el calentamiento: %d \n", contac);
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
