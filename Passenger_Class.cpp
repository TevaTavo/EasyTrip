#include "Passenger_Class.h"

// Constructors
Passenger::Passenger() {}

Passenger::Passenger(Time arrival, const int& origin, const int& destination, int id, const std::string& type, const std::string& status)
    : Arrival(arrival), OriginStation(origin), DestinationStation(destination), ID(id), Type(type), Status(status) {}

// Accessors
Time Passenger::getArrival() const {
    return Arrival;
}

Time Passenger::getDeparture() const {
    return Departure;
}

int Passenger::getOriginStation() const {
    return OriginStation;
}

int Passenger::getDestinationStation() const {
    return DestinationStation;
}

int Passenger::getID() const {
    return ID;
}

Time Passenger::getBoardingDuration() const {
    return BoardingDuration;
}

std::string Passenger::getType() const {
    return Type;
}

std::string Passenger::getStatus() const {
    return Status;
}

// Mutators
void Passenger::setArrival(Time arrival) {
    Arrival = arrival;
}

void Passenger::setDeparture(Time departure) {
    Departure = departure;
}

void Passenger::setOriginStation(const int& origin) {
    OriginStation = origin;
}

void Passenger::setDestinationStation(const int& destination) {
    DestinationStation = destination;
}

void Passenger::setType(const std::string& type) {
    Type = type;
}

void Passenger::setStatus(const std::string& status) {
    Status = status;
}

void Passenger::setID(int id) {
    ID = id;
}

// Additional methods
int Passenger::calculatePriority() const {
    if (getType() == "SP") {
        if (getStatus() == "Aged") {
            return 4;
        } else if (getStatus() == "POD") {
            return 3;
        } else if (getStatus() == "Pregnant") {
            return 2;
        }
    }
    return 1;
}

// Operator Overloading
bool Passenger::operator==(const Passenger& other) const {
    return calculatePriority() == other.calculatePriority();
}
