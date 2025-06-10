# A-Socially-Responsible-Computing-Project

This project implements a simple student roster management system in C++. It demonstrates key object-oriented programming concepts such as classes, dynamic memory allocation, constructors and destructors, and enumerations.

The project consists of two main classes:

- **Student**: Represents a student with attributes such as student ID, name, email, age, days to complete courses, and degree program.
- **Roster**: Manages a collection (array) of `Student` objects, providing functionalities to add, remove, and print student information.

The program reads student data from a predefined array, parses it, and populates the roster. It also includes features to:

- Print all students’ details
- Print invalid email addresses
- Print average days spent in courses for each student
- Print students filtered by their degree program
- Remove a student by student ID

## How to Run

1. **Prerequisites:**  
   You need a C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).

2. **Files:**  
   - `student.h` and `student.cpp`: Defines and implements the `Student` class.  
   - `roster.h` and `roster.cpp`: Defines and implements the `Roster` class.  
   - `main.cpp`: Contains the `main()` function that runs the program.  
   - `Degree.h` : Defines the `DegreeProgram` enum and any related constants.
