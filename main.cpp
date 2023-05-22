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

    Calendar language(today,"Spanish");
    language.display();


    return 0;
}