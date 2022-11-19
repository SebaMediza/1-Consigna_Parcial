#define pinEnfriador 10
#define pinCalentador 9
#define pinAcelerar 8
#define pinMedidas A1

#define segMedidas 3000
#define tiempoEnvento2 6000
#define minTemperatura -25
#define maxTemperatura 50
//#define pormTemperaturas = (maxTemperatura - minTemperatura) / 2
//#define prom_10Mas = (pormTemperaturas + maxTemperatura * (0.1))
//#define prom_10Men = (pormTemperaturas + minTemperatura * (0.1))


int leer(int);
int calentar();
int enfriar();
int promedio(int, int, int);

int medidas[20], cantMedidas = 0, promTemp = 0;
unsigned int tiempoEventosInicial = 0, tiempoEventosFinal = 0;

void setup() {
	pinMode(pinEnfriador, OUTPUT);
	pinMode(pinCalentador, OUTPUT);
	pinMode(pinAcelerar, OUTPUT);
	pinMode(pinMedidas, INPUT);
	Serial.begin(9600);
}

void loop() {
	tiempoEventosInicial = millis();
	if(tiempoEventosInicial - tiempoEventosFinal >= segMedidas){
		medidas[cantMedidas] = leer(cantMedidas);
		if(cantMedidas == 19){
			cantMedidas = 0;
		}
		if(medidas[cantMedidas] < minTemperatura){
			calentar();
		}else{
			if(medidas[cantMedidas] > maxTemperatura){
				enfriar();
			}else{
				Serial.write("La temp es:",medidas[cantMedidas]);
			}
		}
		if(cantMedidas % 3 == 0 && cantMedidas != 0){
			//promedio(medidas, cantMedidas, promTemp);
		}
	}
}

int leer(int indice){
	int medida, medidasMap=0;
	medida = analogRead(pinMedidas);
	medidasMap = map(medida, 0, 1023, minTemperatura, maxTemperatura);
	medidas[indice] = medidasMap;
	return medidas[indice];
}

int promedio(int medidas, int cantMedidas, int promTemp){
	for(int i=0;i<cantMedidas;i++){
		//promTemp = promTemp + medidas[i];
	}
	return promTemp;
}

int calentar(){
	medidas[cantMedidas] = medidas[cantMedidas] + 1;
	return medidas[cantMedidas];
}

int enfriar(){
	medidas[cantMedidas] = medidas[cantMedidas] - 1;
	return medidas[cantMedidas];
}