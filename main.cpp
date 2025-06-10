#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
    cout << "Course Title: CS 216\n";
    cout << "Programming Language: C++\n";
    cout << "Student ID: 900666297\n";
    cout << "Name: Catherine Yousefi\n\n";

    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Catherine,Yousefi,yousefca6524@student.laccd.edu,25,30,30,30,SOFTWARE"
    };

    Roster classRoster;

    for (const auto& entry : studentData) {
        stringstream ss(entry);
        string id, first, last, email, ageStr, d1, d2, d3, progStr;

        getline(ss, id, ',');
        getline(ss, first, ',');
        getline(ss, last, ',');
        getline(ss, email, ',');
        getline(ss, ageStr, ',');
        getline(ss, d1, ',');
        getline(ss, d2, ',');
        getline(ss, d3, ',');
        getline(ss, progStr, ',');

        DegreeProgram dp = SOFTWARE;
        if (progStr == "SECURITY") dp = SECURITY;
        else if (progStr == "NETWORK") dp = NETWORK;

        classRoster.add(id, first, last, email, stoi(ageStr),
                        stoi(d1), stoi(d2), stoi(d3), dp);
    }

    classRoster.printAll();
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << "\n";

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + to_string(i + 1));
    }

    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "\n";
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
