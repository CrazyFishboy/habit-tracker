/**
 * @file constants.h
 * @author Josh Gillum
 * @brief Structure definitions as well as constant variables
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

struct date {
    date(){
        day = 0;
        month = 0;
        year = 0;
    }
    date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    int day;
    int month;
    int year;
};

const std::string months[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

#endif