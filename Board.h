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
    
/**
 * @param string name
 * @param string description
 */
void Checklist(string name, string description);
    
/**
 * @param Checklist checklist
 */
void addChecklist(Checklist checklist);
    
/**
 * @param Checklist checklist
 */
void deleteChecklis(Checklist checklist);

list <Checklist> getChecklist();
private:
    string name;
    string description;
};

#endif //_BOARD_H