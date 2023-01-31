
#ifndef PGM2_UNIVCLASS_H
#define PGM2_UNIVCLASS_H
#include<string>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class UnivClass{
protected:
    string cNumber;
    string title;
    int totalSeats;
    int seatsLeft;
    string professor;
    string dateTime;
    string location;
    int credits;
public:
    UnivClass() {}

    UnivClass(vector<string> words) {   // constructor sets all attributes
        cNumber = words[0];
        title = words[1];
        totalSeats = stoi(words[3]);
        seatsLeft = stoi(words[4]);
        professor = words[6];
        dateTime = words[7];
        location = words[8];
        credits = stoi(words[9]);
    }

    string getCNumber(){ return cNumber; }
    string getTitle(){ return title; }
    int getTotalSeats(){ return totalSeats; }
    int getSeatsLeft(){ return seatsLeft; }
    string getProfessor(){ return professor; }
    string getDateTime(){ return dateTime; }
    string getLocation(){ return location; }
    int getCredits(){ return credits; }
};

#endif //PGM2_UNIVCLASS_H
