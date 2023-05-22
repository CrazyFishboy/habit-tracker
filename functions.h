/**
 * @file functions.h
 * @author Josh Gillum
 * @brief Definitions of various functions
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <string>
#include <iostream>
#include "constants.h"


date getCurrentDate();
void displayDate(date dateToDisplay);
void displayDate(date dateToDisplay, std::string format);

#endif