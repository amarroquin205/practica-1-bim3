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
   Proyecto: interrupciones externas - Bimestre III
*/

//Directivas de Propocesador
#define btn_arriba 2
#define btn_abajo 3
#define A 4
#define B 5
#define C 6
#define D 7

#define PA 8
#define PB 9
#define PC 10
#define PD 11

//Funciones
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
void display_primero();
void display_segundo();

//Variables
volatile static bool f_print = false; 
int unidades = 0; 
int decenas = 0; 

void setup() {
  pinMode(btn_arriba, INPUT);
  pinMode(btn_abajo, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(PA, OUTPUT);
  pinMode(PB, OUTPUT);
  pinMode(PC, OUTPUT);
  pinMode(PD, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(btn_arriba), funcion_ISR_rising, RISING); 
  attachInterrupt(digitalPinToInterrupt(btn_abajo), funcion_ISR_falling, FALLING); 
}

void loop() {
  if (f_print) {
    f_print = false; 
    if (unidades > 9) {
      decenas++;
      unidades = 0;
    }
    if (unidades == -1) {
      unidades = 9;
      decenas--;
    }
    if (decenas < 0) {
      unidades = 0;
      decenas = 5;
    }
    if (unidades > 0 && decenas == 5) {
      unidades = 0;
      decenas = 0;
    }

  }
  display_primero();
  display_segundo();
}

//Funciones ISR
void funcion_ISR_rising(void) {
  unidades ++; 
  f_print = true;
}
void funcion_ISR_falling(void)
{
  unidades --; 
  f_print = true;
}
void display_primero()
{
  if (unidades == 0) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);

  }
  if (unidades == 1) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
  }
  if (unidades == 2) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
  }
  if (unidades == 3) {
    digitalWrite(A, LOW );
    digitalWrite(B, LOW );
    digitalWrite(C, HIGH );
    digitalWrite(D, HIGH );
  }
  if (unidades == 4) {
    digitalWrite(A, LOW );
    digitalWrite(B, HIGH );
    digitalWrite(C, LOW );
    digitalWrite(D, LOW );
  }
  if (unidades == 5) {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW );
    digitalWrite(D, HIGH);
  }
  if (unidades == 6) {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH );
    digitalWrite(D, LOW);
  }
  if (unidades == 7) {
    digitalWrite(A, LOW );
    digitalWrite(B, HIGH );
    digitalWrite(C, HIGH );
    digitalWrite(D, HIGH );
  }
  if (unidades == 8) {
    digitalWrite(A, HIGH );
    digitalWrite(B, LOW );
    digitalWrite(C, LOW );
    digitalWrite(D, LOW );
  }
  if (unidades == 9) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
  }
}
  void display_segundo()
  {
    if (decenas == 0) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, LOW);
    digitalWrite(PC, LOW);
    digitalWrite(PD, LOW);

  }
  if (decenas == 1) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, LOW);
    digitalWrite(PC, LOW);
    digitalWrite(PD, HIGH);

  }
  if (decenas == 2) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, LOW);
    digitalWrite(PC, HIGH);
    digitalWrite(PD, LOW);

  }
  if (decenas == 3) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, LOW);
    digitalWrite(PC, HIGH);
    digitalWrite(PD, HIGH);

  }
  if (decenas == 4) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, HIGH);
    digitalWrite(PC, LOW);
    digitalWrite(PD, LOW);

  }
  if (decenas == 5) {
    digitalWrite(PA, LOW);
    digitalWrite(PB, HIGH);
    digitalWrite(PC, LOW);
    digitalWrite(PD, HIGH);

  }
  }
  
