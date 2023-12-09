#include "Event_Class.h"
#include "Passenger_Class.h"
#include <vector>  // Include the necessary header for using vectors

std::vector<Passenger> specialPassengersList;  // Assuming these are defined somewhere
std::vector<Passenger> wheelchairPassengersList;
std::vector<Passenger> passengersList;

    // Derived class ArrivalEvent
void ArrivalEvent::Execute() {
    // Create a new passenger and add it to the appropriate list
    Passenger newPassenger(/* provide necessary arguments for the constructor */);

    // Add newPassenger to the appropriate list based on passengerType
    if (newPassenger.getType() == PassengerType::SP) {
        specialPassengersList.push_back(newPassenger);
    } else if (newPassenger.getType() == PassengerType::WP) {
        wheelchairPassengersList.push_back(newPassenger);
    } else {
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
            break; // Stop searching after canceling the first matching passenger
        }
    }
}
