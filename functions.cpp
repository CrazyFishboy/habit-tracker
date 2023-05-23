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
                } else if(format[i+1] == 'D'){
                    output += convertToTitle(getDayOfWeek(dateToDisplay));
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


// Uses Zeller's Algorithm
std::string getDayOfWeek(int day, int month, int year){
    const std::string weekday[7] = {"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
    int mon;
    if(month > 2)
        mon = month; //for march to december month code is same as month
    else{
        mon = (12+month); //for Jan and Feb, month code will be 13 and 14
        year--; //decrease year for month Jan and Feb
    }
    int y = year % 100; //last two digit
    int c = year / 100; //first two digit
    int w = (day + ((13*(mon+1))/5) + y + (y/4) + (c/4) + (5*c));
    w = w % 7;
    return weekday[w];
}

// Uses Zeller's Algorithm
std::string getDayOfWeek(date dateInQuestion){
    const std::string weekday[7] = {"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
    int mon;
    if(dateInQuestion.month > 2)
        mon = dateInQuestion.month; //for march to december month code is same as month
    else{
        mon = (12+dateInQuestion.month); //for Jan and Feb, month code will be 13 and 14
        dateInQuestion.year--; //decrease year for month Jan and Feb
    }
    int y = dateInQuestion.year % 100; //last two digit
    int c = dateInQuestion.year / 100; //first two digit
    int w = (dateInQuestion.day + ((13*(mon+1))/5) + y + (y/4) + (c/4) + (5*c));
    w = w % 7;
    return weekday[w];
}

int numDaysIntoYear(date startDate){
    int totalDays = startDate.day;
    for(int i = startDate.month - 1; i > 0; --i){
        totalDays += daysInMonth[i-1];
    }
    if(startDate.year % 4 == 0){
        if(startDate.year % 400 == 0 || startDate.year % 100 != 0){
            if(startDate.month > 2){
                totalDays++;
            }
        }
    }
    return totalDays;
}

date getDateXDaysFromDate(date startDate, int numDays){
    date endDate = startDate;
    return endDate;
}