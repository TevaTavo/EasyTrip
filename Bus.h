#ifndef UNTITLED1_BUS_H
#define UNTITLED1_BUS_H

#include <string>
#include "PQueue.h"
#include "Passenger_Class.h"  // Update the include to match your Passenger class

class Bus {
private:
    PriorityQueue<Passenger*> onBoard;  // Updated to use Passenger pointers
    int timeStep;
    char status;
    std::string direction;
    int counter;

public:
    Bus(); // Constructor

    // Setters
    void setTimeStep(int x);
    void setStatus(char x);
    void setDirection(const std::string& x);
    void setCounter(int x);

    // Getters
    int getTimeStep() const;
    char getStatus() const;
    std::string getDirection() const;
    int getCounter() const;

    // Other functionalities
    void addPassenger(Passenger* passenger, int p);
    void removePassenger();
};

#endif // UNTITLED1_BUS_H
