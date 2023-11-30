//
// Created by Qasim Amar on 2023-11-22.
//

#include "Seat.h"

Seat::Seat(bool seatStatus, int rowNum, char colNum) : seat_status(seatStatus), row_num(rowNum), col_num(colNum) {
}

Seat::Seat(bool seatStatus, string seatNum) : seat_status(seatStatus) {
    string numberPart = "";
    string charPart = "";

    for (char c : seatNum) {
        if (std::isdigit(c)) {
            numberPart += c;
        } else {
            charPart += c;
        }
    }

    row_num = stoi(numberPart);
    col_num = charPart[0];

}

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

int Seat::convert_col(){
    int char_num = int(col_num) - 65;
    return char_num;
}

Seat::Seat() {
    seat_status = false;
}

/*string Seat::concat_RC(int rowNumber, char colNumber){
    string row = to_string(rowNumber);
    string col(1, colNumber);
    string seatNum = row + col;
    return seatNum;
}
*/
