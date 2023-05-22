/**
 * @file calendar.h
 * @author Josh Gillum
 * @brief Definition of the calendar class
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "constants.h"

class Calendar{

public:
    Calendar(){
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            date today(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
            creationDate = today;
        }
        name = "";
    }
    Calendar(date creation, std::string calendarName){
        creationDate = creation;
        name = calendarName;
    }

    void display(){
        std::cout << "Calendar " << name << " was created on " << months[creationDate.month - 1] << " " << creationDate.day << " " << creationDate.year << std::endl;
    }


private:
    date creationDate;
    std::string name;

};
#endif