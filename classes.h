#ifndef classs
#define classes
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//-----------------------passnger class
class Passenger {
public:
    char event;
    int id;
    string type;
    int time;
    int min;
    int startStation;
    int endStation;
    string sp_type;
};
//-------------------------Bus class
class Bus {
public:
    int count;
    int capacity;
    int BC;
    int checkup;
    int checkuptime;
};
//--------------------------station class
class station {
public :
    int number;
    bool main;
    vector<Passenger> inpassngers;
    vector<Passenger> inwpassngers;

    void addPassenger(const vector<Passenger>& passengers, int stationNum) {
        for (const auto& pass : passengers) {
            if (pass.startStation == stationNum) {
                if (pass.type == "WP") {
                    inwpassngers.push_back(pass);
                }
                else {
                    inpassngers.push_back(pass);
                }
            }
        }
    }
    void printStationInfo() const {
        cout << "Station Number: " << number << endl;
        cout << "Is Main Station: " << (main ? "Yes" : "No") << endl;
        cout << "\nIn Passengers:" << endl;
        for (const auto& passenger : inpassngers) {
            cout << "ID: " << passenger.id << ", Type: " << passenger.type << ", Event: " << passenger.event << endl;
        }

        cout << "\nIn WPassengers:" << endl;
        for (const auto& passenger : inwpassngers) {
            cout << "ID: " << passenger.id << ", Type: " << passenger.type << ", Event: " << passenger.event << endl;
            
        }
    }
};

//--------------------------- similationinfo class
class SimulationInfo {
public:
    int numStations;
    int timeBetweenStations;
    Bus wheelBus;
    Bus mixedBus;
    int numTripsBeforeCheckup;
    int checkupTimeW;
    int checkupTimeM;
    int maxWaitingTime;
    int getOnOffTime;
    int numEvents;

    SimulationInfo() : numStations(0), timeBetweenStations(0), numTripsBeforeCheckup(0), checkupTimeW(0), checkupTimeM(0), maxWaitingTime(0), getOnOffTime(0), numEvents(0) {}
};
//---------------------------company 
class company {};
//--------------------------UI
class UI {};


#endif