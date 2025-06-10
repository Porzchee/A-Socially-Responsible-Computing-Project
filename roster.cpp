#include <iostream>
#include <regex>
#include "roster.h"

using namespace std;

Roster::Roster() {
    lastIndex = -1;
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
    }
}

void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress,
                                              age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            lastIndex--;
            cout << "Student with ID " << studentID << " removed.\n";
            break;
        }
    }
    if (!found) cout << "Student with ID " << studentID << " not found.\n";
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            double avg = (days[0] + days[1] + days[2]) / 3.0;
            cout << "Average days for student " << studentID << ": " << avg << endl;
            break;
        }
    }
}

void Roster::printInvalidEmails() {
    regex pattern(R"(([^@\s]+)@([^@\s]+)\.([^@\s]+))");
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if (!regex_match(email, pattern)) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
