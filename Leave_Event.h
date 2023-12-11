#ifndef _LEAVE_EVENT_H_
#define _LEAVE_EVENT_H_

#include "Event_Class.h"
#include "Passenger_Class.h"

// Defines the LeaveEvent class derived from Event
class LeaveEvent : public Event {
public:
    LeaveEvent();
    int getLeaveHour() const;
    int getLeaveMinute() const;
    void Excute(const Passenger& P, PriorityQueue& Q, Event& E, Clock& c);
};

#endif
