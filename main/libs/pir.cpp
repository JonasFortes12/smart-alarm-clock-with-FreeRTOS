#include "pins.h"

void setup_pir(){
    pinMode(PIR_PIN, INPUT);
}

bool is_moviment_detected(){
    return digitalRead(PIR_PIN);
}