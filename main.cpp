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
    std::cout << "Today is " << months[today.month - 1] << " " << today.day << " " << today.year << std::endl;


    Calendar language(today,"Spanish");
    language.display();


    return 0;
}