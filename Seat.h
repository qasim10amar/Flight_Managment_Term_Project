//
// Created by Qasim Amar on 2023-11-22.
//
#include "string"
using namespace std;
#ifndef AMAR_TERM_PROJECT_SEAT_H
#define AMAR_TERM_PROJECT_SEAT_H


class Seat {
private:
    bool seat_status;
    int row_num;
    char col_num;



public:
    Seat(bool seatStatus, int rowNum, char colNum);
    Seat(bool seatStatus, string seatNum);

    bool isSeatStatus() const;

    void setSeatStatus(bool seatStatus);

    int getRowNum() const;

    void setRowNum(int rowNum);

    char getColNum() const;

    void setColNum(char colNum);

    ~Seat();

    int convert_col();

    //string concat_RC(int rowNumber, char colNumber);

    Seat();
};


#endif //AMAR_TERM_PROJECT_SEAT_H
