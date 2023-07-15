/*Joshua Liu
Arduino - Python Electrical
*/
#define photoresistor A0

String message = "";
int brightness = 0;
int lights = 3;

bool isDark = false;

void setup() {
  Serial.begin(9600);
  pinMode(photoresistor, INPUT);
  pinMode(lights, OUTPUT);
  digitalWrite(lights, LOW);
}

void loop() {
  Serial.println("Photoresistor: " + String(analogRead(photoresistor)));
  if(analogRead(photoresistor) <= 20){
    if (!isDark){
      digitalWrite(lights, HIGH);
      isDark = true;
    }
  }else{
    isDark = false;
  }
  if(Serial.available()) {
    String data = Serial.readString();// Reads the serial data sent from the Python code
    brightness = map(data.toInt(), 0, 900, 50, 0);
    message = "Brightness: " + String(brightness);
    analogWrite(lights, brightness);
    delay(1000);
    Serial.println("Brightness: " + String(brightness));
  }
}
