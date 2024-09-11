#include "pins.h"

bool verifyMovement(){
    if(digitalRead(PIR_PIN) == HIGH){
        return true
    } else{
        return false
    }
}