#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
public:
    char type;  // 'A' for arrival, 'D' for departure
    int time;   // The time of the event
    int transTime; // Transaction time, relevant for arrival events

    Event(char eventType = ' ', int eventTime = 0, int transactionTime = 0)
        : type(eventType), time(eventTime), transTime(transactionTime) {}

    bool operator>(const Event& other) const {
        return time > other.time;
    }

    bool operator==(const Event& other) const {
        return time == other.time && type == other.type && transTime == other.transTime;
    }

    bool operator!=(const Event& other) const {
        return time != other.time;
    }

    friend std::ostream& operator<<(std::ostream& os, const Event& event) {
        os << "Event Type: " << event.type << " Time: " << event.time << " Transaction Time: " << event.transTime;
        return os;
    }
};

#endif // EVENT_H
