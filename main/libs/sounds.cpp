#include "pins.h"

void setup_sounds(){
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(STOP_BUTTON_PIN, INPUT);
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

bool is_pushed_stop_button(){
    return digitalRead(STOP_BUTTON_PIN);
}

void stop_sound(){
    Serial.println("Stop button pushed");
    digitalWrite(BUZZER_PIN, LOW);
}
