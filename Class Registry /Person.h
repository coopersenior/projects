#ifndef PGM2_PERSON_H
#define PGM2_PERSON_H

#include<string>
#include <vector>
#include<iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>

using namespace std;

class Person {
protected:
    string fname;
    string lname;
    string id;
public:
    //constructor
    Person(){
        fname = "";
        lname = "";
        id = "";
    }
    //getters
    string getfName(){ return fname; }
    string getlName(){ return lname; }
    string getId(){ return id; }

    // checks if the user entered name is a person's in the files
    bool isName(string fullName){
        if(fullName.compare(fname + " " + lname) == 0){ return true; }
        return false;
    }
};

#endif //PGM2_PERSON_H