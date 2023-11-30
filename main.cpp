#include <iostream>
using namespace std;
#include "main.h"

int main() {

    display_header();
    Airline myAirline = Airline("WestJet");
    populate_flight_list_from_file("passenger_info.txt", myAirline);

    while(true){
        menu();
        int choice;
        cin >> choice;
        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(choice == 1){
            cout << "\t  Aircraft Seat Map" << endl;
            myAirline.getFlightList()[0].printSeatMap();
        }
        else if(choice == 2){
            cout << "Display Passenger Information" << endl;
            myAirline.getFlightList()[0].printPassengerInfo();
        }
        else if(choice == 3){
            cout << "Add a New Passenger" << endl;
            myAirline.getFlightList()[0].addPassenger();
        }
        else if(choice == 4){
            cout << "Remove an Existing Passenger" << endl;
            myAirline.getFlightList()[0].removePassenger();
        }
        else if(choice == 5){
            cout << "Save data" << endl;
            saveData(myAirline);
        }
        else if(choice == 6){
            cout << "Quit" << endl;
            cout << "\nProgram Terminated" << endl;
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}

void display_header() {
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced by: Qasim Amar" << endl;
    cout << "Year: 2023\n" << endl;
    cout << "<<< Press Return to Continue >>>>";
    cin.get();
}

void menu() {

    cout << "<<< Press Return to Continue >>>>" << endl;
    cin.get();
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passenger Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove an Existing Passenger" << endl;
    cout << "5. Save data" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
}

void populate_flight_list_from_file(string filename, Airline &airline) {
    ifstream inputFile("/Users/qasimamar/CLionProjects/Amar_Term_Project/passenger_info.txt"); // Replace 'input.txt' with your file name


    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<string> flightData; // Vector to store non-empty lines
    vector<vector<string>> flights; // Vector of vectors to store lines between empty lines
    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            // Empty line encountered, switch to a new vector for the next set of lines
            if (!flightData.empty()) {
                flights.push_back(flightData);
                flightData.clear(); // Clear flightData for the next set of lines
            }
        } else {
            flightData.push_back(line); // Add non-empty lines to flightData
        }
    }

    // Add the last set of non-empty lines (if any) to flights
    if (!flightData.empty()) {
        flights.push_back(flightData);
    }
    airline.setNumFlight(flights.size());
    vector<Flight> flightList;
    // Display the contents of each flight
    for (const auto& flight : flights) {
        Flight *newFlight;
        for (const auto& data : flight) {
            vector<string> passengerData = tokenize(data);
//            for(int i = 0; i < passengerData.size(); i++){
//                cout << passengerData[i] << endl;
//            }

            if(passengerData.size() == 3){
                newFlight = new Flight(passengerData[0], stoi(passengerData[1]), stoi(passengerData[2]), vector<Passenger>());

            }
            else{
                Passenger myPassenger(new Seat(true, passengerData[3]), passengerData[0], passengerData[1], stoi(passengerData[4]), passengerData[2]);
                vector<Passenger> tempPassengerList = newFlight->getPassengers();
                tempPassengerList.push_back(myPassenger);
                newFlight->setPassengers(tempPassengerList);
            }

        }
        flightList.push_back(*newFlight);

    }
    airline.setFlightList(flightList);

    inputFile.close();


}

//tokenize function
vector<string> tokenize(string str) {
    string inputString = str;

    regex re("\\s{2,}"); // Matches two or more whitespace characters
    vector<string> tokens(sregex_token_iterator(inputString.begin(), inputString.end(), re, -1), {});
    if(tokens.size() == 4){
        string temp = tokens[3];
        regex re("\\s{1,}"); // Matches two or more whitespace characters
        vector<string> tempTokens(sregex_token_iterator(temp.begin(), temp.end(), re, -1), {});
        tokens.push_back(tempTokens[0]);
        tokens.push_back(tempTokens[1]);
        //Delete tokens[2]
        tokens.erase(tokens.begin() + 3);
    }

    return tokens;
}

void saveData(Airline &airline) {
    ofstream outputFile("/Users/qasimamar/CLionProjects/Amar_Term_Project/passenger_info1.txt");

    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Iterate through each flight in the airline
    for (const Flight& flight : airline.getFlightList()) {
        outputFile << setw(6) << left << flight.getFlightId() << setw(5) << right << flight.getNumRows() << setw(5) << right << flight.getNumCols() << endl;

        // Iterate through each passenger in the flight
        for (const Passenger& passenger : flight.getPassengers()) {
            // Assuming you have appropriate getter methods for passenger details like fName, lName, phoneNum, etc.
            outputFile << setw(20) << left << passenger.getFName() << setw(20) << left << passenger.getLName() << setw(20) << left
                       << passenger.getPhoneNum() << setw(2) << left << passenger.getSeat()->getRowNum()
                       << setw(5) << left << passenger.getSeat()->getColNum() << setw(10) << right << passenger.getPassengerId() << endl;
        }
    }

    outputFile.close();
}