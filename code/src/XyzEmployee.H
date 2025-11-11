#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "EmployeeIF.H"

// Base Employee Class
class XyzEmployee:public EmployeeIF
{
protected:
    std::string mName;
    std::string mEmployeeId;
    EmployeeType mEmployeeType;
    std::string mGender;
    std::string mDateOfJoining;
    std::string mDateOfBirth;
    EmployeeStatus mEmployeeStatus;
    std::string mDateOfLeaving;//For Perminate NA, for Temp DOJ+1 year, for Contarctor DOJ+6months
public:
    XyzEmployee(); //default constructor
    XyzEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm); //Parameterized constructor
    virtual ~XyzEmployee(); //Destructor

    //Getters
    std::string GetEmployeeName() const;
    std::string GetEmployeeId() const;
    EmployeeType GetEmployeeType() const;
    EmployeeStatus GetEmployeeStatus() const;
    std::string GetEmployeeGender() const;
    std::string GetEmployeeDOB() const;
    std::string GetEmployeeDOJ() const;
    std::string GetEmployeeDOL() const;
    
    //Setters
    void setStatus(EmployeeStatus newStatusParm);
    void setDOL(const std::string& dateParm);

    // Overload the << operator to allow easy printing
    friend std::ostream& operator<<(std::ostream& osParm, const XyzEmployee& EmployeeParm);
    friend std::istream& operator>>(std::istream& isParm, XyzEmployee& EmployeeParm);
};

//default constructor
XyzEmployee::XyzEmployee():mName("Divya"),mEmployeeId("XYZ0001F"),mGender("Female"),mDateOfJoining("14May2014"),mDateOfBirth("04Sep1992"),
                     mEmployeeStatus(EmployeeStatus::ACTIVE),mDateOfLeaving("NA")
{
    std::cout << "Default Employee Constructor is called" << std::endl;
}

//Parameterized Constructor
XyzEmployee::XyzEmployee(std::string NameParm,
                   std::string IdParm,
                   EmployeeType EmpTypeParm,
                   std::string GenderParm,
                   std::string DojParm,
                   std::string DobParm,
                   EmployeeStatus EmployeeStatusParm,
                   std::string DolParm):mName(NameParm),
                                        mEmployeeId(IdParm),
                                        mEmployeeType(EmpTypeParm),
                                        mGender(GenderParm),
                                        mDateOfJoining(DojParm),
                                        mDateOfBirth(DobParm),
                                        mEmployeeStatus(EmployeeStatusParm),
                                        mDateOfLeaving("NA")
{
    //mEmployeeId = EmployeeUtils::generateEmployeeId(EmpTypeParm);
    if (EmployeeStatusParm == RESIGNED)
    {
        this->mDateOfLeaving = "2025-12-1";
    } 
    std::cout << "Parameterized Constructor got created" << std::endl;
}

XyzEmployee::~XyzEmployee()
{
    std::cout << "Employee Destructor got called" <<std::endl;
}

std::string XyzEmployee::GetEmployeeName() const
{
    return this->mName;
}

std::string XyzEmployee::GetEmployeeId() const
{
    return this->mEmployeeId;
}

EmployeeType XyzEmployee::GetEmployeeType() const
{
    return this->mEmployeeType;    
}

EmployeeStatus XyzEmployee::GetEmployeeStatus() const
{
    return mEmployeeStatus;
}

std::string XyzEmployee::GetEmployeeGender() const
{
    return this->mGender;
}

std::string XyzEmployee::GetEmployeeDOB() const
{
    return this->mDateOfBirth;
}
std::string XyzEmployee::GetEmployeeDOJ() const
{
    return this->mDateOfJoining;
}

std::string XyzEmployee::GetEmployeeDOL() const
{
    return this->mDateOfLeaving;
}

void XyzEmployee::setStatus(EmployeeStatus newStatusParm)
{
    this->mEmployeeStatus = newStatusParm;
}

void XyzEmployee::setDOL(const std::string& dateParm)
{
    this->mDateOfLeaving = dateParm;
}

std::ostream& operator<<(std::ostream& osParm, const XyzEmployee& EmployeeParm)
{
        osParm << "Name:" << EmployeeParm.mName <<" "<< "EmpId:" <<EmployeeParm.mEmployeeId;
        return osParm;
}

std::istream& operator>>(std::istream& isParm, XyzEmployee& EmployeeParm)
{
    std::cout << "Enter Employee name: ";
    // Use std::getline to read the entire line, including spaces
    // The std::ws manipulator skips any leading whitespace
    std::getline(isParm >> std::ws, EmployeeParm.mName);
    std::cout << "Enter Employee ID: ";
    isParm >> EmployeeParm.mEmployeeId;
    return isParm;
}
#endif
