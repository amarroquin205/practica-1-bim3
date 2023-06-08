/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Alvaro Josue Antonio Marroquin Corado
   Profe. Alejandro Navas
   Carnet: 2022375
   Proyecto: INTERRUPCIONES POR MEDIO DE SOFTWARE - Bimestre III
*/

//Librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Directivas de Preprocesado
#define boton 2
//Funcion ISR
void sensortemp();
void mar_boton();

//Constructores
Ticker accion_temperatura(sensortemp,3000);
Ticker state_boton(mar_boton,6000);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  accion_temperatura.start();
  state_boton.start();
  sensor.begin();
}

void loop() {
  accion_temperatura.update();
  state_boton.update();
}

void sensortemp(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.println("Sensor de Temperatura");
  Serial.print("La Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}

void mar_boton(){
  int estado = digitalRead(boton);
 
  if(estado == HIGH){
    Serial.println("El boton esta");
    Serial.println("Presionado");
  }

  if(estado == LOW){
    Serial.println("El boton no");
    Serial.println("esta Presionado");
  }
}
