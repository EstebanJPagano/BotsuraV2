#include <AFMotor.h>
#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
#include <Servo.h>              

SoftwareSerial miBT(53, 51);

// ----------- Puenteh
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int speedCarFast = 255;  // variable para almacenar valor de velocidad
int speedCarMid = 245;  // variable para almacenar valor de velocidad
int speedCarSlow = 230; // variable para almacenar valor de velocidad
int speedCar ;

char DATO = 0;      // variable para almacenar caracter recibido

// ---------- SERVO
Servo myservoH;               // Define any servo name
int servo_position = 0;
int contador;

/// ----------- ULTRASONICO
int TRIG = 22;      // trigger en pin 10
int ECO = 24;      // echo en pin 9
int DURACION;
int DISTANCIA;

void setup(){

  miBT.begin(38400);
  Serial.begin(38400);

  // MOTORES
  motor1.setSpeed(speedCarFast);
  motor2.setSpeed(speedCarFast);
  
  // SERVO
  myservoH.attach (10);          // Define the servo signal pins

  // ULTRASONICO  
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
}

void loop(){
  // calcularDiatanciaMin();
    
    //------------Bluetooth
   if (miBT.available()){     // si hay informacion disponible desde modulo
    DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo
    Serial.println(DATO);
      
    if(DATO == '1') { MotorForward();}
    else if(DATO == '3') {MotorBackward();}
    else if(DATO == '4') {TurnLeft();}
    else if(DATO == '2') {TurnRight();}
    else if(DATO == '0') {MotorStop(); }
    else if(DATO == 'a') SetSpeedCarMax() ;     
    else if(DATO == 'b') SetSpeedCarMid();   
    else if(DATO == 'c') SetSpeedCarMin();      
    else if(DATO == 'l') { rotarCabeza_H_I(); }//rotar horizontal izquierda
    else if(DATO == 'r') { rotarCabeza_H_D(); } //rotar horizontal derecha
    else if(DATO == 't') { contador = 0; rotarCabeza_H_90();} // rotar cabeza derecha
    
    if(distancia() <= 10){
      Serial.println("SSSSS");   
      MotorStop();
    }
   }
    delay(90);  

}

int SetSpeedCarMid(){
  Serial.print("SetSpeedCarMid");
  motor1.setSpeed(speedCarMid);
  motor2.setSpeed(speedCarMid);
  delay(90);  
}

int SetSpeedCarMin(){
  Serial.print("SetSpeedCarMin ");
  motor1.setSpeed(speedCarSlow);
  motor2.setSpeed(speedCarSlow);
  delay(90);  
}

int SetSpeedCarMax(){
  Serial.print("SetSpeedCarMax");
  motor1.setSpeed(speedCarFast);
  motor2.setSpeed(speedCarFast);
  delay(90);  
}

/* FORWARD */
void MotorForward(){
  Serial.print("MotorForward");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

/* BACKWARD */
void MotorBackward(){
  Serial.print("MotorBackward");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);  
}

/* TURN RIGHT */
void TurnRight(){
  Serial.print("TurnRight");
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

/* TURN LEFT */
void TurnLeft(){  
  Serial.print("TurnLeft");
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void MotorStop(){
  Serial.print("MotorStop");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

// Ultrasonico

int distancia(){
  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);       // al pin conectado al trigger
  digitalWrite(TRIG, LOW);    // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  delay(100);       // demora entre datos
  return (DISTANCIA);
}
// Fin Ultrasonico

// Servo
int rotarCabeza_H_I(){
  if(contador == 0){ contador = 90; }
  contador = contador + 25;               //Incrementa el contador
  delay (100);           // Retardo
  myservoH.write(contador); 
 }
 
void rotarCabeza_H_D(){ 
 if(contador == 0){ contador = 90;  }
 contador= contador - 25;               //Incrementa el contador
 delay (100);           // Retardo
 myservoH.write(contador);
}
void rotarCabeza_H_90(){ myservoH.write(90); }

// Fin Servo
