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

#include "constants.h"
#include "calendar.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <ctime>

int main(){
    
    date today = getCurrentDate();
    displayDate(today);
    displayDate(today,"%M %d %y. Today is a %D");

    std::cout << "-------------------------\n";

    date day(29,2,2000);
    displayDate(day);
    int days = numDaysIntoYear(day);
    std::cout << "Days into year: " << std::to_string(days) << std::endl;
    day = daysIntoYearToDate(days,2000);
    displayDate(day);

    Calendar language(today,"Spanish");
    language.displayInfo();


    return 0;
}