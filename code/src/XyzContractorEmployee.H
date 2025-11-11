#ifndef _TEMP_EMPLOYEE_H_
#define _TEMP_EMPLOYEE_H_
#include "XyzEmployee.H"
#include <string>
#include <iostream>

class XyzContractorEmployee:public XyzEmployee
{
    private:
        Agency mAgency;
    public:
    XyzContractorEmployee();
    XyzContractorEmployee(std::string NameParm,
                          std::string IdParm,
                          EmployeeType EmpTypeParm,
                          std::string GenderParm,
                          std::string DojParm,
                          std::string DobParm,
                          EmployeeStatus EmployeeStatusParm,
                          std::string DolParm,
                          Agency AgencyParm);
    ~XyzContractorEmployee();    
    Agency GetAgencyName();
    void PrintEmployeeDetails() const;
};

XyzContractorEmployee::XyzContractorEmployee():XyzEmployee()
{
    std::cout << "Created XyzContractor Default Constructor" << std::endl;
}

XyzContractorEmployee::XyzContractorEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm,
             Agency AgencyParm):XyzEmployee(NameParm,
             IdParm,
             EmpTypeParm,
             GenderParm,
             DojParm,
             DobParm,
             EmployeeStatusParm,
             DolParm),mAgency(AgencyParm)
{
    std::cout << "Created XyzContractor Parameterized Constructor" << std::endl;
}

XyzContractorEmployee::~XyzContractorEmployee()
{
    std::cout << "Destructor of XyzContractorEmployee" << std::endl;
}

Agency XyzContractorEmployee::GetAgencyName()
{ 
    return this->mAgency;
}

void XyzContractorEmployee::PrintEmployeeDetails() const
{
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Employee Name  : " << this->mName << std::endl;
        std::cout << "Employee ID    : " << this->mEmployeeId << std::endl;
        std::cout << "Employee Type  : Contractor" << std::endl;
        std::cout << "Employee Status: " << EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus) << std::endl;
        std::cout << "Gender         : " << this->mGender << std::endl;
        std::cout << "Date of Birth  : " << this->mDateOfBirth << std::endl;
        std::cout << "Date of Joining: " << this->mDateOfJoining << std::endl;
        std::cout << "Date of Leaving: " << this->mDateOfLeaving << std::endl;
        std::cout << "Agency         : " << EmployeeUtils::AgencyToString(this->mAgency) << std::endl;
        std::cout << "-----------------------------------------" <<std::endl;
}
#endif
