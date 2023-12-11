#ifndef EASYTRIP_PASSENGER_H
#define EASYTRIP_PASSENGER_H
#include "Time.h"

#include <string>

class Passenger {
private:
    Time Arrival;
    Time Departure;
    int OriginStation;
    int DestinationStation;
    int ID;
    const Time BoardingDuration = Time(0, 10);
    std::string Type;
    std::string Status;

public:
    // Constructors
    Passenger();
    Passenger(Time arrival, const int& origin, const int& destination, int id, const std::string& type, const std::string& status);

    // Accessors
    Time getArrival() const;
    Time getDeparture() const;
    int getOriginStation() const;
    int getDestinationStation() const;
    int getID() const;
    Time getBoardingDuration() const;
    std::string getType() const;
    std::string getStatus() const;

    // Mutators
    void setArrival(Time arrival);
    void setDeparture(Time departure);
    void setOriginStation(const int& origin);
    void setDestinationStation(const int& destination);
    void setType(const std::string& type);
    void setStatus(const std::string& status);
    void setID(int id);

    // Additional methods
    int calculatePriority() const;

    // Operator Overloading
    bool operator==(const Passenger& other) const;
};

#endif // EASYTRIP_PASSENGER_H
