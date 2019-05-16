/**
 * Project Untitled
 */


#ifndef _MAIN WINDOW_H
#define _MAIN WINDOW_H

#include <QtWidgets/QPushButton>
#include "Observer.h"
#include "Board.h"
#include "Observer.h"
#include "User.h"


class MainWindow : public Observer, public Board {
public:
    MainWindow(const string &name, const string &description);

    void handleaddChecklist();
    
void handledeleteChecklist();
private: 
    QPushButton addChecklist;
    QPushButton deleteChecklist;
    User user;
};

#endif //_MAIN WINDOW_H