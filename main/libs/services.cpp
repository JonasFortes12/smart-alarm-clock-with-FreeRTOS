#include "pins.h"
#include "sounds.h"
#include "lcd.h"
#include "pir.h"
#include "noise_sensor.h"
#include "real_time_clock.h"
#include "free-rtos-source/include/FreeRTOS.h"


void setup_modules_services()  {
    
    // Initialize Serial communication
    Serial.begin(9600);

    // Initialize the RTC
    rtc_setup();
    set_time();

    // Initialize the LCD
    setupLCD();
    clearLCD();

    // Initialize the buzzer
    setup_sounds();

    // Initialize the noise sensor
    setup_noise_sensor();

    // Initialize the PIR sensor
    setup_pir();
}


