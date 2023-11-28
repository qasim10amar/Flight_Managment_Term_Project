#include <iostream>
using namespace std;
#include "main.h"

int main() {

//    // Sample passenger data
//    std::vector<Passenger> passengers = {
//            Passenger(new Seat(true, 0, 'A'), "Tom", "Harris", 10000, "403-100-0000"),
//            Passenger(new Seat(true,1, 'A'), "Tim", "Brown", 10001, "403-100-0001"),
//            Passenger(new Seat(true,2, 'F'), "Jim", "Black", 10002, "403-100-0002"),
//            // Add more passengers as needed
//    };
    Airline myAirline = Airline("WestJet");
    populate_flight_list_from_file("passenger_info.txt", myAirline);
    myAirline.getFlightList()[0].printSeatMap();

    //myAirline.getFlightList()[1].printSeatMap();
//    // Creating a Flight object
//    Flight myFlight("WJ1145", 24, 6, passengers);
//
//    // Printing the seat map
//    myFlight.printSeatMap();
    return 0;
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
    std::string inputString = str;

    std::regex re("\\s{2,}"); // Matches two or more whitespace characters
    std::vector<std::string> tokens(std::sregex_token_iterator(inputString.begin(), inputString.end(), re, -1), {});

    return tokens;
}