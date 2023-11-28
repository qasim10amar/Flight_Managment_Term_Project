//
// Created by Qasim Amar on 2023-11-27.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "Flight.h"
#include "Seat.h"
#include "Passenger.h"
#include "Airline.h"


#ifndef AMAR_TERM_PROJECT_MAIN_H
#define AMAR_TERM_PROJECT_MAIN_H

int main();

void display_header();

void menu();

void populate_flight_list_from_file(string file_name, Airline &airline);
vector<string> tokenize(string str);

#endif //AMAR_TERM_PROJECT_MAIN_H
