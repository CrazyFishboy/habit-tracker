/**
 * @file day.h
 * @author Josh Gillum
 * @brief Definition of the day class
 * @version Development
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DAY_H
#define DAY_H

#include "constants.h"
#include "functions.h"
class Day{

public:
    Day(){
        mDate = getCurrentDate();
        pass = false;
        setStatus = false;
    }
    Day(date day){
        mDate = day;
        pass = false;
        setStatus = false;
    }
    Day(date day, bool passOrFail){
        mDate = day;
        pass = passOrFail;
        setStatus = true;
    }

    date getDate(){
        return mDate;
    }
    void setDate(date day){
        mDate = day;
    }
    bool getPass(){
        return pass;
    }
    void setPass(bool passOrFail){
        pass = passOrFail;
        setStatus = true;
    }
    bool getSetStatus(){
        return setStatus;
    }

private:
    date mDate; // The date in question
    bool pass; // Whether or not there was a pass or fail on this day
    bool setStatus; // The pass or fail status has been set

};
#endif