#include "libs/lcd.h"
#include "libs/real_time_clock.h"



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
  
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {
    
    // update the time
    now = rtc.now();


    Serial.println(get_time());
    showMessage(get_time(), 0);
    showMessage(get_date(), 1);

    
    delay(1000);
}
