//
// Created by Qasim Amar on 2023-11-22.
//

#include "Flight.h"
#include "Seat.h"
#include <iomanip>

using namespace std;
Flight::Flight(const string &flightId, int numRows, int numCols, const vector<Passenger> &passengers) : flightId(flightId), numRows(numRows), numCols(numCols),passengers(passengers)
{
    seatMap.resize(numRows + 1, vector<Seat>(numCols));

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
    for (int row = 1; row <= numRows; ++row) {
        cout << "   +";
        for (int col = 0; col < numCols; ++col) {
            cout << "---+";
        }
        cout << endl;

        cout << setw(2) << row<< " |";
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
    cout << "\n" << endl;
}

void printSeparator(int totalWidth) {
    for (int i = 0; i < totalWidth; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void Flight::printPassengerInfo() const {
    std::cout << std::left << std::setw(20) << "First Name" << std::setw(20) << "Last Name" << std::setw(15) << "Phone"
              << std::setw(5) << "Row" << std::setw(10) << "Seat" << std::setw(10) << "ID" << std::endl;

    printSeparator(75);
    for (const Passenger &passenger : passengers) {
        std::cout << std::left << std::setw(20) << passenger.getFName() << std::setw(20) << passenger.getLName() << std::setw(15) << passenger.getPhoneNum()
                  << std::setw(5) << passenger.getSeat()->getRowNum() << std::setw(10) << passenger.getSeat()->getColNum() << std::setw(10) << passenger.getPassengerId() << std::endl;
        printSeparator(75);
    }

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

void Flight::setPassengers(const vector<Passenger> &passengers){
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

void Flight::addPassenger() {
    int id;
    string fName;
    string lName;
    string phoneNum;
    int rowNum;
    char colNum;

    cout << "Enter passenger ID: ";
    cin >> id;
    cout << "Enter passenger first name: ";
    cin >> fName;
    cout << "Enter passenger last name: ";
    cin >> lName;
    cout << "Enter passenger phone number: ";
    cin >> phoneNum;
    cout << "Enter passenger row number: ";
    cin >> rowNum;
    cout << "Enter passenger column number: ";
    cin >> colNum;

    Seat *seat = new Seat(true, rowNum, colNum);
    Passenger passenger(seat, fName, lName, id, phoneNum);
    vector<Passenger> tempPassengerList = passengers;
    tempPassengerList.push_back(passenger);
    setPassengers(tempPassengerList);
}

void Flight::removePassenger() {
    int id;
    cout << "Enter passenger ID: ";
    cin >> id;
    vector<Passenger> tempPassengerList = passengers;
    for(int i = 0; i < tempPassengerList.size(); i++){
        if(tempPassengerList[i].getPassengerId() == id){
            tempPassengerList.erase(tempPassengerList.begin() + i);
        }
    }
    setPassengers(tempPassengerList);
}



