#define A 500
#define B 300
#define trigPin 9            //Trig Ultrasons (sortie)
#define echoPin 10
int motor_pin1 = 4;
int motor_pin2 = 5;
int motor_pin3 = 6;
int motor_pin4 = 7;                                    

void setup () { 
  pinMode(trigPin, OUTPUT);   //Trig est une sortie
  pinMode(echoPin, INPUT);    //Echo est une entrée
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(motor_pin3,OUTPUT);
  pinMode(motor_pin4,OUTPUT);
  delay(700);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);               //Trig déclenché 10ms sur HIGH
  digitalWrite(trigPin, LOW);       
  // calcul de la distance :
  duration = pulseIn(echoPin, HIGH);   // Distance proportionnelle à la durée de sortie
  distance = duration*340/(2*10000);   //Vitesse du son théorique
  
  if(distance >= 20) {                 //Si il n'y a pas d'obstacle à plus de 20cm 
    digitalWrite(motor_pin1,LOW);      //Alors il avance 
    digitalWrite(motor_pin2,HIGH);
    digitalWrite(motor_pin3,HIGH);
    digitalWrite(motor_pin4,LOW);                                
  }
  else {                               //Sinon (si il voix un objet a moin de 20 cm)
    digitalWrite(motor_pin1,HIGH);     //Le robot part en arriere puis 500 milliseconde 
    digitalWrite(motor_pin2,LOW);      //aprés il part vers la gauche.
    digitalWrite(motor_pin3,LOW);
    digitalWrite(motor_pin4,HIGH);
    delay(A);
    digitalWrite(motor_pin1,LOW);
    digitalWrite(motor_pin2,HIGH);
    digitalWrite(motor_pin3,LOW);
    digitalWrite(motor_pin4,HIGH);
    delay(B);
  }
}﻿
