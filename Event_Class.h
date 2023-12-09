#ifndef EVENT_CLASS_H
#define EVENT_CLASS_H

#include "Passenger_Class.h" // Assuming you have Passenger_Class.h defined

class Event {
protected:
    int eventTime;
    Passenger passengerInfo;

public:
    Event(int eventTime, const Passenger& passengerInfo)
        : eventTime(eventTime), passengerInfo(passengerInfo) {}

    int getEventTime() const {
        return eventTime;
    }

    const Passenger& getPassengerInfo() const {
        return passengerInfo;
    }

    virtual void Execute() = 0;
};

class ArrivalEvent : public Event {
private:
    PassengerType passengerType;
    Station startStation;
    Station endStation;

public:
    ArrivalEvent(int eventTime, const Passenger& passengerInfo, PassengerType passengerType, Station startStation, Station endStation)
        : Event(eventTime, passengerInfo), passengerType(passengerType), startStation(startStation), endStation(endStation) {}

    PassengerType getPassengerType() const {
        return passengerType;
    }

    const Station& getStartStation() const {
        return startStation;
    }

    const Station& getEndStation() const {
        return endStation;
    }

    void Execute() override;
};

class LeaveEvent : public Event {
private:
    Station startStation;

public:
    LeaveEvent(int eventTime, const Passenger& passengerInfo, Station startStation)
        : Event(eventTime, passengerInfo), startStation(startStation) {}

    const Station& getStartStation() const {
        return startStation;
    }

    void Execute() override;
};

#endif
