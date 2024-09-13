#include "libs/services.h"

///////////////////////////////////////// Setup ///////////////////////////////////
void setup()
{
    // Setup the modules services (RTC, LCD, Buzzer, Noise Sensor, PIR Sensor)
    setup_modules_services();

    // Create the queue for the noise sensor
    noiseQueue = xQueueCreate(1, sizeof(bool)); // Create a queue with 1 element of type bool
    if (noiseQueue == NULL)
    {
        Serial.println("Failed to create noiseQueue");
        while (1)
            ; // Block the program if the queue was not created
    }

    // Create tasks
    xTaskCreate(update_time_on_lcd_task, "Update Time", 8192, NULL, 1, NULL);  // Increased to 8192
    xTaskCreate(verify_alarm_time_task, "Verify Alarm", 8192, NULL, 2, NULL);  // Increased to 8192
    xTaskCreate(verify_moviment_task, "Verify Movement", 4096, NULL, 3, NULL); // Increased to 4096
    xTaskCreate(verify_noise_task, "Verify Noise", 4096, NULL, 3, NULL);       // Increased to 4096
    xTaskCreate(log, "Log Task", 8192, NULL, 1, NULL);                         // Increased to 8192

    // Define time for the alarm
    set_alarm_time(20, 33, 0); // Set the alarm time to 4:25:00
}

///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop()
{
    // Empty loop
}
