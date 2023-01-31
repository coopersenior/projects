#ifndef PGM2_STUDENT_H
#define PGM2_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

using namespace std;

class Student : public Person{
private:
    int curCredits;
    int creditsAvail = 21;
public:
    Student() {}

    Student(vector<string> words) {
        lname = words[0];
        fname = words[1];
        id = words[2];
        curCredits = stoi(words[3]);
    }

    int getCurCredits(){ return curCredits; }
    int getCreditsAvail() { return creditsAvail; }
};

#endif //PGM2_STUDENT_H