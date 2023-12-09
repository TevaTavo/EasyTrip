#ifndef PASSENGER_CLASS_H
#define PASSENGER_CLASS_H

#include <string>
#include <vector>

// Enum for passenger types
enum class PassengerType {
    SP, // Special Passenger
    WP, // Wheelchair Passenger
    NP  // Normal Passenger
};

// Enum for station types
enum class StationType {
    BUS,
    TRAIN,
    AIRPORT
};

// Forward declarations
class Station;

// Class representing a station
class Station {
private:
    int stationID; // Unique identifier for the station
    StationType type; // Type of the station
    std::string name; // Name of the station

public:
    // Constructor and member functions as needed
    Station(int id, StationType t, std::string n) : stationID(id), type(t), name(n) {}
    int getStationID() const { return stationID; }
    StationType getType() const { return type; }
    std::string getName() const { return name; }
};

// Class representing a passenger
class Passenger {
private:
    int passengerID; // Unique identifier for the passenger
    PassengerType type; // Type of the passenger
    Station startStation; // Starting station of the passenger
    Station endStation; // Ending station of the passenger

public:
    // Constructor and member functions as needed
    Passenger(int id, PassengerType t, const Station& start, const Station& end)
        : passengerID(id), type(t), startStation(start), endStation(end) {}

    int getPassengerID() const { return passengerID; }
    PassengerType getType() const { return type; }
    const Station& getStartStation() const { return startStation; }
    const Station& getEndStation() const { return endStation; }

    // Additional member functions as needed
    bool hasBeenOnBus() const { /* implement as needed */ return false; }
    void cancel() { /* implement as needed */ }
};

// Lists for passengers
extern std::vector<Passenger> specialPassengersList;
extern std::vector<Passenger> wheelchairPassengersList;
extern std::vector<Passenger> passengersList;

#endif
