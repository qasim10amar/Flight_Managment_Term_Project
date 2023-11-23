#include <iostream>
using namespace std;
#include "Flight.h"

int main() {
    int rows = 25; // Update with your desired number of rows
    int cols = 9;  // Update with your desired number of columns

    Flight flight("FL001", rows, cols);

    // Occupy some seats for demonstration
    flight.occupySeat(5, 2);
    flight.occupySeat(6, 1);
    flight.occupySeat(23, 2);

    // Display the seat map
    flight.displaySeatMap();

    return 0;
}