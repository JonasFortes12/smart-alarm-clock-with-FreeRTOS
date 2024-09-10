#include "libs/lcd.h"
#include "libs/real_time_clock.h"
#include "libs/noise_sensor.h"



///////////////////////////////////////// Setup ///////////////////////////////////
void setup() {

    // Initialize Serial communication
    Serial.begin(9600);

    // Initialize the RTC
    rtc_setup();
    set_time();

    // Initialize the LCD
    setupLCD();
    clearLCD();
  pinMode(SOUND_SENSOR_PIN, INPUT); // Set the signal pin as input
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {
    
    // update the time
    now = rtc.now();


    Serial.println(get_time());
    showMessage(get_time(), 0);
    showMessage(get_date(), 1);

    
    Serial.println(is_noise_detected());
    delay(100);
}
