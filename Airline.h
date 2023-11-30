//
// Created by Qasim Amar on 2023-11-22.
//
#include <string>
#include "Flight.h"

using namespace std;
#ifndef AMAR_TERM_PROJECT_AIRLINE_H
#define AMAR_TERM_PROJECT_AIRLINE_H


class Airline {
public:
    Airline(const string &name, const vector<Flight> &flightList, int numFlight);
    Airline(const string &name);

    ~Airline();

    const string &getName() const;

    vector<Flight> &getFlightList();

    int getNumFlight() const;

    void setFlightList(const vector<Flight> &flightList);

    void setNumFlight(int numFlight);

private:
    const string name;
    vector<Flight> flightList;
    int numFlight;
};


#endif //AMAR_TERM_PROJECT_AIRLINE_H
