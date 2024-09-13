#include "pins.h"
#include "rings.h"
#include "lcd.h"
#include "pir.h"
#include "noise_sensor.h"
#include "real_time_clock.h"
#include "free-rtos-source/include/FreeRTOS.h"

// create TaskHandle_t for identify the ring alarm task
TaskHandle_t ringAlarmTaskHandle = NULL;

// Create the queue for the noise sensor
QueueHandle_t noiseQueue = NULL;

void setup_modules_services()
{

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

void update_time_on_lcd_task(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        now = rtc.now(); // Atualiza o tempo do RTC
        String time = get_time();
        String date = get_date();
        clearLCD();
        showMessage(time, 0);
        showMessage(date, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Wait for 1 second
    }
}

void ring_alarm_task(void *pvParameters)
{
    (void)pvParameters;
    bool noiseDetected;
    alarm_ringing = true; // Set the alarm as ringing

    while (!is_pushed_stop_button())
    {
        // Receives the noiseDetected value from the queue
        if (xQueueReceive(noiseQueue, &noiseDetected, 0))
        {
            if (noiseDetected)
            {
                ring_hard_sound(); // If there is noise, ring the hard sound
            }
            else
            {
                ring_soft_sound(); // If there is no noise, ring the soft sound
            }
        }
        else
        {
            // If the queue is empty, ring the soft sound
            ring_soft_sound();
        }
    }

    stop_sound();          // Stop the alarm
    clear_alarm();         // Clear the alarm set
    alarm_ringing = false; // Set the alarm as not ringing
    vTaskDelete(NULL);     // close this task
}

void verify_alarm_time_task(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        // Get the current time
        now = rtc.now();
        // If the alarm time is defined and the current time is equal to the alarm time, create the ring alarm task
        if (is_alarm_time() && ringAlarmTaskHandle == NULL)
        {
            xTaskCreate(ring_alarm_task, "Ring Alarm", 2048, NULL, 2, &ringAlarmTaskHandle);
            // showMessage("Alarm ringing", 1);
        }
        // If the stop button is pressed and the alarm is not ringing, clear the alarm
        if (is_pushed_stop_button() && !alarm_ringing)
        {
            clear_alarm(); // Clear the alarm set
        }

        vTaskDelay(500 / portTICK_PERIOD_MS); // Verify every 500ms
    }
}

void verify_moviment_task(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        if (is_moviment_detected() && alarm_ringing)
        {
            set_snooze_time(5);    // add 5 minutes to the snooze time
            stop_sound();          // stop the alarm
            alarm_ringing = false; // set the alarm as not ringing
            if (ringAlarmTaskHandle != NULL)
            {
                vTaskDelete(ringAlarmTaskHandle); // Delete the ringing task
                ringAlarmTaskHandle = NULL;
            }
        }
        vTaskDelay(200 / portTICK_PERIOD_MS); // Verifica a cada 200ms
    }
}

void verify_noise_task(void *pvParameters)
{
    (void)pvParameters;
    bool noiseDetected;
    for (;;)
    {
        noiseDetected = is_noise_detected();
        xQueueSend(noiseQueue, &noiseDetected, portMAX_DELAY); // send the noiseDetected value to the queue
        vTaskDelay(200 / portTICK_PERIOD_MS);                  // vefiry every 200ms
    }
}

void log(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        Serial.println("Moviment: " + String(is_moviment_detected()));
        Serial.println("Noise: " + String(is_noise_detected()));
        Serial.println("Button: " + String(is_pushed_stop_button()));
        Serial.println("Alarm Time Defined: " + String(alarm_hour) + ":" + String(alarm_minute) + ":" + String(alarm_second));
        Serial.println("-----------------------------------------");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Wait for 1000ms
    }
}