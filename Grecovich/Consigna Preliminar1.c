#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <math.h>

#include <stdbool.h>

#define TOTTEMP 20 
#define TEV1 5 
#define MINTEM -25
#define MAXTEM 50

int calefactor(int, bool);
int enfriador(int, bool);
int promedio(int);
int sensa_temp();


int main(){
	
printf("%d", sensa_temp());
	
	clock_t tiempo_inicio, tiempo_final, inicio_evento1, fin_evento1 ;
	double segundos_v=0, tiempo_tot =0; 
	
	tiempo_inicio = clock();
	inicio_evento1 = clock(); 
	
	while (tiempo_tot< TOTTEMP){ 
		fin_evento1 = clock();
		tiempo_final = clock();
		segundos_v = (double)(fin_evento1 -inicio_evento1)/ CLOCKS_PER_SEC;
		
		tiempo_tot= (double)(tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC;
	
		if (segundos_v >=TEV1)
			
		{inicio_evento1 = fin_evento1;
	
		printf("Tiempo entre eventos %8.2lf\n", segundos_v);
		}
	} 
	printf("Tiempo transcurrido Total de ejecuci�n %lf", tiempo_tot);
	
	
	int cont1, cont2, contac, contae;
    bool control1, control2;
    if(sensa_temp()<0){
		if(cont1<1){
			cont1++;
			control1=false;
			calefactor(sensa_temp(),control1);
		}else{
			if(cont1>=1){
			cont1++;
			control1=true;
			calefactor(sensa_temp(),control1);
			contac=cont1;
			}
		}
	}else{
		if(sensa_temp()>40){
			if(cont2<1){
				cont2++;
				control1=false;
				calefactor(sensa_temp(),control2);
			}else{
				if(cont1>=1){
					cont2++;
					control2=true;
					calefactor(sensa_temp(),control2);
					contae=cont2;
				}
			}
		}
		
	}
return (0);
}
	
int sensa_temp(){
    return (rand()%(MAXTEM+1)+MINTEM);
}
	
int calefactor(int temperatura, bool controlCalecAce){	
	if(controlCalecAce==false){
		temperatura++;
	}else{
		if(controlCalecAce==true){
			temperatura=temperatura+5;
		}
	}
	return temperatura;
}
	
int enfriador(int temperatura, bool controlEnfricAce){	
	if(controlEnfricAce==false){
		temperatura--;
	}else{
		if(controlEnfricAce==true){
			temperatura=temperatura-5;
		}
	}
	return temperatura;
}
