//
// Created by Qasim Amar on 2023-11-22.
//

#include "Seat.h"


Seat::Seat(bool seatStatus, int rowNum, char colNum) : seat_status(seatStatus), row_num(rowNum), col_num(colNum) {}

Seat::~Seat() {

}

bool Seat::isSeatStatus() const {
    return seat_status;
}

void Seat::setSeatStatus(bool seatStatus) {
    seat_status = seatStatus;
}

int Seat::getRowNum() const {
    return row_num;
}

void Seat::setRowNum(int rowNum) {
    row_num = rowNum;
}

char Seat::getColNum() const {
    return col_num;
}

void Seat::setColNum(char colNum) {
    col_num = colNum;


}


