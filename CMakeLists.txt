cmake_minimum_required(VERSION 3.26)
project(Amar_Term_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Amar_Term_Project main.cpp
        Airline.cpp
        Airline.h
        Flight.cpp
        Flight.h
        Passenger.cpp
        Passenger.h
        Seat.cpp
        Seat.h)
