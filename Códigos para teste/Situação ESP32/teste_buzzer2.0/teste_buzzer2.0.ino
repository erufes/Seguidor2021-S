////////////// Variaveis do Buzzer //////////////
///////////// Musica take on me    /////////////
#include "pitches.h"

int Buzzer ?;                                            // Pino do Buzzer

int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4, 4,
  4, 5, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 5, 8, 8, 8, 8
};

int songLength = sizeof(melody) / sizeof(melody[0]);


////////////// setup() do Buzzer //////////////
void setup() {
  //We don't need anything here
}


////////////// Main e Funçoes auxiliares do Buzzer //////////////
void verificaBuzzer() {
  for (int thisNote = 0; thisNote < songLength; thisNote++) {

    int duration = 1000 / durations[thisNote];
    tone(Buzzer, melody[thisNote], duration);
    int pause = duration * 1.3;
    delay(pause);
    noTone(Buzzer);
  }
}
