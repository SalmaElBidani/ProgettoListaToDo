/**
 * Project Untitled
 */


#ifndef _TASKVIEW_H
#define _TASKVIEW_H

#include "Observer.h"
#include "Task.h"
#include "Observer.h"


class TaskView: public Observer, public Task, public Observer {
public: 
    
void handleFavorites();
private: 
    QPushButton Favorites;
};

#endif //_TASKVIEW_H