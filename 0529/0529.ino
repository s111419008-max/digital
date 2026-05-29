int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int ledCount = 10;

int sensorPin = A0;

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  int sensorRead = analogRead(sensorPin);

  int ledBar = map(sensorRead, 0, 1023, 0, ledCount);

  ledControl(ledBar);

  Serial.print("Sensor: ");
  Serial.print(sensorRead);
  Serial.print("  LED: ");
  Serial.println(ledBar);

  delay(100);
}

void ledControl(int ledNumber) {
  for (int i = 0; i < ledCount; i++) {
    if (i < ledNumber) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
