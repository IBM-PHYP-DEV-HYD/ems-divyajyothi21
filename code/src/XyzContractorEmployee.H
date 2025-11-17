#ifndef _TEMP_EMPLOYEE_H_
#define _TEMP_EMPLOYEE_H_
#include "XyzEmployee.H"
#include <string>
#include <iostream>
#include "XyzEmployeeSummaryBuilder.H"

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
    void PrintSummaryRow() const;  // Override virtual method for polymorphic printing
};

#endif
