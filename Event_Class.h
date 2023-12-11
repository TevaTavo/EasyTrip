#ifndef EVENT_CLASS_H
#define EVENT_CLASS_H

#include <vector>
#include "classes.h"

enum class PassengerType { SP, WP, NP }; // Define PassengerType enum

class Event {
public:
    virtual void Execute() = 0; // Virtual function to be implemented by derived classes
    virtual ~Event() = default; // Virtual destructor for polymorphic behavior
};

class ArrivalEvent : public Event {
private:
    PassengerType MapStringToPassengerType(const std::string& typeString);

public:
    ArrivalEvent(const Passenger& passenger);
    void Execute() override;

private:
    Passenger newPassenger;
};

class LeaveEvent : public Event {
public:
    LeaveEvent(const Passenger& passenger);
    void Execute() override;

private:
    Passenger leavePassenger;
};

#endif
