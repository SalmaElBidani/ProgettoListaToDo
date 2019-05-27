/**
 * Project Untitled
 */


#ifndef _TASK_H
#define _TASK_H

#include "Subject.h"
#include "Subject.h"
#include "Date.h"
#include "Time.h"
#include <iostream>


class Task: public Subject {
public:

    

 Task(Date date, std::string text);
private: 
    Date startDate;
    Date endDate;
    Time startTime;
    Time endTime;
    std::string notes;
    std::string name;
};

#endif //_TASK_H