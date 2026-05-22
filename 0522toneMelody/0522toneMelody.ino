#include "pitches.h"


const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
const int totalLeds = 10;


int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5
};


int noteDurations[] = {
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 4, 4,
  8, 8, 4, 4, 4, 2
};

void setup() {
 
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    int numLedsToLight = map(melody[thisNote], NOTE_G4, NOTE_G5, 1, totalLeds);
    numLedsToLight = constrain(numLedsToLight, 1, totalLeds); // 確保在 1~10 之間

    for (int l = 0; l < totalLeds; l++) {
      if (l < numLedsToLight) {
        digitalWrite(ledPins[l], HIGH); // 亮燈
      } else {
        digitalWrite(ledPins[l], LOW);  // 熄燈
      }
    }

    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  
    noTone(8);
  }

  for (int i = 0; i < totalLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  
}