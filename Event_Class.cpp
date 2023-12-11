#include "Event_Class.h"
#include "Passenger_Class.h"
#include <iostream>
#include <algorithm> // Include for std::find_if

using namespace std;

extern vector<Passenger> specialPassengersList;
extern vector<Passenger> wheelchairPassengersList;
extern vector<Passenger> passengersList;

// Helper function to map string to PassengerType
PassengerType ArrivalEvent::MapStringToPassengerType(const std::string& typeString) {
    if (typeString == "SP") {
        return PassengerType::SP;
    } else if (typeString == "WP") {
        return PassengerType::WP;
    } else {
        return PassengerType::NP;
    }
}

// Constructor for ArrivalEvent
ArrivalEvent::ArrivalEvent(const Passenger& passenger) : newPassenger(passenger) {}

// Execute method for ArrivalEvent
void ArrivalEvent::Execute() {
    if (newPassenger.getType() == PassengerType::SP) {
        specialPassengersList.push_back(newPassenger);
    } else if (newPassenger.getType() == PassengerType::WP) {
        wheelchairPassengersList.push_back(newPassenger);
    } else {
        passengersList.push_back(newPassenger);
    }

    cout << "Arrival Event: Passenger " << newPassenger.getPassengerID() << " arrived at station "
         << newPassenger.getStartStation().getStationID() << " to go to station "
         << newPassenger.getEndStation().getStationID() << endl;
}

// Constructor for LeaveEvent
LeaveEvent::LeaveEvent(const Passenger& passenger) : leavePassenger(passenger) {}

// Execute method for LeaveEvent
void LeaveEvent::Execute() {
    auto removePassenger = [&](vector<Passenger>& list) {
        auto it = find_if(list.begin(), list.end(), [&](const Passenger& p) {
            return p.getPassengerID() == leavePassenger.getPassengerID();
        });
        if (it != list.end() && !it->hasBeenOnBus()) {
            list.erase(it);
            cout << "Leave Event: Passenger " << leavePassenger.getPassengerID() << " at station "
                 << leavePassenger.getStartStation().getStationID() << " has left." << endl;
            return true;
        }
        return false;
    };

    if (!removePassenger(specialPassengersList) && !removePassenger(wheelchairPassengersList) && !removePassenger(passengersList)) {
        cout << "Leave Event: No action taken for Passenger " << leavePassenger.getPassengerID() << endl;
    }
}
