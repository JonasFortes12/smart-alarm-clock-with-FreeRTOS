#include "services.cpp"


void setup_modules_services();

// task for updating the time on the LCD using showMessage function
void update_time_on_lcd_task(void *pvParameters);

// task for verifying if the alarm time has arrived
void verify_alarm_time_task(void *pvParameters);

// task for ringing the alarm
void ring_alarm_task(void *pvParameters);

// task for verifying the PIR sensor, if there is a movement, it will ring the hard sound
void verify_noise_task(void *pvParameters);

// task for verifying the noise sensor, if there is a noise, it will set snooze time to 5 minutes
void verify_moviment_task(void *pvParameters);

// task for logging the system status
void log(void *pvParameters);