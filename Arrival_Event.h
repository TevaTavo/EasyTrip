#ifndef _ARRIVAL_EVENT_H_
#define _ARRIVAL_EVENT_H_

#include "Event_Class.h"
#include "Passenger_Class.h"
#include "Queue.h"

// Defines the ArrivalEvent class derived from Event
class ArrivalEvent : public Event {
public:
    ArrivalEvent();
    int getArrivalHour() const;
    int getArrivalMinute() const;
    void Excute(const Passenger& P, Queue& Q, Event& E, PriorityQueue& PQ, Clock& c);
};

#endif
