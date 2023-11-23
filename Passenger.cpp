//
// Created by Qasim Amar on 2023-11-22.
//

#include "Passenger.h"

Passenger::Passenger(Seat *seat, const string &fName, const string &lName, int passengerId, const string &phoneNum)
        : seat(seat), FName(fName), LName(lName), passenger_id(passengerId), phone_num(phoneNum) {}

Passenger::~Passenger() {

}

Seat *Passenger::getSeat() const {
    return seat;
}

void Passenger::setSeat(Seat *seat) {
    Passenger::seat = seat;
}

const string &Passenger::getFName() const {
    return FName;
}

void Passenger::setFName(const string &fName) {
    FName = fName;
}

const string &Passenger::getLName() const {
    return LName;
}

void Passenger::setLName(const string &lName) {
    LName = lName;
}

int Passenger::getPassengerId() const {
    return passenger_id;
}

void Passenger::setPassengerId(int passengerId) {
    passenger_id = passengerId;
}

const string &Passenger::getPhoneNum() const {
    return phone_num;
}

void Passenger::setPhoneNum(const string &phoneNum) {
    phone_num = phoneNum;
}
