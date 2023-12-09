#include "Passenger_Class.h"
#include <algorithm> // Include this for std::find and std::remove

// Define the lists for passengers
std::vector<Passenger> specialPassengersList;
std::vector<Passenger> wheelchairPassengersList;
std::vector<Passenger> passengersList;

// Implement member functions for the Passenger class as needed

bool Passenger::hasBeenOnBus() const {
    // Implement logic to check if the passenger has been on a bus
    // For example, return true if the passenger has been on a bus; otherwise, return false
    return false;
}

void Passenger::cancel() {
    // Implement logic to cancel the passenger
    // Update data structures/lists accordingly
    // For example, remove the passenger from the appropriate list

    // Use std::remove_if with erase to efficiently remove the passenger from the vectors
    specialPassengersList.erase(std::remove_if(specialPassengersList.begin(), specialPassengersList.end(),
                                               [this](const Passenger& p) { return p.getPassengerID() == this->getPassengerID(); }),
                                specialPassengersList.end());

    wheelchairPassengersList.erase(std::remove_if(wheelchairPassengersList.begin(), wheelchairPassengersList.end(),
                                                  [this](const Passenger& p) { return p.getPassengerID() == this->getPassengerID(); }),
                                   wheelchairPassengersList.end());

    passengersList.erase(std::remove_if(passengersList.begin(), passengersList.end(),
                                        [this](const Passenger& p) { return p.getPassengerID() == this->getPassengerID(); }),
                         passengersList.end());
}