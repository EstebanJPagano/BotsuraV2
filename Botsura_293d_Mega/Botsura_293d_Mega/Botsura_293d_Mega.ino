
int TRIG = 22;      // trigger en pin 10
int ECO = 24;      // echo en pin 9
int DURACION;
int DISTANCIA;

void setup(){  
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  Serial.begin(38400);     // inicializacion de comunicacion serial a 9600 bps
}

void loop(){
    Serial.println(distancia());    // envio de valor de distancia por monitor serial

  
}

int distancia(){
  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);       // al pin conectado al trigger
  digitalWrite(TRIG, LOW);    // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
            // alto en Echo
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  delay(200);       // demora entre datos
  return (DISTANCIA);
}
