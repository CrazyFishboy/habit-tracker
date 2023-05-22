/**
 * @file functions.cpp
 * @author Josh Gillum
 * @brief Implementations of various functions
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "functions.h"


date getCurrentDate(){
    /*
    // print various components of tm structure.
    std::cout << "Year:" << 1900 + ltm->tm_year<<std::endl;

    std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;

    std::cout << "Day: "<< ltm->tm_mday << std::endl;

    std::cout << "Time: "<< ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;
    */

    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    // Creates date object
    date dateToday(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    return dateToday;
}