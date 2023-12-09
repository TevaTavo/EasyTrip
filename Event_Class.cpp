#include "Event_Class.h"
#include "Passenger_Class.h"
#include <vector>  // Include the necessary header

using namespace std;  // Use the standard namespace
// Lists for passengers
vector<Passenger> specialPassengersList;
vector<Passenger> wheelchairPassengersList;
vector<Passenger> passengersList;

// Derived class ArrivalEvent
void ArrivalEvent::Execute() {
    // Create a new passenger and add it to the appropriate list
    Passenger newPassenger(Passenger newPassenger(1, PassengerType::SP, Station(1, StationType::BUS, "Bus Station"), Station(2, StationType::TRAIN, "Train Station"));
);

    // Add newPassenger to the appropriate list
    if (newPassenger.getType() == PassengerType::SP) {
        specialPassengersList.push_back(newPassenger);
    }
    else if (newPassenger.getType() == PassengerType::WP) {
        wheelchairPassengersList.push_back(newPassenger);
    }
    else {
        passengersList.push_back(newPassenger);
    }
}

// Derived class LeaveEvent
void LeaveEvent::Execute() {
    // Cancel the requested normal passenger (if found and hasn’t been on a bus yet)
    // Find the requested normal passenger
    for (Passenger& passenger : passengersList) {
        if (passenger.getType() == PassengerType::NP && !passenger.hasBeenOnBus()) {
            // If found and hasn't been on a bus yet, cancel the passenger
            passenger.cancel();
            break;  // Stop searching after canceling the first matching passenger
        }
    }
}
