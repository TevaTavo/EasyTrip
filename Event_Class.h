#ifndef _EVENT_H_
#define _EVENT_H_

#include <string> 

// Base class for different types of events
class Event {
public:
    Event();
    virtual std::string getEventType() const = 0; 
    virtual void Excute() = 0;
};

#endif
