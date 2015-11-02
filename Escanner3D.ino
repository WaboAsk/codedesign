// Librerias
#include <Servo.h>

//  ***********************************************
//  ************ DAVID LASERSCANNER 3D ************
//  ***********************************************
//SERVOS
Servo servoDavidI;
Servo servoDavidD;
Servo servoDavidC;

//PINES
int pin_ServoDI = 3;  //verde
int pin_LaserDI = 4;  //blanco


int pin_ServoDD = 6;  //verde
int pin_LaserDD = 7;  //blaco

int pin_ServoDC = 2;   // sevo blanco


//  ***********************************
//  ************ Angulos ************
//  ***********************************
//Izquierdo
int AnguloDavidiz_Arriba = 55;    //75
int AnguloDavidIz_Abajo = 30;     //30

//Abajo AnguloDavidDe_Abajo
int AnguloDavidDe_Arriba = 125;   //110
int AnguloDavidDe_Abajo = 145;    //145

//Velocidad con la que se mueven los laser
int velosidad_Escaneo = 300;    //300

//Rotacion del servo central (milesimas de segundos)
int rotacionServoCentro = 150;

//  ***********************************
//  ************ Variables ************
//  ***********************************

int i = 0;
char dato;


void setup() {
  //Serial de consola
  Serial.begin(9600);

  //  ************ DAVID LASERSCANNER 3D ************
  pinMode(pin_LaserDI, OUTPUT);
  pinMode(pin_LaserDD, OUTPUT);

  servoDavidI.attach(pin_ServoDI);
  servoDavidD.attach(pin_ServoDD);
  servoDavidC.attach(pin_ServoDC);

  servoDavidD.write(110);
  servoDavidI.write(75);
  servoDavidC.write(90);

}

void loop() {

  if (Serial.available()) {
    dato = Serial.read();
    Serial.println(dato);
  }

  if (dato == '1') {
    //ENCENDEMOS EL SERVO DEL DAVID IZQUIERDO
    Serial.println("Escaneando David lasser Scan lado Izquierdo");
    digitalWrite(pin_LaserDI, HIGH);
    digitalWrite(pin_LaserDD, LOW);
    servoDavidD.write(110);

    for (i = AnguloDavidIz_Abajo; i <= AnguloDavidiz_Arriba; i += 1) {
      servoDavidI.write(i);
      delay(velosidad_Escaneo);
    }

    for (i = AnguloDavidiz_Arriba; i >= AnguloDavidIz_Abajo; i -= 1) {
      servoDavidI.write(i);
      delay(velosidad_Escaneo);
    }
  }

  if (dato == '2') {

    //ENCENDEMOS EL SERVO DEL DAVID IZQUIERDO
    Serial.println("Escaneando David lasser Scan lado Derecho");
    digitalWrite(pin_LaserDI, LOW);
    digitalWrite(pin_LaserDD, HIGH);
    servoDavidI.write(75);

    for (i = AnguloDavidDe_Arriba; i <= AnguloDavidDe_Abajo; i += 1) {
      servoDavidD.write(i);
      delay(velosidad_Escaneo);
    }

    for (i = AnguloDavidDe_Abajo; i >= AnguloDavidDe_Arriba; i -= 1) {
      servoDavidD.write(i);
      delay(velosidad_Escaneo);
    }
  }

  if (dato == '3') {
    // PAUSA
    int torque = 0;
    dato = Serial.println("ROTANDO EL OBJETO");

    // PARAMOS TODAS LAS FUNCIONES
    digitalWrite(pin_LaserDI, LOW);
    digitalWrite(pin_LaserDD, LOW);
    servoDavidD.write(110);
    servoDavidI.write(75);
    // FIN DE LA FUNCION DE PARAR PROCESO

     if (torque == 0) {
      servoDavidC.write(0);
      delay(rotacionServoCentro);
      servoDavidC.write(90);
      torque = 1;
    }
  }

  if (dato == '4') {
    // PAUSA
    dato = Serial.println("ESCANEO PAUSADO");

    digitalWrite(pin_LaserDI, LOW);
    digitalWrite(pin_LaserDD, LOW);
    servoDavidD.write(110);
    servoDavidI.write(75);
  }


}
