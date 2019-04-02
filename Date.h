/**
 * Project Untitled
 */


#ifndef _DATE_H
#define _DATE_H

#include "Time.h"

class Date {
public: 
    
/**
 * @param int Day
 * @param int month
 * @param int year
 */
void Date(int Day, int month, int year);
Date $today();
private: 
    int Day;
    int month;
    int year;
};

#endif //_DATE_H