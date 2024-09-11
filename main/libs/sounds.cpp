#include "pins.h"

void setup_sounds(){
    pinMode(BUZZER_PIN, OUTPUT);
}

void ring_soft_sound(){
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
}

void ring_hard_sound(){
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
}