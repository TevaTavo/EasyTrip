#ifndef EASYTRIP_EVENTCLASS_H
#define EASYTRIP_EVENTCLASS_H

#include "Time.h"
#include "Passenger_Class.h"
#include "Bus.h"
#include "Queue.h"

class Company; // Forward declaration for Company class

class Event {
public:
    virtual ~Event() = default;
    Event(Time eventTime, Passenger* passenger, Company* company)
        : eventTime(eventTime), P(passenger), C(company) {}

    virtual void execute() = 0;

protected:
    Time eventTime;
    Passenger* P;
    Company* C;
};

class ArriveEvent : public Event {
public:
    ArriveEvent(Time arrivalTime, Passenger* passenger, Company* company)
        : Event(arrivalTime, passenger, company) {}

    void execute() override;
};

class LeaveEvent : public Event {
public:
    LeaveEvent(Time leaveTime, Passenger* passenger, Company* company)
        : Event(leaveTime, passenger, company) {}

    void execute() override;
};

#endif //EASYTRIP_EVENTCLASS_H
