//
// Created by Qasim Amar on 2023-11-22.
//

#include "Flight.h"
#include "Seat.h"
#include <iomanip>

using namespace std;
Flight::Flight(const string &flightId, int numRows, int numCols, const vector<Passenger> &passengers) : flightId(flightId), numRows(numRows), numCols(numCols),passengers(passengers)
{
    seatMap.resize(numRows, vector<Seat>(numCols));

    // Update seats based on passenger information
    for (const Passenger &passenger : passengers) {
        // Extract row and column from the seat assignment (assuming the format is consistent)
        int row = passenger.getSeat()->getRowNum(); // Convert the row character to integer
        char col = passenger.getSeat()->getColNum(); // Extract the column character

        // Update the corresponding seat based on row and column
        seatMap[row][col - 'A'].setSeatStatus(true);
    }

}

void Flight::printSeatMap() const {
    // Print header with column letters
    cout << "   ";
    for (char col = 'A'; col < 'A' + numCols; ++col) {
        cout << "  " << col << " ";
    }
    cout << endl;

    // Print seat map
    for (int row = 0; row < numRows; ++row) {
        cout << "   +";
        for (int col = 0; col < numCols; ++col) {
            cout << "---+";
        }
        cout << endl;

        cout << setw(2) << row << " |";
        for (int col = 0; col < numCols; ++col) {
            if (seatMap[row][col].isSeatStatus()) {
                cout << " X |";
            } else {
                cout << "   |";
            }
        }
        cout << endl;
    }

    cout << "   +";
    for (int col = 0; col < numCols; ++col) {
        cout << "---+";
    }
    cout << endl;
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

int Flight::getNumCols() const {
    return numCols;
}

const vector<Passenger> &Flight::getPassengers() const {
    return passengers;
}

void Flight::setPassengers(const vector<Passenger> &passengers) {
    Flight::passengers = passengers;
    // Update seats based on passenger information
    for (const Passenger &passenger : passengers) {
        // Extract row and column from the seat assignment (assuming the format is consistent)
        int row = passenger.getSeat()->getRowNum(); // Convert the row character to integer
        char col = passenger.getSeat()->getColNum(); // Extract the column character

        // Update the corresponding seat based on row and column
        seatMap[row][col - 'A'].setSeatStatus(true);
    }
}

const vector<vector<Seat>> &Flight::getSeatMap() const {
    return seatMap;
}

void Flight::setSeatMap(const vector<vector<Seat>> &seatMap) {
    Flight::seatMap = seatMap;
}

