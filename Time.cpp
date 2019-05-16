/**
 * Time.cpp
 */


#include "Time.h"
#include <ctime>
#include <stdexcept>


// controls the correctness of time

Time::Time(short unsigned int h, short unsigned int m, short unsigned int s) {
    if (h < 0 || h > 24) {
        throw std::runtime_error ("Error in hours number");
    }

    if (m < 0 || m > 60){
        throw std::runtime_error ("Error in minutes number");
    }

    if (s < 0 || s > 60){
        throw std::runtime_error ("Error in seconds number");
    }

    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}


Time Time::fromString(std::string str){
    std::tm t;
    strptime (str.c_str(), "%H: %M: %S", &t);
    return Time(t.tm_hour, t.tm_min, t.tm_sec);
}

std::string Time::toString() const{
    return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}

bool Time::operator < (const Time& right) const{
    if (this->hours > right.hours)
        return false;
    else if (this->hours == right.hours){
        if (this->minutes > right.minutes)
            return false;
        else if (this->minutes == right.minutes){
            if (this->seconds >= right.seconds)
                return false;
        }
    }
    return true;
}
bool Time::operator == (const Time& right) const{
    return this->hours == right.hours && this->minutes == right.minutes && this->seconds == right.seconds;

}

 //get hours, minutes and seconds
 int Time::getHours() const{
     return hours;
 }
 int Time::getMinutes() const{
     return minutes;
 }

 int Time::getSeconds() const{
     return seconds;
 }


Time::~Time() {}
