#include  <Stepper.h>

int sensor = 3;     
int leitura = A1;     
const int PassoPorVolta = 500;  // Passo por Volta do Motor

void setup() {

  Stepper MotorP(PassoPorVolta, 8, 10, 9, 11);
  pinMode(sensor,      INPUT);
  pinMode(leitura,     INPUT);

  servo.attach(cobertura);
  servo.write(90);           
  
  Serial.begin(9600);
  digitalWrite(LEDauto, HIGH);
}

void loop() {



  
  if(digitalRead(sensor) == HIGH){  // Sem chuva detectada
     MotorP.step(682);
       delay(1000);
  }
  
  if(digitalRead(sensor) == LOW){   // Chuva detectada
  MotorP.step(-682);
  delay(1000);
  }

  Serial.print("Medida do sensor: ");
  Serial.println(analogRead(leitura));  
  delay(250);
}