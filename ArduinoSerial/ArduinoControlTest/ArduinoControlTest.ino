/*Joshua Liu
Arduino only
*/

#define greenB 2
#define yellowB 3
#define redB 4

#define greenL 5
#define yellowL 6
#define redL 7

#define photoresistor A0

#define motor 11

#define motorB 8

void setup() {
  Serial.begin(9600);
  
  pinMode(greenB, INPUT);
  pinMode(yellowB, INPUT);
  pinMode(redB, INPUT);
  
  pinMode(greenL, OUTPUT);
  pinMode(yellowL, OUTPUT);
  pinMode(redL, OUTPUT);

  pinMode(photoresistor, INPUT);

  pinMode(motor, OUTPUT);
  pinMode(motorB, INPUT);

  digitalWrite(greenL, LOW);
  digitalWrite(yellowL, LOW);
  digitalWrite(redL, LOW);
  
  Serial.println("Green off");
  Serial.println("Yellow off");
  Serial.println("Red off");
}

void loop() {
  Serial.print("Photoresistor: ");
  Serial.println(analogRead(photoresistor));
  if(analogRead(photoresistor) > 9){
    if(digitalRead(motorB) == 1){
      digitalWrite(motor, HIGH);
      //Serial.println("Motor on");
    }else{
      digitalWrite(motor, LOW);
      //Serial.println("Motor off");
    }
    if(digitalRead(greenB) == 1){
      digitalWrite(greenL, HIGH);
      //Serial.println("Green on");
    }else{
      digitalWrite(greenL, LOW);
      //Serial.println("Green off");
    }
    if(digitalRead(yellowB) == 1){
      digitalWrite(yellowL, HIGH);
      //Serial.println("Yellow on");
    }else{
      digitalWrite(yellowL, LOW);
      //Serial.println("Yellow off");
    }
    if(digitalRead(redB) == 1){
      digitalWrite(redL, HIGH);
      //Serial.println("Red on");
    }else{
      digitalWrite(redL, LOW);
      //Serial.println("Red off");
    }
  }else{
    if(digitalRead(motorB) == 1){
      digitalWrite(motor, LOW);
      //Serial.println("Motor off");
    }else{
      digitalWrite(motor, HIGH);
      //Serial.println("Motor on");
    }
    if(digitalRead(greenB) == 1){
      digitalWrite(greenL, LOW);
      //Serial.println("Green off");
    }else{
      digitalWrite(greenL, HIGH);
      //Serial.println("Green on");
    }
    if(digitalRead(yellowB) == 1){
      digitalWrite(yellowL, LOW);
      //Serial.println("Yellow off");
    }else{
      digitalWrite(yellowL, HIGH);
      //Serial.println("Yellow on");
    }
    if(digitalRead(redB) == 1){
      digitalWrite(redL, LOW);
      //Serial.println("Red off");
    }else{
      digitalWrite(redL, HIGH);
      //Serial.println("Red on");
    }
  }
}
