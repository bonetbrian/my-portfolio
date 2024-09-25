#ifndef BANK_SIMULATION_H
#define BANK_SIMULATION_H

#include <iostream>
#include <fstream>
#include <queue>
#include "SL_PriorityQueue.h"
#include "Event.h"

using namespace std;

class BankSimulation {
private:
    SL_PriorityQueue<Event> eventQueue;
    queue<Event> bankQueue;
    int numCustomers;
    int totalWaitingTime;

public:
    BankSimulation() : numCustomers(0), totalWaitingTime(0) {}

    void processArrival(const Event& arrivalEvent) {
        numCustomers++;
        if (bankQueue.empty()) {
            int departureTime = arrivalEvent.time + arrivalEvent.transTime;
            eventQueue.add(Event('D', departureTime));
        }
        bankQueue.push(arrivalEvent);
    }

    void processDeparture(const Event& departureEvent) {
        if (!bankQueue.empty()) {
            Event customer = bankQueue.front();
            bankQueue.pop();
            totalWaitingTime += departureEvent.time - customer.time;
            if (!bankQueue.empty()) {
                Event nextCustomer = bankQueue.front();
                int departureTime = departureEvent.time + nextCustomer.transTime;
                eventQueue.add(Event('D', departureTime));
            }
        }
    }

    void readEventsFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        int arrivalTime, transactionTime;
        while (infile >> arrivalTime >> transactionTime) {
            eventQueue.add(Event('A', arrivalTime, transactionTime));
        }

        infile.close();
    }

    void runSimulation() {
        while (!eventQueue.isEmpty()) {
            Event currentEvent = eventQueue.peek();
            eventQueue.remove();

            if (currentEvent.type == 'A') {
                processArrival(currentEvent);
            }
            else {
                processDeparture(currentEvent);
            }
        }
    }

    void printStatistics() const {
        cout << "Total number of customers: " << numCustomers << endl;
        cout << "Average waiting time: " << (numCustomers ? (totalWaitingTime / numCustomers) : 0) << endl;
    }
};

#endif // BANK_SIMULATION_H
