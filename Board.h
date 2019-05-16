/**
 * Project Untitled
 */


#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <list>
#include "Subject.h"
#include "Subject.h"
#include "Subject.h"
#include "Checklist.h"




using namespace std;
class Board: public Subject {
public: 
    


    void addChecklist(Checklist checklist);

    Board(const string &name, const string &description);

    void deleteChecklist(Checklist checklist);



list <Checklist> getChecklist();
private:
    string name;
    string description;
};



#endif //_BOARD_H