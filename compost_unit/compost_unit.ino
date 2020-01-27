#include <Servo.h>
#include <EEPROM.h>

int moisturePin = A0;
int waterLevel = 0; int orientation = 0;
int waterPump = D3;
int moisture;
int floatSwitch = D4;
int tiltSwitch = D1;
int servoPin = D5;
Servo vent;


void setup() {
  vent.attach(servoPin);
  pinMode(moisturePin, INPUT);
  pinMode(floatSwitch, INPUT);
  pinMode(tiltSwitch, INPUT);
  pinMode(waterPump, OUTPUT);

  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }
  
int getMoisture(int map_max, int map_min) {
  moisture = analogRead(moisturePin);
  return map(moisture,map_max,map_min,0,100); // calibrate
}
bool getWaterLevel () {
  waterLevel = digitalRead(floatSwitch);
  if (waterLevel == LOW) { return true; }
  return false;
}
bool getOrientation () {
  orientation = digitalRead(tiltSwitch);
  if (orientation == LOW) { return true; }
  return false;
}
void togglePump(bool state) {
  if (state) { digitalWrite(waterPump, HIGH); return ; }
  digitalWrite(waterPump, LOW);
}
void toggleVent(bool state) {
  if (state) { vent.write(45); }
  vent.write(135);
}

void loop() {
//  Serial.print(" Mositure : ");
//  Serial.println(getMoisture(608,300));
//  Serial.println("%");
//  Serial.println(getWaterLevel());
//  delay(1000);
//  togglePump(true);
//  delay(3000);
//  togglePump(false);
//  delay(3000);
  
}
