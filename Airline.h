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

    ~Airline();

    const string &getName() const;

    const vector<Flight> &getFlightList() const;

    int getNumFlight() const;

    void setName(const string &name);

    void setFlightList(const vector<Flight> &flightList);

    void setNumFlight(int numFlight);

private:
    string name;
    vector<Flight> flightList;
    int numFlight;
};


#endif //AMAR_TERM_PROJECT_AIRLINE_H
