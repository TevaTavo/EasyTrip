#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hour;
    int minute;

public:
    // Constructor
    Time(int h = 0, int m = 0);

    // Overload + operator
    Time operator+(const Time& t) const;

    // Overload - operator
    Time operator-(const Time& t) const;

    // Function to handle time overflow
    void handleOverflow();

    // Function to handle time underflow
    void handleUnderflow();

    // Display the time
    void display() const;
};

#endif
