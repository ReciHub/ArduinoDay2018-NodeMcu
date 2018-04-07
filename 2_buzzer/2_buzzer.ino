#include "pitches.h"

// Notas na melodia
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4
};

int noteDurations[] = {
  8, 8, 8, 8, 4, 4
};

void setup() {
  pinMode(14, OUTPUT);
  // Itera sobre os valores diferentes das notas
  for (int thisNote = 0; thisNote < 6; thisNote++) {

    // Calcula o tempo de duracao da nota
    int noteDuration = 100 * noteDurations[thisNote];
    tone(14, melody[thisNote], noteDuration);

    // Para entenderemos qual a nota que esta tocando, eh interessante dar uma pausa entre elas
    int pauseBetweenNotes = noteDuration * 0.4;
    delay(pauseBetweenNotes);
    // para o tone que esta tocando no momento
    noTone(14);
  }
}

void loop() {
  // nao repete nada
}
