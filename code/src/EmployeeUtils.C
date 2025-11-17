#include "EmployeeUtils.H"
#include <iostream>
#include <ctime>
#include <sstream>
#include  <iomanip>


int EmployeeUtils::mEmployeeIdCounter = 0;

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
            return "JusticeLeague";
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
    int sIdCount = GetEmpIdCounter();
    std::string sPrefix = "XYZ";
    std::string sNum = std::to_string(sIdCount);
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

int EmployeeUtils::GetEmpIdCounter()
{
    return ++mEmployeeIdCounter;
}

std::string EmployeeUtils::CalculateFutureDate(
    const std::string& InputDateParm,
    int MonthsParm,
    int YearsParm)
{
    // 1. Convert the input string (YYYY-MM-DD) into a std::tm struct
    std::tm DateTm = {};
    std::stringstream DateStringStream(InputDateParm);

    // Attempt to parse the date from the string stream
    // %Y: 4-digit year, %m: 2-digit month, %d: 2-digit day
    if (!(DateStringStream >> std::get_time(&DateTm, "%Y-%m-%d"))) {
        return 0;
    }

    // 2. Modify the month and year fields
    // tm_mon is 0-11, so 6 months is +6, 1 year is +12 months.
    DateTm.tm_mon += MonthsParm + (YearsParm * 12);

    // 3. Normalize the date using std::mktime
    // This critical step handles rollovers (e.g., month 15 becomes next year's March)
    std::mktime(&DateTm);

    // 4. Format the resulting std::tm struct back into a YYYY-MM-DD string
    std::stringstream sOutputStringStream;
    sOutputStringStream << std::put_time(&DateTm, "%Y-%m-%d");
    
    std::cout << "Divya CalculateFutureDate" << sOutputStringStream.str() << std::endl; 
    return sOutputStringStream.str();
}

std::string EmployeeUtils::GetTodaysDate()
{
    // 1. Get the current time point
    std::time_t sTime = std::time(nullptr); 

    // 2. Convert to local time structure
    // localtime returns a pointer to a static object, no need to delete it.
    std::tm* sNow = std::localtime(&sTime); 
    
    // 3. Use std::put_time to format the tm structure into a string
    std::ostringstream sOutStream;
    
    // The format string "%Y-%m-%d" means:
    // %Y: Year with century (e.g., 2025)
    // %m: Month as a decimal number (01-12)
    // %d: Day of the month (01-31)
    sOutStream << std::put_time(sNow, "%Y-%m-%d");

    // 4. Return the resulting string
    std::cout << "Divya GetTodaysDate" << sOutStream.str() << std::endl;
    return sOutStream.str();
}
