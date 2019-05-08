/**
 * Project Untitled
 */


#ifndef _DATE_H
#define _DATE_H

#include "Time.h"
#include <stdio.h>
#include <ostream>


class Date {
public:
    explicit Date(int aDay, int aMonth, int aYear) throw (std::runtime_error);
    virtual ~Date();
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day) throw (std::runtime_error);
    void setMonth(int month) throw (std::runtime_error);
    void setYear(int year) throw (std::runtime_error);
    static Date today();
    static Date fromString(std::string str);
    std::string toString() const;
    bool operator < (const Date& right) const;
    bool operator == (const Date& right) const;


private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;
    int getMaxDays(int year);
    std::string getMonthString(short unsigned int month) const;
};


#endif //_DATE_H