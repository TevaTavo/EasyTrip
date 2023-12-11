#include "Time.h"

// Constructor
Time::Time(int h, int m) : hour(h), minute(m) {
    // Call overflow and underflow handlers to normalize time
    handleOverflow();
    handleUnderflow();
}

// Overload + operator
Time Time::operator+(const Time& t) const {
    Time temp;
    temp.hour = hour + t.hour;
    temp.minute = minute + t.minute;
    temp.handleOverflow();
    return temp;
}

// Overload - operator
Time Time::operator-(const Time& t) const {
    Time temp;
    temp.hour = hour - t.hour;
    temp.minute = minute - t.minute;
    temp.handleUnderflow();
    return temp;
}

// Function to handle time overflow (when minutes exceed 60)
void Time::handleOverflow() {
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
}

// Function to handle time underflow (when minutes are negative)
void Time::handleUnderflow() {
    if (minute < 0) {
        int borrowHours = (-minute + 59) / 60;
        hour -= borrowHours;
        minute += borrowHours * 60;
    }
}

// Display the time
void Time::display() const {
    std::cout << "Time: " << hour << " hours, " << minute << " minutes" << std::endl;
}
