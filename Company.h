//
// Created by musta on 12/11/2023.
//

#ifndef COMPANY_H
#define COMPANY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "PQueue.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Passenger_Class.h"
#include "Bus.h"
#include "Time.h"

using namespace std;

class Company {
    int numberStations, Timediff, WBusNumber, MBusNumber, Wcapacity, Mcapacity, numberjur, CheckW, CheckM, maxWaiting, getOnOffTime, Events, ID;
    Time T;
    string event_type, passenger_type, beforeT, SP_type, START, END;
    Queue<Passenger> AWP;
    PriorityQueue<Passenger> AP;
    Queue<Passenger> LP;

    void loadInputFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file";
            return;
        }

        inputFile >> numberStations >> Timediff >> WBusNumber >> MBusNumber >> Wcapacity >> Wcapacity >> numberjur >> CheckW >> CheckM >> maxWaiting >> getOnOffTime >> Events;
        for (int i = 0; i < Events; i++) {
            inputFile >> event_type;
            if (event_type == "A") {
                inputFile >> passenger_type;
                inputFile >> beforeT;
                size_t colonPos = beforeT.find(':');
                int hours = stoi(beforeT.substr(0, colonPos));
                int min = stoi(beforeT.substr(colonPos + 1));
                Time Temp(hours, min);
                T = Temp;
                inputFile >> ID >> START >> END;
                SP_type = "";
                if (passenger_type == "WP") {
                    Passenger new_passenger(T, stoi(START), stoi(END), ID, passenger_type, SP_type);
                    AWP.enqueue(new_passenger);
                } else {
                    Passenger new_passenger(T, stoi(START), stoi(END), ID, passenger_type, SP_type);
                    int priority = new_passenger.calculatePriority();
                    AP.enqueue(new_passenger, priority);
                }
                if (passenger_type == "SP") {
                    inputFile >> SP_type;
                    Passenger new_passenger(T, stoi(START), stoi(END), ID, passenger_type, SP_type);
                    int priority = new_passenger.calculatePriority();
                    AP.enqueue(new_passenger, priority);
                }
            } else if (event_type == "L") {
                inputFile >> beforeT;
                size_t colonPos = beforeT.find(':');
                int hours = stoi(beforeT.substr(0, colonPos));
                int min = stoi(beforeT.substr(colonPos + 1));
                Time Temp(hours, min);
                T = Temp;
                inputFile >> ID >> START;
                Passenger new_passenger(T, stoi(START), 0, ID, "", "");
                LP.enqueue(new_passenger);
            }
        }
        inputFile.close();
    }
};

#endif //COMPANY_H
