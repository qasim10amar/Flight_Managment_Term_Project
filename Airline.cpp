//
// Created by Qasim Amar on 2023-11-22.
//

#include "Airline.h"

Airline::Airline(const string &name, const vector<Flight> &flightList, int numFlight) : name(name),
                                                                                        flightList(flightList),
                                                                                        numFlight(numFlight) {
}

Airline::Airline(const string &name) : name(name) {

}

Airline::~Airline() {

}

const string &Airline::getName() const {
    return name;
}

const vector<Flight> &Airline::getFlightList() const {
    return flightList;
}

int Airline::getNumFlight() const {
    return numFlight;
}

void Airline::setFlightList(const vector<Flight> &flightList) {
    Airline::flightList = flightList;
}

void Airline::setNumFlight(int numFlight) {
    Airline::numFlight = numFlight;
}
