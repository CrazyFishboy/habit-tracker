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

void displayDate(date dateToDisplay){
    std::cout << "Today is " << convertToTitle(months[dateToDisplay.month -1]) << " " << dateToDisplay.day << " " << dateToDisplay.year << std::endl;
}

void displayDate(date dateToDisplay, std::string format){
    std::string output = "";
    for(long unsigned i = 0; i < format.length(); ++i){
        if(format[i] != '%'){
            output += format[i];
        } else {
            if(i + 1 < format.length()){
                if(format[i+1] == 'd'){
                    output += std::to_string(dateToDisplay.day);
                    ++i;
                } else if(format[i+1] == 'm'){
                    output += std::to_string(dateToDisplay.month);
                    ++i;
                } else if(format[i+1] == 'M'){
                    output += convertToTitle(months[dateToDisplay.month -1]);
                    ++i;
                } else if(format[i+1] == 'y'){
                    output += std::to_string(dateToDisplay.year);
                    ++i;
                }
            }
        }
    }
    std::cout << output << std::endl;
}


std::string convertToLowerCase(std::string input){
    std::string output = "";
    for(long unsigned i = 0; i < input.length(); ++i){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            output += (input[i] - 'A') + 'a';
        } else {
            output += input[i];
        }
    }
    return output;
}


std::string convertToUpperCase(std::string input){
    std::string output = "";
    for(long unsigned i = 0; i < input.length(); ++i){
        if(input[i] >= 'a' && input[i] <= 'z'){
            output += (input[i] - 'a') + 'A';
        } else {
            output += input[i];
        }
    }
    return output;
}


std::string convertToTitle(std::string input){
    std::string output = "";
    for(long unsigned i = 0; i < input.length(); ++i){
        if(i == 0 || input[i -1] == ' '){
            if(input[i] >= 'a' && input[i] <= 'z'){
                output += (input[i] - 'a') + 'A';
            } else {
                output += input[i];
            }
        } else {
            if(input[i] >= 'A' && input[i] <= 'Z'){
                output += (input[i] - 'A') + 'a';
            } else {
                output += input[i];
            }
        }
    }
    return output;
}