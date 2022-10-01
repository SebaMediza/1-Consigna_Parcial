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
		
		//printf("%d", sensa_temp());
		
		clock_t tiempo_inicio, tiempo_final, inicio_evento1, fin_evento1 ;
		double segundos_v=0, tiempo_tot =0; 
		
		tiempo_inicio = clock();
		inicio_evento1 = clock(); 
		
		while (tiempo_tot< TOTTEMP){ 
			fin_evento1 = clock();
			tiempo_final = clock();
			segundos_v = (double)(fin_evento1 -inicio_evento1)/ CLOCKS_PER_SEC;
			
			tiempo_tot= (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;
			
			if (segundos_v >=TEV1){
				inicio_evento1 = fin_evento1;
				int cont1=0, cont2=0, contac, contae;
				bool control1, control2;
				unsigned int temperatura=sensa_temp();
				if(temperatura<0){
					if(cont1<1){
						cont1++;
						control1=false;
						calefactor(sensa_temp(), control1);
					}else{
						if(cont1>=1){
							cont1++;
							control1=true;
							calefactor(sensa_temp(), control1);
							contac=cont1;
						}
					}
				}else{
					if(temperatura>40){
						if(cont2<1){
							cont2++;
							control2=false;
							enfriador(sensa_temp(),control2);
						}else{
							if(cont1>=1){
								cont2++;
								control2=true;
								enfriador(sensa_temp(),control2);
								contae=cont2;
							}
						}
					}
				}
			printf("Tiempo entre eventos %8.2f\n", segundos_v);
			}
		} 
	printf("Tiempo transcurrido Total de ejecución %lf", tiempo_tot);

return (0);
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
