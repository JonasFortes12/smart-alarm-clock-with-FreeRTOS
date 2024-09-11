#include "pins.h"

void setup_noise_sensor(){
    pinMode(SOUND_SENSOR_PIN, INPUT); // Set the signal pin as input
}

bool is_noise_detected(){
    return digitalRead(SOUND_SENSOR_PIN);
}