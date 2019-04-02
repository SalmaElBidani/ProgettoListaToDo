/**
 * Project Untitled
 */


#ifndef _MAIN WINDOW_H
#define _MAIN WINDOW_H

#include "Observer.h"
#include "Board.h"
#include "Observer.h"


class Main Window: public Observer, public Board, public Observer {
public: 
    
void handleaddChecklist();
    
void handledeleteChecklist();
private: 
    QPushButton addChecklist;
    QPushButton deleteChecklist;
    User user;
};

#endif //_MAIN WINDOW_H