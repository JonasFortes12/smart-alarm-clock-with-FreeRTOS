#include "libs/services.h"

///////////////////////////////////////// Setup ///////////////////////////////////
void setup() {
    // setup the modules services ( RTC, LCD, Buzzer, Noise Sensor, PIR Sensor)
    setup_modules_services();

    // Create the queue for the noise sensor
    noiseQueue = xQueueCreate(1, sizeof(bool));  // Create a queue with 1 element of type bool
    if (noiseQueue == NULL) {
        Serial.println("Failed to create noiseQueue");
        while (1);  // Block the program if the queue was not created
}
  
    // Create tasks
    xTaskCreate(update_time_on_lcd_task, "Update Time", 2048, NULL, 1, NULL);
    xTaskCreate(verify_alarm_time_task, "Verify Alarm", 2048, NULL, 2, NULL);
    xTaskCreate(verify_moviment_task, "Verify Movement", 2048, NULL, 3, NULL);
    xTaskCreate(verify_noise_task, "Verify Noise", 2048, NULL, 3, NULL);
    xTaskCreate(log, "Log Task", 2048, NULL, 1, NULL);  // Add the log task
    
    // Init the scheduler for the tasks
    vTaskStartScheduler();

    // Define time for the alarm  
    set_alarm_time(4, 25, 0); // Set the alarm time to 2:25:00
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {
    // Empty loop
}
