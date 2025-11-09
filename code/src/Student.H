#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

class Student {
    std::string mName;
    int mRollno;
public:
    Student();
    Student(std::string nameParm, int RollnoParm);
    Student(const Student &studentParm);
    ~Student();

    // Overload the << operator to allow easy printing
    friend std::ostream& operator<<(std::ostream& osParm, const Student& studentParm);
    friend std::istream& operator>>(std::istream& isParm, Student& studentParm);
};

Student::Student()
{
	mName = "";
	mRollno = 0;
}

Student::Student(std::string nameParm, int RollnoParm)
{
	mName = nameParm;
	mRollno = RollnoParm;
}

Student::Student(const Student &studentParm)
{
	mName = studentParm.mName;
	mRollno = studentParm.mRollno;
}

Student::~Student()
{
	//std::cout <<"Student is getting destructing here"<<std::endl;
}

std::ostream& operator<<(std::ostream& osParm, const Student& studentParm)
{
        osParm << "Name:" << studentParm.mName <<" "<< "Rollno:" << studentParm.mRollno;
        return osParm;
}

std::istream& operator>>(std::istream& isParm, Student& studentParm)
{
    std::cout << "Enter student name: ";
    // Use std::getline to read the entire line, including spaces
    // The std::ws manipulator skips any leading whitespace
    std::getline(isParm >> std::ws, studentParm.mName);
    std::cout << "Enter student roll number: ";
    isParm >> studentParm.mRollno;
    return isParm;
}
#endif
