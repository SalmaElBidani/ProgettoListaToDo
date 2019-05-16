/**
 * Project Untitled
 */
#include <cstring>
#include <cstdio>
#include <string>

#ifndef _SOTTOTASK_H
#define _SOTTOTASK_H


class SottoTask {
public:


    SottoTask(std::string name);


std::string getTaskcompleted(std::string name);
private: 
    std::string name;
    std::string Taskcompleted;
};
#endif //_SOTTO TASK_H