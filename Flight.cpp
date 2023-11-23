//
// Created by Qasim Amar on 2023-11-22.
//

#include "Flight.h"

using namespace std;

Flight::Flight(const string &flightId, int numRows, int numCols, const vector<Passenger> &passengers,
               const vector<vector<Seat>> &seatMap) : flightId(flightId), numRows(numRows), numCols(numCols),
                                                      passengers(passengers), seatMap(seatMap) {}

Flight::~Flight() {

}

const string &Flight::getFlightId() const {
    return flightId;
}

void Flight::setFlightId(const string &flightId) {
    Flight::flightId = flightId;
}

int Flight::getNumRows() const {
    return numRows;
}

void Flight::setNumRows(int numRows) {
    Flight::numRows = numRows;
}

int Flight::getNumCols() const {
    return numCols;
}

void Flight::setNumCols(int numCols) {
    Flight::numCols = numCols;
}

const vector<Passenger> &Flight::getPassengers() const {
    return passengers;
}

void Flight::setPassengers(const vector<Passenger> &passengers) {
    Flight::passengers = passengers;
}

const vector<vector<Seat>> &Flight::getSeatMap() const {
    return seatMap;
}

void Flight::setSeatMap(const vector<vector<Seat>> &seatMap) {
    Flight::seatMap = seatMap;
}
