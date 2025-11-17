#ifndef _EMPLOYEE_UTILS_H_ 
#define _EMPLOYEE_UTILS_H_
#include <cstdio>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

//int GetEmpIdCounter() = 0;

enum EmployeeType
{
    FULL_TIME,
    CONTRACTOR,
    INTERN,
    EMP_TYPE_COUNT
};

enum EmployeeStatus
{
    ACTIVE,
    INACTIVE,
    RESIGNED,
    EMP_STATUS_COUNT
};

// Genders
enum Gender
{   MALE,
    FEMALE,
    GENDER_COUNT
};

enum College
{
    IIT_KANPUR,
    IIT_HYDERABAD,
    NIT_WARANGAL,
    NIT_TRUCHI,
    COLLEGE_COUNT
};

enum Branch
{
    CSE,
    CSIT,
    ECE,
    BRANCH_COUNT
};

enum Agency
{
    AVENGERS,
    JUSTICE_LEAGUE,
    X_MEN,
    AGENCY_COUNT
};

// Define the static member variable
//int EmployeeUtils::mEmployeeIdCounter = 0;

class EmployeeUtils
{
private:
    static int mEmployeeIdCounter;
public:
    EmployeeUtils();
    ~EmployeeUtils();
    template<typename T>
    static T getRandomEnum(int Nparm)
    {
        return static_cast<T>(getRandomInt(0, Nparm - 1));
    }
    static std::string EmployeeTypeToString(EmployeeType TypeParm);
    static std::string EmployeeStatusToString(EmployeeStatus StatusParm);
    static std::string GenderToString(Gender GenderParm);
    static std::string CollegeToString(College CollegeParm);
    static std::string BranchToString(Branch BranchParm);
    static std::string AgencyToString(Agency AgencyParm);
    static std::string generateEmployeeId(EmployeeType TypeParm);
    static int getRandomInt(int MinParm, int MaxParm);
    static std::string genDate(int StartYearParm, int EndYearParm);
    static int GetEmpIdCounter();
    static std::string CalculateFutureDate(const std::string& InputDateParm,
                                           int MonthsParm,
                                           int YearsParm);
    static std::string GetTodaysDate();
};

#endif
