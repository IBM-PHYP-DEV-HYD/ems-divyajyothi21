#ifndef _INTERN_EMPLOYEE_H_
#define _INTERN_EMPLOYEE_H_
#include "XyzEmployee.H"
#include <string>
#include <iostream>
#include "XyzEmployeeSummaryBuilder.H"

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
        void PrintSummaryRow() const;  // Override virtual method for polymorphic printing
};
#endif
