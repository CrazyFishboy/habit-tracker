/**
 * @file main.cpp
 * @author Josh Gillum
 * @brief Program that allows users to track their completion of 
 * certain tasks that they want to build habits for
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <ctime>
#include "constants.h"
#include "calendar.h"


int main(){
    std::cout << "Hello World" << std::endl;
    // current date/time based on current system
    time_t now = time(0);

    std::cout << "Number of sec since January 1,1970 is: " << now << std::endl;

    tm *ltm = localtime(&now);

    /*
    // print various components of tm structure.
    std::cout << "Year:" << 1900 + ltm->tm_year<<std::endl;

    std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;

    std::cout << "Day: "<< ltm->tm_mday << std::endl;

    std::cout << "Time: "<< ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;
    */

    date today(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    std::cout << "Today is " << months[today.month - 1] << " " << today.day << " " << today.year << std::endl;


    return 0;
}