

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
