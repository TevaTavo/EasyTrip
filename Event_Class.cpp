#include "Event_Class.h"


// Default constructor initializing event type to an empty string
Event::Event() {
    eventType = "";
}

// Accessor for event type
string Event::getEventType() const {
    return eventType;
}

// Default implementation of Execute, does nothing
void Event::Excute() {} 
