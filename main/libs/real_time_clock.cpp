#include "Wire.h"
#include "RTClib.h"


RTC_DS3231 rtc; // Initialize an instance of the RTCDS3231 class

DateTime now; // Create a DateTime object to hold the current time


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

