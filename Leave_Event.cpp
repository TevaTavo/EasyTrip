#include "Leave_Event.h"

// Default constructor initializing leave time to zero
LeaveEvent::LeaveEvent() : Event() {
    leaveHour = 0;
    leaveMinute = 0;
}

// Accessor for leave hour
int LeaveEvent::getLeaveHour() const {
    return leaveHour;
}

// Accessor for leave minute
int LeaveEvent::getLeaveMinute() const {
    return leaveMinute;
}

// Executes the leave event based on event type and leave time
void LeaveEvent::Excute(const Passenger& P, PriorityQueue& Q, Event& E, Clock& c) {
    const string& eventType = E.getEventType();
    int hour = c.getHour();
    int minute = c.getMinute();
    if (eventType == "L" && leaveHour == hour && leaveMinute == minute) {
        Q.dequeueSpecific(P.getId());
    }
}
