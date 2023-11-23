//
// Created by Qasim Amar on 2023-11-22.
//

#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "Seat.h"

using namespace std;

#ifndef AMAR_TERM_PROJECT_FLIGHT_H
#define AMAR_TERM_PROJECT_FLIGHT_H


class Flight {
private:

    string flightId;
    int numRows;
    int numCols;
    vector<Passenger> passengers;
    vector<vector<Seat>> seatMap;

public:
    Flight(const string &flightId, int numRows, int numCols, const vector<Passenger> &passengers,
           const vector<vector<Seat>> &seatMap);

    ~Flight();

    const string &getFlightId() const;

    void setFlightId(const string &flightId);

    int getNumRows() const;

    void setNumRows(int numRows);

    int getNumCols() const;

    void setNumCols(int numCols);

    const vector<Passenger> &getPassengers() const;

    void setPassengers(const vector<Passenger> &passengers);

    const vector<vector<Seat>> &getSeatMap() const;

    void setSeatMap(const vector<vector<Seat>> &seatMap);


};


#endif //AMAR_TERM_PROJECT_FLIGHT_H
