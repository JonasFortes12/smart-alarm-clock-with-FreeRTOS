#include "libs/services.h"



///////////////////////////////////////// Setup ///////////////////////////////////
void setup() {
    // setup the modules services ( RTC, LCD, Buzzer, Noise Sensor, PIR Sensor)
    setup_modules_services();

    set_alarm_time(0, 57, 0);
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {

    // Update the current time
    now = rtc.now();

    Serial.println(get_time());
    delay(1000);
    // Check if the alarm time has arrived
    if(is_alarm_time()){
        // Ring the alarm
        showMessage("Alarm Ringing..",0);
        ring_soft_sound();
        delay(100);
        ring_soft_sound();
        delay(100);
        ring_soft_sound();
    }
    
}
