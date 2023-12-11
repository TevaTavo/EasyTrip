#include "Arrival_Event.h"

// Default constructor initializing arrival time to zero
ArrivalEvent::ArrivalEvent() : Event() {
    arrivalHour = 0;
    arrivalMinute = 0;
}

// Accessor for arrival hour
int ArrivalEvent::getArrivalHour() const {
    return arrivalHour;
}

// Accessor for arrival minute
int ArrivalEvent::getArrivalMinute() const {
    return arrivalMinute;
}

// Executes the arrival event based on passenger type and arrival time
void ArrivalEvent::Excute(const Passenger& P, Queue& Q, Event& E, PriorityQueue& PQ, Clock& c) {
    const string& eventType = E.getEventType();
    const string& passType = P.getPassengerType();
    int hour = c.getHour();
    int minute = c.getMinute();
    if (eventType != "L" && passType == "W" && arrivalHour == hour && arrivalMinute == minute) {
        Q.enqueue(P.getId());
    } else if (eventType != "L" && passType != "W" && arrivalHour == hour && arrivalMinute == minute) {
        PQ.enqueue(P.getId(), P.getPriority());
    }
}
