//
// Created by Qasim Amar on 2023-11-22.
//

#include "Seat.h"
#include "string"

using namespace std;
#ifndef AMAR_TERM_PROJECT_PASSENGER_H
#define AMAR_TERM_PROJECT_PASSENGER_H


class Passenger {
private:
    Seat * seat;
    string FName;
    string LName;
    int passenger_id;
    string phone_num;

public:
    Passenger(Seat *seat, const string &fName, const string &lName, int passengerId, const string &phoneNum);

    ~Passenger();

    Seat *getSeat() const;

    void setSeat(Seat *seat);

    const string &getFName() const;

    void setFName(const string &fName);

    const string &getLName() const;

    void setLName(const string &lName);

    int getPassengerId() const;

    void setPassengerId(int passengerId);

    const string &getPhoneNum() const;

    void setPhoneNum(const string &phoneNum);


};


#endif //AMAR_TERM_PROJECT_PASSENGER_H
