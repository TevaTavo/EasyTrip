#include <iostream>
#include <fstream>
#include <sstream>
#include "Event_Class.h"
#include "LinkedList.h"
#include "stations.h" // ITS NOT AVAILABLE YET
using namespace std;

int main() {
    // Create an instance of the Company class
    Company company;

    // Access the events list from the Company class
    LinkedList<Events*>& eventsList = company.getEventsList();

    // Print the events list (optional)
    company.printEvent();

    // Iterate through the events list and execute each event
    Node<Events*>* current = eventsList.getHead();
    while (current != nullptr) {
        Events* currentEvent = current->getItem();
        cout << currentEvent->getid();
        // Execute the event (uncomment the following lines once execute() method is implemented)
        if (currentEvent->execute()->getType() == "NP" || currentEvent->execute()->getType() == "WP") {
            S.AddPassanger(currentEvent->execute());
        } else if (currentEvent->execute()->getType() == "SP") {
            S.addSpecialPassanger(currentEvent->execute());
        }
        current = current->getNext();
    }
    
    // Optionally, print the stations' information (uncomment the following lines once execute() is implemented)
    S.PrintAllStations();

    return 0;
}
