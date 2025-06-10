#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName,
            std::string emailAddress, int age, int daysInCourse1,
            int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    ~Student();

    // Accessors
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram() const;

    // Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print();
};

#endif