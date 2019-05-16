/**
 * User.h
 */


#ifndef _USER_H
#define _USER_H

#include "Checklist.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>

class shared_ptr;

class User {
public:
    std::string username;
    void registerme(){
        std::cout << "Enter your name: " << std::endl;
        getline(std::cin, username);
    }

    

private:
    std::vector< std::shared_ptr<Checklist> > checklist;

};

#endif //_USER_H