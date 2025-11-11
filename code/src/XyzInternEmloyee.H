#ifndef _INTERN_EMPLOYEE_H_
#define _INTERN_EMPLOYEE_H_
#include "XyzEmployee.H"
#include <string>
#include <iostream>

class XyzInternEmployee:public XyzEmployee
{
    private:
        College mCollege;
        Branch mBranch;
    public:
        XyzInternEmployee();
        XyzInternEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParam,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm,
             College CollegeParm,
             Branch BranchParm);
        ~XyzInternEmployee();
        College GetCollegeName();
        Branch GetBranch();
        void PrintEmployeeDetails() const;
};

XyzInternEmployee::XyzInternEmployee():XyzEmployee()
{
    std::cout << "Creating a XyzInternEmployee Default Constructor" << std::endl;
}

XyzInternEmployee::XyzInternEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm,
             College CollegeParm,
             Branch BranchParm):XyzEmployee(NameParm,
                       IdParm,
                       EmpTypeParm,
                       GenderParm,
                       DojParm,
                       DobParm,
             EmployeeStatusParm,
             DolParm),mCollege(CollegeParm),mBranch(BranchParm)
{
    std::cout << "Creating a XyzInternEmployee Parameterized Constructor" << std::endl;
}

XyzInternEmployee::~XyzInternEmployee()
{
    std::cout << "Destrcuting the XyzInternEmployee" << std::endl;
}

College XyzInternEmployee::GetCollegeName()
{
    return this->mCollege;
}

Branch XyzInternEmployee::GetBranch()
{
    return this->mBranch;
}

void XyzInternEmployee::PrintEmployeeDetails() const
{
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Employee Name  : " << this->mName << std::endl;
        std::cout << "Employee ID    : " << this->mEmployeeId << std::endl;
        std::cout << "Employee Type  : Intern" << std::endl;
        std::cout << "Employee Status: " << EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus) << std::endl;
        std::cout << "Gender         : " << this->mGender << std::endl;
        std::cout << "Date of Birth  : " << this->mDateOfBirth << std::endl;
        std::cout << "Date of Joining: " << this->mDateOfJoining << std::endl;
        std::cout << "Date of Leaving: " << this->mDateOfLeaving << std::endl;
        std::cout << "College        : " << EmployeeUtils::CollegeToString(this->mCollege) << std::endl;
        std::cout << "Branch         : "  << EmployeeUtils::BranchToString(this->mBranch) << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    
}
#endif
