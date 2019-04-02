/**
 * Project Untitled
 */


#ifndef _TIME_H
#define _TIME_H

class Time {
public: 
    
/**
 * @param int hours
 * @param int minutes
 * @param int seconds
 */
void Time(int hours, int minutes, int seconds);
    
Time $Now();
private: 
    int hours;
    int minutes;
    int seconds;
};

#endif //_TIME_H