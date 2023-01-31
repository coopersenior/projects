#ifndef PGM2_EMPLOYEE_H
#define PGM2_EMPLOYEE_H

#include<iostream>
#include<string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include "Person.h"

using namespace std;

class Employee: public Person{
private:
    string empType;
    string dept;
    int creditsAvail;

public:
    Employee() {}

    Employee(vector<string> words){
        lname = words[0];
        fname = words[1];
        id = words[2];
        empType = words[3];
        if (empType == "FT") { creditsAvail = 7; }
        else { creditsAvail = 3; }

        dept = words[4];
    }

    string getEmpType(){ return empType; }
    string getDept(){ return dept; }
    int getCreditsAvail() {return creditsAvail; }
};

#endif //PGM2_EMPLOYEE_H