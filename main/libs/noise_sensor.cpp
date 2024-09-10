#include "pins.h"

bool is_noise_detected(){
    return digitalRead(SOUND_SENSOR_PIN);
}