#include "Event_Class.h"
#include "Company.h"
#include "Time.h"
#include "Passenger_Class.h" // Include the missing header file

#include <sstream>

Event::Event(TimeClass eventTime, PassengerClass* P, CompanyClass* C)
    : eventTime(eventTime), P(P), C(C) {
}

void Event::setCompany(CompanyClass* company) {
    this->C = company;
}

void Event::setPassenger(PassengerClass* passenger) {
    this->P = passenger;
}

void Event::setEventQueue(Queue<std::vector<std::string>> eventQueue) {
    this->eventQueue = eventQueue;
}

void Event::setFile(std::string filename) {
    this->file = filename;
}

CompanyClass* Event::getCompany() {
    return C;
}

PassengerClass* Event::getPassenger() {
    return P;
}

Queue<std::vector<std::string>> Event::getEventQueue() {
    return eventQueue;
}

std::string Event::getFile() {
    return file;
}

ArriveEvent::ArriveEvent(TimeClass ArrivalTime, PassengerClass* P, CompanyClass* C)
    : Event(ArrivalTime, P, C) {
}

void ArriveEvent::execute() {
    C->addPassenger(P);
}

LeaveEvent::LeaveEvent(TimeClass LeaveTime, PassengerClass* P, CompanyClass* C)
    : Event(LeaveTime, P, C) {
}

void LeaveEvent::execute() {
    C->leavePassenger(P);
}

void processEvent(std::string filename, TimeClass Time, CompanyClass* company) {
    FileHandler file(filename);
    Queue<std::vector<std::string>> eventQueue = file.processEventLines();

    while (!eventQueue.isEmpty()) {
        std::vector<std::string> line = eventQueue.frontElement();
        std::string eventType = line[0];

        if (eventType == "A") {
            std::string PassengerType = line[1];
            std::istringstream iss(line[2]);
            std::string arrivaltime;

            std::getline(iss, arrivaltime, ':');
            int hours = std::stoi(arrivaltime);

            std::getline(iss, arrivaltime);
            int minutes = std::stoi(arrivaltime);

            TimeClass ArrivalTime(hours, minutes); // Use TimeClass

            int PassengerID = std::stoi(line[3]);
            int StartStation = std::stoi(line[4]);
            int EndStation = std::stoi(line[5]);
            std::string statue = line[6];
            if (Time == ArrivalTime) {
                auto* P = new PassengerClass(ArrivalTime, StartStation, EndStation, PassengerID, PassengerType, statue);

                ArriveEvent arriveEvent(ArrivalTime, P, company);
                delete P;
                arriveEvent.execute();
                eventQueue.dequeue();
            }
        } else if (eventType == "L") {
            std::istringstream iss(line[1]);

            std::string arrivaltime;

            std::getline(iss, arrivaltime, ':');
            int hours = std::stoi(arrivaltime);

            std::getline(iss, arrivaltime);
            int minutes = std::stoi(arrivaltime);

            TimeClass leaveTime(hours, minutes); // Use TimeClass
            if (Time == leaveTime) {
                PassengerClass* P = company->getPassengerByID(std::stoi(line[2]));
                LeaveEvent leaveEvent(leaveTime, P, company);

                leaveEvent.execute();
                eventQueue.dequeue();
            }
        } else {
            break;
        }
        std::cerr << "Invalid event type: " << eventType << std::endl;
    }
}
