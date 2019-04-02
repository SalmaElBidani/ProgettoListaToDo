/**
 * Project Untitled
 */


#ifndef _CHECKLIST_H
#define _CHECKLIST_H

#include "Task.h"
#include "Date.h"
#include <iostream>
#include <map>

class Checklist {
public: 
    
/**
 * @param Task task
 */
void addTask( Task task);
    
/**
 * @param Task task
 */
void deleteTask( Task task);
private: 
    std::string name;
    std::string description;
    std::map<Date,Task> Tasks;
};

#endif //_CHECKLIST_H