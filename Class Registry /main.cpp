
#include"UnivClass.h"
#include"Student.h"
#include"Employee.h"

using namespace std;

vector<string> splitOneLine(string line) {  // splits one line of the file into a vector
    string temp;
    vector<string> words;
    istringstream iss{line};

    while(getline(iss, temp, ',')) {
        words.push_back(temp);
    }
    return words;  // returns the vector
}

void ReadUnivC(vector<UnivClass>& classes){ // reads in the classes file and adds to vector
    string line;
    ifstream ifs;
    ifs.open("/public/pgm2/classes.csv");
    // check if open
    if (!ifs) cout << "Couldn't open file." << endl;

    while (getline(ifs, line)) {
        UnivClass one_class(splitOneLine(line));
        classes.push_back(one_class);
    }
    ifs.close();
}

void ReadStudent(vector<Student>& stu){ // reads in the students file and adds to vector
    string line;
    ifstream ifs;
    ifs.open("/public/pgm2/students.csv");
    // check if open
    if (!ifs) cout << "Couldn't open file." << endl;

    while (getline(ifs, line)) {
        Student one_stu(splitOneLine(line));
        stu.push_back(one_stu);
    }
    ifs.close();
}

void ReadEmp(vector<Employee>& emps){ // reads in the employees file and adds to vector
    string line;
    ifstream ifs;
    ifs.open("/public/pgm2/employees.csv");
    // check if open
    if (!ifs) cout << "Couldn't open file." << endl;

    while (getline(ifs, line)) {
        Employee one_emp(splitOneLine(line));
        emps.push_back(one_emp);
    }
    ifs.close();
}

int FindPrintName(vector<Student> &vecStud, vector<Employee> &vecEmp, string name){
    int credits;
    for (unsigned int i = 0; i < vecStud.size(); i++) { // checks if name is a student
        if (vecStud[i].isName(name)) {
            // means its true
            credits = vecStud[i].getCreditsAvail();  // sets max credits allowed
            cout << "\nStudent name: " << name << " ID: " << vecStud[i].getId();
            cout << " Current credits: " << vecStud[i].getCurCredits() << endl;
        }
    }
    for (unsigned int i = 0; i < vecEmp.size(); i++) { // checks if name is an employee
        if (vecEmp[i].isName(name)) {
            // means its true
            credits = vecEmp[i].getCreditsAvail();   // sets max credits allowed
            cout << "\nEmployee name: " << name << " ID: " << vecEmp[i].getId();
            cout << " Type: " << vecEmp[i].getEmpType() << " Works in: " << vecEmp[i].getDept() << endl;
        }
    }
    // return their credits available to take to know what they can and can't register for
    return credits;
}

void PrintClassSchedule(vector<UnivClass> &uniCla, vector<string> &chosenClasses, int creditsLimit){
    cout << "Is registered for:" << endl;
    int count = creditsLimit;
    for (unsigned int i = 0; i < uniCla.size(); i++) {
        for(unsigned int j = 0; j < chosenClasses.size(); j++) {
            if (chosenClasses[j].compare(uniCla[i].getCNumber()) == 0) {
                if (count >= uniCla[i].getCredits()) {  // checks that user can register for class
                    string prof = uniCla[i].getProfessor();
                    prof.erase(remove(prof.begin(), prof.end(), '\"' ), prof.end());

                    cout << uniCla[i].getCNumber() << " " << uniCla[i].getTitle() << " Taught by ";
                    cout << prof << " At " << uniCla[i].getDateTime();
                    cout << " In " << uniCla[i].getLocation() << endl;
                    count -= uniCla[i].getCredits(); // keeps track of credits allowed to register for
                } else {
                    cout << "Could not register for " << uniCla[i].getCNumber() << endl;
                } // if the added amount of credits will put them over the limit they can't register
            }
        }
    }
}

int main(int argc, char** argv){
    vector<Employee> emps;  // initializes the vectors to store each files info
    ReadEmp(emps);          // reads each class into vector
    vector<UnivClass> classes;
    ReadUnivC(classes);
    vector<Student> stu;
    ReadStudent(stu);

    string fullName;  // stores entered full name
    string chosenClasses;
    vector<string> vecChoClasses;
    cout << "Enter first and last name: ";
    getline(cin, fullName);
    cout << "Enter classes to take - one line with spaces between:" << endl;
    getline(cin, chosenClasses); // gets line of classes separated by spaces

    string line;
    stringstream ss(chosenClasses);
    while (getline(ss, line, ' ')) {   // breaks apart classes by the space
        vecChoClasses.push_back(line);          // takes entered classes and puts them into a string vector
    }
    int credLim = FindPrintName(stu, emps, fullName); // Return credits available for person
    PrintClassSchedule(classes, vecChoClasses, credLim);
    // Print classes registered for and tells them if they can't due to credit restrictions

    return(0);
}