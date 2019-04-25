#include "Student.h"

// Default Constructor
Student::Student()
{
}

// Destructor
Student::~Student()
{
}

// Mutatator setStudentInfo
void Student::setStudentInfo(int newID, const string& newFName,
                    const string& newLName)
{
    idNum = newID;
    fName = newFName;
    lName = newLName;
}

bool Student::operator>(const Student& otherStudent) const
{
    return idNum > otherStudent.idNum;
}

bool Student::operator<(const Student& otherStudent) const
{
    return idNum < otherStudent.idNum;
}

bool Student::operator==(const Student& otherStudent) const
{
    return idNum == otherStudent.idNum;
}

// Overloaded friend ostream operator
ostream& operator<<(ostream& os, const Student& student)
{
    os << "\n" << student.idNum << " - " << student.lName <<  ", " << student.fName;
    return os;
}

