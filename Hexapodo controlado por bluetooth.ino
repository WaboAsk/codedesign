#include <Servo.h>  // Libreria de servomotores

//Estado de la señal del bluethoo
int estado = 0; //Inicializamos "Estado" a 0
int pin_Leds = 7; // Iniciamos la variable para los pines del los leds(ojos)

//DECLARAMOS LAS VARIABLES CORRESPONDIENTES PARA
//CADA UNO DE LOS 3 SERVOS;
//DERECHO, IZQUIERDO Y CENTRO
Servo servo_Centro;        //  3
Servo servo_Derecho;       //  2
Servo servo_Izquierdo;     //  1



//***************************************************************
//************************* SETUP  ******************************
//***************************************************************
void setup() {
  Serial.begin(9600); // Inicializamos el monitor serial del arduino

  //Decharamos los led como salida
  pinMode(pin_Leds, OUTPUT);

  //ASIGNAMOS LOS PINES CORRESPONDIENTES PARA
  //CADA UNO DE LOS SERVOS.
  servo_Centro.attach(11);
  servo_Derecho.attach(10);
  servo_Izquierdo.attach(9);

  servo_Centro.write(90);
  servo_Derecho.write(90);
  servo_Izquierdo.write(90);

}

//*******************************************************************
//************************* FUNCIONES  ******************************
//*******************************************************************

//************************* ADELANTE  ******************************
void Adelante() {
  servo_Centro.write(20);
  servo_Derecho.write(60);
  servo_Izquierdo.write(60);
  delay(300);

  servo_Centro.write(125);
  servo_Derecho.write(120);
  servo_Izquierdo.write(120);
  delay(300);

}


//************************* ATRAS  ******************************
void Atras() {
  servo_Centro.write(20);
  servo_Derecho.write(120);
  servo_Izquierdo.write(120);
  delay(300);

  servo_Centro.write(125);
  servo_Derecho.write(60);
  servo_Izquierdo.write(60);
  delay(300);

}

//************************* IZQUIERDA  ******************************
void Izquierda() {
  servo_Centro.write(20);
  servo_Derecho.write(60);
  servo_Izquierdo.write(90);
  delay(300);

  servo_Centro.write(125);
  servo_Derecho.write(120);
  servo_Izquierdo.write(90);
  delay(300);

}

//************************* DERECHA  ******************************
void Derecha() {
  servo_Centro.write(20);
  servo_Derecho.write(90);
  servo_Izquierdo.write(60);
  delay(300);

  servo_Centro.write(125);
  servo_Derecho.write(90);
  servo_Izquierdo.write(120);
  delay(300);

}


//************************* PAUSA  ******************************
void PAUSA() {
  servo_Centro.write(90);
  servo_Derecho.write(90);
  servo_Izquierdo.write(90);

}


//*******************************************************************
//****************************** LOOP  ******************************
//*******************************************************************
void loop() {
  if (Serial.available() > 0) {
    estado = Serial.read();
  }

  if (estado == '0') {
    PAUSA();   // FUNCION PARA PARAR

  }

  if (estado == '1') {
    Adelante();   // FUNCION PARA IR HACIA ADELANTE

  }

  if (estado == '2') {
    Atras();      // FUNCION PARA IR HACIA ATRAS
  }

  if (estado == '3') {
    Izquierda();      // FUNCION PARA IR HACIA LA IZQUIERDA
  }

  if (estado == '4') {
    Derecha();      // FUNCION PARA IR HACIA LA DERECHA
  }

  if (estado == '5') {
    digitalWrite(pin_Leds, HIGH);
  }

  if (estado == '6') {
    digitalWrite(pin_Leds, LOW);
  }


}
