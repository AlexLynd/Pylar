int moisture_pin = A7; 
int floatSwitch = 8;
int waterLevel = 0;
int analog_moisture;

void setup() {
  pinMode(moisture_pin, INPUT);
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }
  
int getMoisture(int map_max, int map_min) {
  analog_moisture = analogRead(moisture_pin);
  return map(analog_moisture,map_max,map_min,0,100); // calibrate
}
bool getWaterLevel () {
  waterLevel = digitalRead(floatSwitch);
  if (waterLevel == LOW) { return true; }
  return false;
}

void loop() {
//  Serial.print(" Mositure : ");
//  Serial.println(getMoisture(608,300));
//  Serial.println("%");
  Serial.println(getWaterLevel());
  delay(1000);
}
