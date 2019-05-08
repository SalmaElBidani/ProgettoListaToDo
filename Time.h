/**
 * Time
 */


#ifndef _Time_H
#define _Time_H

#include <string>

class Time {
public:

    explicit Time(short unsigned int h, short unsigned int m, short unsigned int s);
    virtual ~Time();

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    static Time fromString(std::string);
    std::string toString() const;

    bool operator < (const Time& right) const;
    bool operator == (const Time& right) const;


private:
    short unsigned int hours;
    short unsigned int minutes;
    short unsigned int seconds;
};

#endif //_T_H