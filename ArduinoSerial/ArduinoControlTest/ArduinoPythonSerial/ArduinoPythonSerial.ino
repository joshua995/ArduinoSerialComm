/*Joshua Liu
Arduino - Python
*/
#define greenL 2
#define redL 3

#define photoresistor A0

bool isGreenOn = false;
bool isRedOn = false;

String message = "";

void setup() {
  Serial.begin(9600);
  
  pinMode(greenL, OUTPUT);
  
  pinMode(redL, OUTPUT);

  pinMode(photoresistor, INPUT);
  
  digitalWrite(greenL, LOW);
  digitalWrite(redL, LOW);
  
  Serial.println("Green off|Red off");
}

void loop() {
  Serial.println("Photoresistor: " + String(analogRead(photoresistor)) + " " + message);
  if(analogRead(photoresistor) <= 20g){
    digitalWrite(greenL, HIGH);
    isGreenOn = true;
    digitalWrite(redL, HIGH);
    isRedOn = true;
  }
  if(Serial.available()) {
    String data = Serial.readString();// Reads the serial data sent from the Python code
    if (data.indexOf("green") != -1 && !isGreenOn){
      digitalWrite(greenL, HIGH);
      isGreenOn = true;
    }else if(data.indexOf("green") != -1 && isGreenOn){
      digitalWrite(greenL, LOW);
      isGreenOn = false;
    }
    if (data.indexOf("red") != -1 && !isRedOn){
      digitalWrite(redL, HIGH);
      isRedOn = true;
    }else if(data.indexOf("red") != -1 && isRedOn){
      digitalWrite(redL, LOW);
      isRedOn = false;
    }
  }
  message = "";
  if (isGreenOn){
    message += "Green on";
  }else if (!isGreenOn){
    message += "Green off";
  }
  if (isRedOn){
    message += "Red on";
  }else if (!isRedOn){
    message += "Red off";
  }
}
