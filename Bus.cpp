#include "Bus.h"

// Constructor
Bus::Bus() : timeStep(0), status(' '), direction(""), counter(0) {}

// Setters
void Bus::setTimeStep(int x) { timeStep = x; }
void Bus::setStatus(char x) { status = x; }
void Bus::setDirection(const std::string& x) { direction = x; }
void Bus::setCounter(int x) { counter = x; }

// Getters
int Bus::getTimeStep() const { return timeStep; }
char Bus::getStatus() const { return status; }
std::string Bus::getDirection() const { return direction; }
int Bus::getCounter() const { return counter; }

// Other functionalities
void Bus::addPassenger(Passenger* passenger, int p) {
    onBoard.enqueue(passenger, p);
}

void Bus::removePassenger() {
    if (!onBoard.isEmpty()) {
        Passenger* p = onBoard.frontElement();
        onBoard.dequeue();
        // Be careful with memory management. Ensure that you manage the memory for Passenger objects correctly.
        delete p;
    }
}
