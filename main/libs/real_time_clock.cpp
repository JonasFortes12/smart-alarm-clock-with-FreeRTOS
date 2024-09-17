#include "Wire.h"
#include "RTClib.h"


RTC_DS3231 rtc; // Initialize an instance of the RTCDS3231 class

DateTime now; // Create a DateTime object to hold the current time


// Alarm time configuration
int alarm_hour = NULL;
int alarm_minute = NULL;
int alarm_second = NULL;
int alarm_defined = false;
int alarm_ringing = false;
int snooze_time = 5;

// Function to setup the RTC
void rtc_setup(){
    
    Wire.begin();

    if (!rtc.begin()) {
        Serial.println("RTC not detected");
    }

}

// Function to format numbers with two digits
String print_two_digits(int number) {
    if (number < 10) {
        return "0" + String(number);
    }
    return String(number);
}

// Function to get the current time as a string
String get_time() {
    String time = "";
    time += print_two_digits(now.hour()) + ":";
    time += print_two_digits(now.minute()) + ":";
    time += print_two_digits(now.second());
    return time;
}

// Function to get the current date as a string
String get_date() {
    String date = "";
    date += String(now.year()) + "/";
    date += print_two_digits(now.month()) + "/";
    date += print_two_digits(now.day());
    return date;
}

// Function to set the initial date and time on the RTC
void set_time() {
    rtc.adjust(DateTime(__DATE__, __TIME__)); // Set RTC time to compile time
}

// Function to set the alarm time
void set_alarm_time(int hour, int minute, int second, int snooze){
    alarm_hour = hour;
    alarm_minute = minute;
    alarm_second = second;
    snooze_time = snooze;
    alarm_defined = true;
}

// Function to clear the alarm
void clear_alarm() {
    alarm_hour = NULL;
    alarm_minute = NULL;
    alarm_second = NULL;
    alarm_defined = false;
}

// Function to check if the alarm time has been reached
bool is_alarm_time() {
    if (alarm_defined) {
        if (now.hour() == alarm_hour && now.minute() == alarm_minute && now.second() == alarm_second) {
            return true;
        }
    }
    return false;
}

// Function to set the snooze time
void set_snooze_time(int minutes){
    Serial.println("Snooze time set to " + String(minutes) + " minutes");
    alarm_minute += minutes;
    if(alarm_minute >= 60){
        alarm_minute -= 60;
        alarm_hour++;
        if(alarm_hour >= 24){
            alarm_hour = 0;
        }
    }
}