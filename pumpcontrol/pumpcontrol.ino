/*
 * Soil Moisture Sensor
 * A0 -> A0
 * 5V -> VCC
 * GND -> GND
 * 
 * Relay
 * GND-> GND
 * VCC -> 5V
 * In -> 13
 * 
 */


#define OUTPIN 13   // พินขาออก ต่อรีเลย์
#define PUMPTH 50   // ช่วงความขื้นเริ่มทำงาน 0-100

int sensorPin = A0;
int sensorValue = 0;
int pumpOn = PUMPTH;

void setup() {
  Serial.begin(115200);
  pinMode(OUTPIN, OUTPUT);
}

void loop() {

  // อ่านค่าเซนเซอร์
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 100, 0);
  Serial.println(sensorValue);

  // เงื่อนไขปั้มทำงาน
  if (sensorValue < pumpOn + 10) {
    Serial.println("Dry -> Pump On");
    digitalWrite(OUTPIN, HIGH);
  }
  else if (sensorValue >= pumpOn - 10) {
    Serial.println("Wet -> Pump On");
    digitalWrite(OUTPIN, LOW);
  }

  delay(1000);
}
