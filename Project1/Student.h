/*
    Park, David
    CS A200
    October 19, 2015
 
    Exercise 13 B
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
    // Overloaded friend ostream operator
    friend ostream& operator<<(ostream& os, const Student& student);
    
public:
    
    // Default Constructor
    Student();
    
    // Destructor
    ~Student();
    
    // Mutatator setStudentInfo
    void setStudentInfo(int newID, const string& newFName,
                        const string& newLName);
    
    // Overloaded Inequality Operator
    bool operator>(const Student& otherStudent) const;
    bool operator<(const Student& otherStudent) const;
    
    // Overloaded Equality Operator
    bool operator==(const Student& otherStudent) const;
    
private:
    int idNum;
    string fName;
    string lName;
};

#endif