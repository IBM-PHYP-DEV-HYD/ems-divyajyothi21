#ifndef _EMPLOYEE_UTILS_H_ 
#define _EMPLOYEE_UTILS_H_
#include "EmployeeIF.H"
#include <cstdio>
#include <string>

int employeeIdCounter = 0;

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

class EmployeeUtils
{
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
};

std::string EmployeeUtils:: EmployeeTypeToString(EmployeeType TypeParm)
{
    switch (TypeParm)
    {
        case FULL_TIME:
            return "Full-Time";
        case CONTRACTOR:
            return "Contractor";
        case INTERN:
            return "Intern";
        default:
            std::cout << "Invalid TypeParm" <<std::endl;
            return "Unknown";
    }
}

std::string EmployeeUtils::EmployeeStatusToString(EmployeeStatus StatusParm)
{
    switch (StatusParm)
    {
        case ACTIVE:
            return "Active";
        case INACTIVE:
            return "Inactive";
        case RESIGNED:
            return "Resigned";
        default:
            std::cout << "Invalid Status Parm" <<std::endl;
            return "Unknown";
    }
}

std::string EmployeeUtils::GenderToString(Gender GenderParm)
{
    switch (GenderParm)
    {
        case MALE:
            return "Male";
        case FEMALE:
            return "Female";
        default:
            return "Unknown";
    }
}

std::string EmployeeUtils::CollegeToString(College CollegeParm)
{
    switch (CollegeParm)
    {
        case IIT_KANPUR:
            return "IIT Kanpur";
        case IIT_HYDERABAD:
            return "IIT Hyderabad";
        case NIT_WARANGAL:
            return "NIT Warangal";
        case NIT_TRUCHI:
            return "NIT Truchi";
        default:
            return "Unknown";
    }
}

std::string EmployeeUtils::BranchToString(Branch BranchParm)
{
    switch (BranchParm)
    {
        case CSE:
            return "CSE";
        case CSIT:
            return "CSIT";
        case ECE:
            return "ECE";
        default:
            return "Unknown";
    }
}

std::string EmployeeUtils::AgencyToString(Agency AgencyParm)
{
    switch (AgencyParm)
    {
        case AVENGERS:
            return "Avengers";
        case JUSTICE_LEAGUE:
            return "Justice League";
        case X_MEN:
            return "X-Men";
        default:
            return "Unknown";
    }
}

/**
 * @brief Generates a unique employee ID based on type.
 * Format: XYZXXXX[F/C/I] where XXXX is a 4-digit sequence number.
 */
std::string EmployeeUtils::generateEmployeeId(EmployeeType TypeParm)
{
    std::cout << "incrementing employeeIdCounter" << employeeIdCounter << std::endl;
    employeeIdCounter++;
    std::cout << "After incrementing employeeIdCounter" << employeeIdCounter << std::endl;
    std::string sPrefix = "XYZ";
    std::string sNum = std::to_string(employeeIdCounter);
    // Pad with leading zeros to make it 4 digits
    while (sNum.length() < 4)
    {
        sNum = "0" + sNum;
    }
    char sSuffix = '\0';
    switch (TypeParm)
    {
        case FULL_TIME:
            sSuffix = 'F';
            break;
        case CONTRACTOR:
            sSuffix = 'C';
            break;
        case INTERN:
            sSuffix = 'I';
            break;
        default:
            std::cout << "invalid Type" << std::endl;
    }
    return (sPrefix + sNum + sSuffix);
}

/**
 * @brief Generates a random integer between min (inclusive) and max (inclusive).
 */
int EmployeeUtils::getRandomInt(int MinParm, int MaxParm)
{
    return (MinParm + (std::rand() % (MaxParm - MinParm + 1)));
}

std::string EmployeeUtils::genDate(int StartYearParm, int EndYearParm)
{
    int sYear = EmployeeUtils::getRandomInt(StartYearParm, EndYearParm);
    int sMonth = EmployeeUtils::getRandomInt(1, 12);
    int sMonthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sMaxd = sMonthdays[sMonth - 1];
    // simple leap-year handling for February
    if (sMonth == 2 && ((sYear % 4 == 0 && sYear % 100 != 0) || (sYear % 400 == 0)))
    {
        sMaxd = 29;
    }
    int sDay = EmployeeUtils::getRandomInt(1, sMaxd);
    char sBuf[16];
    std::snprintf(sBuf, sizeof(sBuf), "%04d-%02d-%02d", sYear, sMonth, sDay);
    return std::string(sBuf);
}

#endif
